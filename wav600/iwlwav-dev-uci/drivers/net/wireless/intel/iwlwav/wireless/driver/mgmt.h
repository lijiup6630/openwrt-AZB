/******************************************************************************

         Copyright (c) 2020, MaxLinear, Inc.
         Copyright 2016 - 2020 Intel Corporation
         Copyright 2015 - 2016 Lantiq Beteiligungs-GmbH & Co. KG
         Copyright 2009 - 2014 Lantiq Deutschland GmbH
         Copyright 2007 - 2008 Infineon Technologies AG

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

#ifndef _MTLK_MGMT_H_
#define _MTLK_MGMT_H_

#include "mtlk_coreui.h"

int __MTLK_IFUNC
mtlk_mgmt_transmit (
  mtlk_core_t *core,
  mtlk_nbuf_t *nbuf,
  mtlk_mgmt_txclb_f clb,
  mtlk_handle_t clb_usr_data);

#endif /* _MTLK_MGMT_H_ */
