/******************************************************************************

         Copyright (c) 2020, MaxLinear, Inc.
         Copyright 2016 - 2020 Intel Corporation
         Copyright 2015 - 2016 Lantiq Beteiligungs-GmbH & Co. KG
         Copyright 2009 - 2014 Lantiq Deutschland GmbH
         Copyright 2007 - 2008 Infineon Technologies AG

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

/*
 *  Unit test implementation for file-system access
 *
 * FIXME:
 *   The driver helper should not know about EEPROM format.
 *   To remove code after CRC generation on EEPROM data originator.
 */

#if defined(EEPROM_CRC_ON_DRVHLPR) & defined(RUN_EEPROM_CRC_UTEST)

#include "mtlkinc.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "dataex.h"
#include "mtlkirba.h"

#include "fshlpr_utest.h"

#define LOG_LOCAL_GID   GID_IRB
#define LOG_LOCAL_FID   4

/** IRB event for data storing on file-system */
static const mtlk_guid_t IRBE_FILE_SAVE = MTLK_IRB_GUID_FILE_SAVE;

static uint8 tmb_buffer[0xFFF];
static uint32 tmb_buffer_used = 0;

static uint32 utest_steps = 0;

#define EEPROM_HEAD(a, b) \
/* 0000 */  (a), (b),   0x02, 0x03, 0x04, 0x05, 0x06, 0x07,   0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, \
/* 0010 */  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,   0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, \
/* 0020 */  0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,   0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, \
/* 0030 */  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,   0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f

/* -== TEST-0: EEPROM_SIZE_WRONG ==- */
static uint8 in0[]   = {
/* 0000 */  0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01, 0xFF
  };

/* -== TEST-1: CRC_DONE | BUFFER_RECREATED | CIS_AREA_SIZE_UPDATED | NEW_BUFFER_CLEANED ==- */
static uint8 in1[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF,
  };
static uint8 out1[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0x85, 0x04, 0x3c, 0x93, 0x41, 0x22,
/* 0060 */  0xFF
  };

/* -== TEST-2: CRC_DONE ==- */
static uint8 in2[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 0060 */  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };
static uint8 out2[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0x85, 0x04, 0x3c, 0x93, 0x41, 0x22,
/* 0060 */  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };

/* -== TEST-3: CRC_DONE ==- */
static uint8 in3[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
/* 0060 */  0xFF
  };
static uint8 out3[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0x85, 0x04, 0x3c, 0x93, 0x41, 0x22,
/* 0060 */  0xFF
  };

/* -== TEST-4: CRC_PRESENT ==- */
static uint8 in4[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0x85, 0x04, 0x3c, 0x93, 0x41, 0x22,
/* 0060 */  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };
static uint8 out4[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04,   0x80, 0x10, 0x40, 0x44, 0x41, 0x00, 0x00, 0x00,
/* 0050 */  0x09, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   0x01, 0x08, 0x85, 0x04, 0x3c, 0x93, 0x41, 0x22,
/* 0060 */  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };

/* -== TEST-5: TERMINATOR_MISSED ==- */
static uint8 in5[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00
  };

/* -== TEST-6: CIS_AREA_SIZE_WRONG ==- */
static uint8 in6[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04
  };

/* -== TEST-7: CIS_AREA_SIZE_WRONG ==- */
static uint8 in7[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04
  };

/* -== TEST-8: EEPROM_VERSION_WRONG ==- */
static uint8 in8[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01
  };

/* -== TEST-9: EEPROM_HEAD_WRONG ==- */
static uint8 in9[]   = {
  EEPROM_HEAD(0x1B, 0xFC),
/* 0040 */  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };

