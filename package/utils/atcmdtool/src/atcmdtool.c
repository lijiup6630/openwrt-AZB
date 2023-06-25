//=====================================================================
// COPYSTR: Copyright (c) 2020 By HuachenLink, All Rights Reserved.
// FLENAME: atcmdtool.c
// CONTACT: liudongguo@huachen.link
// CREATED: 2020-09-12 21:52:00
// LTSVERN: 0.1.1
// LTSUPDT: 2020-12-03 09:41:33
//=====================================================================
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

+#define ATE_REPORT

#ifndef DEV_MAXSIZE
#define DEV_MAXSIZE 0x10
#endif

#ifndef INSTRUCTION_MAXSIZE
#define INSTRUCTION_MAXSIZE 0x100
#endif

#ifndef LINE_MAXSIZE
#define LINE_MAXSIZE 0x4000
#endif

#ifndef RESP_MAXSIZE
#define RESP_MAXSIZE 0x1000
#endif

#ifdef ENABLE_LOCKFILE
static int fdLock = -1;
#ifndef LOCK_FILE
#define LOCK_FILE "/run/hat.lock"
#endif
#endif

// import from sys/file.h
#ifndef LOCK_EX
#define LOCK_EX 2 /* Exclusive lock.  */
#endif
#ifndef LOCK_UN
#define LOCK_UN 8 /* Unlock.  */
#endif

static void doDeviceLock(unsigned int action);
static void recvResp(int fd);
static void sendReq(int fd, const char *s);
static void serialOpen(int *fd, char *ins, int argc, char *argv[]);
static void serialClose(int fd);
//--------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  int fd = -1;
  char atins[INSTRUCTION_MAXSIZE] = {0};

  // STEP1 open
  serialOpen(&fd, &atins[0], argc, argv);
  doDeviceLock(LOCK_EX);
  // STEP2 send AT-instruction
  sendReq(fd, atins);

  // STEP3 recv resp
  recvResp(fd);

  doDeviceLock(LOCK_UN);
  // STEP4: clean resources and exit ok
  serialClose(fd);

  return (EXIT_SUCCESS);
}

//--------------------------------------------------------------------------
static void serialOpen(int *ifd, char *ins, int argc, char *argv[]) {
  char port[DEV_MAXSIZE];
  int baud = 115200, tmout = 10;

  snprintf(port, DEV_MAXSIZE - 1, "/dev/ttyUSB1");
  if (argc == 1 || (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
    fprintf(stderr,
            "Usage:  %s [-b RATE{=%d}] [-t TMOUT{=%d}s] [[-d] "
            "DEVPATH{=%s}] <[AT]+INSTRUCTION>\n",
            argv[0], baud, tmout, port);
    exit(EXIT_SUCCESS);
  }
  char *k = NULL;
  char *v = NULL;
  // parse args
  for (int i = 1; i < argc;) {
    k = argv[i], v = argv[i + 1];
    if (v && (!strcmp(k, "-b") || !strcmp(k, "--baudrate"))) {
      baud = atoi(v);
    } else if (v && (!strcmp(k, "-t") || !strcmp(k, "--timeout"))) {
      tmout = atoi(v);
    } else if (v && (!strcmp(k, "-d") || !strcmp(k, "--device"))) {
      switch (v[0]) {
      case '/':
        snprintf(port, DEV_MAXSIZE - 1, "%s", v);
        break;
      case '0' ... '9':
        snprintf(port, DEV_MAXSIZE - 1, "/dev/ttyUSB%c", v[0]);
        break;
      default:
        snprintf(port, DEV_MAXSIZE - 1, "%s", "/dev/ttyUSB1");
        break;
      }
    } else if (!strncmp(k, "/dev/", 5)) {
      snprintf(port, DEV_MAXSIZE - 1, "%s", k);
      i++;
      continue;
    } else if (k[0] == '+') {
      snprintf(ins, INSTRUCTION_MAXSIZE - 1, "at%s\r", k);
      fprintf(stderr, "[cmd] %s \n", ins);
      break;
    } else if (!strncmp(k, "at", 2) || !strncmp(k, "AT", 2)) {
      snprintf(ins, INSTRUCTION_MAXSIZE - 1, "%s\r", k);
      fprintf(stderr, "[cmd] %s \n", ins);
      break;
    } else if (!strcmp(k, "-v") || !strcmp(k, "--version")) {
      fprintf(stderr, "Built %s at [%s, %s]\n", argv[0], __DATE__, __TIME__);
      exit(EXIT_SUCCESS);
    } else {
      fprintf(stderr, "[FATAL] Got a not supported argument < %s >\n", k);
      exit(EXIT_FAILURE);
    }
    i += 2;
  }

  // open fd for port
  int fd = open(port, O_RDWR);
  if (fd < 0) {
    fprintf(stderr, "[FATAL] Can not open port '%s'\n", port);
    exit(EXIT_FAILURE);
  }

  struct termios options;
  tcgetattr(fd, &options);
  tcflush(fd, TCIOFLUSH);

  options.c_lflag = 0;
  options.c_oflag = 0;
  options.c_iflag = 0;

  // Set Baudrate
  switch (baud) {
  case 9600:
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    break;
  case 19200:
    cfsetispeed(&options, B19200);
    cfsetospeed(&options, B19200);
    break;
  default:
#ifdef ATE_REPORT
    fprintf(stderr, "[REPORT] Will use default baudrate: 115200\n");
#endif
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);
  }

  // Input Modes
  options.c_iflag |= IGNCR; // Ignore CR
#ifdef XONXOFF
  options.c_iflag |= IXON; // XON-XOFF Flow Control
#endif

  // Output Modes
  options.c_oflag |= OPOST; // Post-process output

  // Control Modes
  options.c_cflag |= CS8;    // 8 data bits
  options.c_cflag |= CREAD;  // Enable Receiver
  options.c_cflag |= CLOCAL; // Ignore modem status lines

  // Local Modes
  options.c_lflag |= IEXTEN; // Extended input character processing

  // Special characters
  tmout *= 10;
  /* 函数read
   * VMIN=0,VTIME=0,未读到任何参数也立即返回，相当于非阻塞模式；
   * VMIN=0,VTIME>0,读取到数据立即返回，若无数据则等待VTIME时间返回；
   * VMIN>0,VTIME=0,只有在读取到VMIN个字节的数据或者收到一个信号的时候才返回；
   * VMIN>0,VTIME>0,从读取第一个字节的数据时开始计时，并会在读取到VMIN个字节或者VTIME时间后返回
   */
  options.c_cc[VTIME] = tmout; // Always return...
  options.c_cc[VMIN] = 0;      // Immediately from read()

#ifdef XONXOFF
  options.c_cc[VSTOP] = XOFF;
  options.c_cc[VSTART] = XON;
#endif

  if (tcsetattr(fd, TCSANOW, &options) < 0) {
    fprintf(stderr, "[FATAL] Failed to config '%s'\n", port);
    exit(EXIT_FAILURE);
  }
  tcflush(fd, TCIOFLUSH);
  *ifd = fd;
}

