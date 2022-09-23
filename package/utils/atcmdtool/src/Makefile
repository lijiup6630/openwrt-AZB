CC = gcc
CFLAGS = -Wall
OBJS = atcmdtool.o

all: atcmdtool

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

atcmdtool: $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f atcmdtool *.o