/* -== TEST-10: EEPROM_HEAD_WRONG ==- */
static uint8 in10[]   = {
  EEPROM_HEAD(0x00, 0x00),
/* 0040 */  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

/* -== TEST-11: EEPROM_HEAD_WRONG ==- */
static uint8 in11[]   = {
  EEPROM_HEAD(0xFF, 0xFF),
/* 0040 */  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };

/* -== TEST-12: EEPROM_SIZE_WRONG ==- */
static uint8 in12[]   = {
  EEPROM_HEAD(0xFC, 0x1B)
  };

/* -== TEST-13: EEPROM_SIZE_WRONG ==- */
static uint8 in13[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
  };

/* -== TEST-14: CRC_DONE | BUFFER_RECREATED | CIS_AREA_SIZE_UPDATED | NEW_BUFFER_CLEANED ==- */
static uint8 in14[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0xFF
  };

static uint8 out14[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x85, 0x04, 0xe3, 0x16, 0x96, 0x74, 0xFF
  };

/* -== TEST-15: CIS_SIZE_WRONG ==- */
static uint8 in15[]   = {
  EEPROM_HEAD(0xFC, 0x1B),
/* 0040 */  0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x80, 0x10, 0xFF
  };

typedef struct {
  uint8   *in;
  uint16  in_size;
  uint8   *out;
  uint16  out_size;
  uint32  steps;
} eeprom_utest_t;

static eeprom_utest_t eeprom_utest_array[] =
{
  {in0,  sizeof(in0),  NULL, 0, EEPROM_SIZE_WRONG | CRC_APPEND_FAILED},
  {in1,  sizeof(in1),  out1, sizeof(out1), CRC_DONE | BUFFER_RECREATED | CIS_AREA_SIZE_UPDATED | NEW_BUFFER_CLEANED},
  {in2,  sizeof(in2),  out2, sizeof(out2), CRC_DONE | BUFFER_REUSED | CIS_AREA_SIZE_UPDATED},
  {in3,  sizeof(in3),  out3, sizeof(out3), CRC_DONE | BUFFER_REUSED},
  {in4,  sizeof(in4),  out4, sizeof(out4), CRC_PRESENT},
  {in5,  sizeof(in5),  NULL, 0, TERMINATOR_MISSED | CRC_APPEND_FAILED},
  {in6,  sizeof(in6),  NULL, 0, CIS_AREA_SIZE_WRONG | CRC_APPEND_FAILED},
  {in7,  sizeof(in7),  NULL, 0, CIS_AREA_SIZE_WRONG | CRC_APPEND_FAILED},
  {in8,  sizeof(in8),  NULL, 0, EEPROM_VERSION_WRONG | CRC_APPEND_FAILED},
  {in9,  sizeof(in9),  NULL, 0, EEPROM_HEAD_WRONG | CRC_APPEND_FAILED},
  {in10, sizeof(in10), NULL, 0, EEPROM_HEAD_WRONG | CRC_APPEND_FAILED},
  {in11, sizeof(in11), NULL, 0, EEPROM_HEAD_WRONG | CRC_APPEND_FAILED},
  {in12, sizeof(in12), NULL, 0, EEPROM_SIZE_WRONG | CRC_APPEND_FAILED},
  {in13, sizeof(in13), NULL, 0, EEPROM_SIZE_WRONG | CRC_APPEND_FAILED},
  {in14, sizeof(in14), out14, sizeof(out14), CRC_DONE | BUFFER_RECREATED | CIS_AREA_SIZE_UPDATED | NEW_BUFFER_CLEANED},
  {in15, sizeof(in15), NULL, 0, CIS_SIZE_WRONG | TERMINATOR_MISSED | CRC_APPEND_FAILED},
  /* NOTE: Should be last one */
  {NULL, 0, NULL, 0, 0}
};

static int
_data_validate(uint8 const *buff, uint32 size)
{
  int i;
  int err = MTLK_ERR_OK;

  if (NULL == buff) /* is not needed */
    return MTLK_ERR_OK;

  if (size != tmb_buffer_used)
  {
    ELOG_DD("FS HLPR: Wrong size [%d], should be [%d]", size, tmb_buffer_used);
    return MTLK_ERR_UNKNOWN;
  }

  for (i = 0; i < size; i++)
  {
    if (tmb_buffer[i] == buff[i])
      continue;

    ELOG_DDD("FS HLPR: Wrong EEPROM data [0x%02x] at 0x%08x, expected [0x%02x]", tmb_buffer[i], i, buff[i]);
    err = MTLK_ERR_UNKNOWN;
  }

  return err;
}

void __MTLK_IFUNC
eeprom_utest_step(uint32 step)
{
  utest_steps |= step;
}

void __MTLK_IFUNC
eeprom_utest_write(void* buff, uint32 len)
{
  MTLK_ASSERT(buff);
  MTLK_ASSERT(len <= sizeof(tmb_buffer));

  memcpy(tmb_buffer, buff, len);
  tmb_buffer_used = len;
}

void __MTLK_IFUNC
run_eeprom_crc_utest(
  void (*_file_save_handler)(
    mtlk_irba_t*,
    mtlk_handle_t,
    const mtlk_guid_t*,
    void*,
    uint32)
)
{
  int i = 0;
  eeprom_utest_t *p = eeprom_utest_array;
  BOOL all_pased = TRUE;

  MTLK_ASSERT(_file_save_handler);

  ILOG0_V("FS HLPR: Start EEPROM unit tests");

  while (NULL != p->in)
  {
    BOOL pased = FALSE;
    struct mtlk_file_save *evt;
    uint32 evt_size = sizeof(struct mtlk_file_save) + p->in_size;

    ILOG0_D("FS HLPR: EEPROM unit test [%d]", i);

    utest_steps = 0;

    evt = malloc(evt_size);
    if (NULL == evt)
    {
      ELOG_V("FS HLPR: Cannot allocate memory for tests");
      goto NEXT;
    }

    snprintf((void*)evt->fname, sizeof(evt->fname), "unused.bin");
    evt->size = p->in_size;
    memcpy((void*)(evt + 1), p->in, p->in_size);

    (*_file_save_handler)(NULL, HANDLE_T(NULL), &IRBE_FILE_SAVE, evt, evt_size);

    free(evt);

    if (utest_steps != p->steps)
    {
      ELOG_DD("FS HLPR: Unit test steps are wrong [0x%08x], expected [0x%08x]",
        utest_steps, p->steps);
      all_pased = FALSE;
    }
    else
    {
      pased = TRUE;
    }

    if ((TRUE == pased) && (MTLK_ERR_OK != _data_validate(p->out, p->out_size)))
    {
      pased = FALSE;
      all_pased = FALSE;
    }

NEXT:

    ILOG0_DS("FS HLPR: EEPROM unit test [%d] %s", i, (TRUE == pased) ? "SUCCEED" : "FAILED");

    p++;
    i++;
  }

  ILOG0_S("FS HLPR: All EEPROM unit tests done [%s]!", (TRUE == all_pased) ? "SUCCEED" : "FAILED");
}

#endif /* defined(EEPROM_CRC_ON_DRVHLPR) & defined(RUN_EEPROM_CRC_UTEST) */