//--------------------------------------------------------------------------
static void serialClose(int fd) {
  tcflush(fd, TCIOFLUSH);
  close(fd);
}

//--------------------------------------------------------------------------
static void sendReq(int fd, const char *ins) {
#ifdef ATE_REPORT
  fprintf(stderr, "[REPORT] Will send AT-INSTRUCTION: %s\n", ins);
#endif
  size_t pc = 0, insLen = strlen(ins);
  ssize_t sntCnt;
  while (pc < insLen) {
    do {
      sntCnt = write(fd, ins + pc, insLen - pc);
    } while (sntCnt < 0 && errno == EINTR);
    if (sntCnt < 0) {
      exit(EXIT_FAILURE);
    }
    pc += sntCnt;
  }
}

//--------------------------------------------------------------------------
static void recvResp(int fd) {
  int curRead = 0, totalRead = 0;
  char buf[LINE_MAXSIZE] = {0};
  while (1) {
    do {
      curRead = read(fd, buf, LINE_MAXSIZE - 1);
    } while (curRead <= 0 && errno == EINTR);
    if (curRead < 0) {
      exit(EXIT_FAILURE);
    }
    fprintf(stdout, "%s", buf);
    totalRead += curRead;
    if (strstr(buf, "OK") || strstr(buf, "ERROR") || !totalRead ||
        totalRead > RESP_MAXSIZE) {
#ifdef ATE_REPORT
      fprintf(stderr, "[REPORT] Total READ: %d bytes\n", totalRead);
#endif
      break;
    }
    memset(buf, 0, LINE_MAXSIZE);
  }
}

//--------------------------------------------------------------------------
static void doDeviceLock(unsigned int action) {
#ifdef ENABLE_LOCKFILE
  if (fdLock == -1) {
    fdLock = open(LOCK_FILE, O_CREAT);
    if (fdLock < 0) {
      fprintf(stderr, "[FATAL] failed to create lockfile '%s' !!!\n",
              LOCK_FILE);
      exit(EXIT_FAILURE);
    }
  }
  if (0 != flock(fdLock, action)) {
    fprintf(stderr, "[FATAL] failed to %s lock !!!\n",
            (action == LOCK_UN ? "remove" : "apply"));
    exit(EXIT_FAILURE);
  }
#endif
}
