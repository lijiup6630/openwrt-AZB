#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_YSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (y1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const void *) (y1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_YDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (y1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const void *) (y1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_YP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (y1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (y1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (y1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_YY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (y1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_YPY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * p2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (y1), (const void *) (p2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (y1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_YPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * p2, const void * p3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (y1), (const void *) (p2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_YSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const char * s2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (y1), (const char *) (s2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (p1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDCD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int8 c3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(c3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT8(c3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int8) (c3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SSS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__SLOG1_8(const char *fname, uint8 gid, uint8 fid, uint16 lid, uint16 src_task_id, uint16 dst_task_id, uint16 message_size, char *message)
{
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  int flags__ = mtlk_log_get_flags(1, 8, gid);
  if ((flags__ & LOG_TARGET_REMOTE) != 0)
  {
    size_t datalen__ = LOGPKT_SIGNAL_SIZE(message_size);
    mtlk_log_multi_buffer_t *buffers;
    mtlk_log_signal_t mtlk_log_signal;

    if (mtlk_log_new_pkt_reserve_multi(LOGPKT_EVENT_HDR_SIZE_VER2 + datalen__, &buffers))
    {
      char *packet = message;
      mtlk_log_multi_buffer_t *current_buffer = &buffers[0];
      while (current_buffer->buf)
      {
        uint8 *p__ = current_buffer->data;
        uint16 packet_size = current_buffer->data_size;

        if (current_buffer == &buffers[0]) /* first packet contains header */
        {
          mtlk_log_event_t log_event__;

      // OLD header format
      // log_event__.info      = LOG_MAKE_INFO(2, 8, gid);
      // log_event__.info_ex   = LOG_MAKE_INFO_EX(fid, lid, 0, 0);
      // log_event__.size      = datalen__;

          LOG_MAKE_INFO(log_event__, /* ver */ 2, datalen__, /* wif */ 0,
                        0, 0, 0, /* dest, prior, exp, */
                        8, gid, fid, lid);

          log_event__.timestamp = mtlk_log_get_timestamp();
          
          logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE_VER2, &log_event__, LOGPKT_EVENT_HDR_SIZE_VER2);
          
          p__ += LOGPKT_EVENT_HDR_SIZE_VER2;
          packet_size -= LOGPKT_EVENT_HDR_SIZE_VER2;
                                           
	  mtlk_log_signal.src_task_id = src_task_id;
	  mtlk_log_signal.dst_task_id = dst_task_id;
	  mtlk_log_signal.len = message_size;
      
          LOGPKT_PUT_SIGNAL_HEADER(mtlk_log_signal);

          packet_size -= LOGPKT_SIGNAL_HDR_SIZE;
                                           
          MTLK_ASSERT((int16)packet_size >= 0);
          MTLK_ASSERT(p__ == current_buffer->data + LOGPKT_EVENT_HDR_SIZE_VER2 + LOGPKT_SIGNAL_HDR_SIZE);
        }

        LOGPKT_PUT_SIGNAL_BODY(packet, packet_size);

        MTLK_ASSERT(p__ == current_buffer->data + current_buffer->data_size);

        packet += packet_size;

        ++ current_buffer;
      }
      mtlk_log_new_pkt_release_multi(buffers);
    }
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (p1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__SLOG0_8(const char *fname, uint8 gid, uint8 fid, uint16 lid, uint16 src_task_id, uint16 dst_task_id, uint16 message_size, char *message)
{
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  int flags__ = mtlk_log_get_flags(0, 8, gid);
  if ((flags__ & LOG_TARGET_REMOTE) != 0)
  {
    size_t datalen__ = LOGPKT_SIGNAL_SIZE(message_size);
    mtlk_log_multi_buffer_t *buffers;
    mtlk_log_signal_t mtlk_log_signal;

    if (mtlk_log_new_pkt_reserve_multi(LOGPKT_EVENT_HDR_SIZE_VER2 + datalen__, &buffers))
    {
      char *packet = message;
      mtlk_log_multi_buffer_t *current_buffer = &buffers[0];
      while (current_buffer->buf)
      {
        uint8 *p__ = current_buffer->data;
        uint16 packet_size = current_buffer->data_size;

        if (current_buffer == &buffers[0]) /* first packet contains header */
        {
          mtlk_log_event_t log_event__;

      // OLD header format
      // log_event__.info      = LOG_MAKE_INFO(2, 8, gid);
      // log_event__.info_ex   = LOG_MAKE_INFO_EX(fid, lid, 0, 0);
      // log_event__.size      = datalen__;

          LOG_MAKE_INFO(log_event__, /* ver */ 2, datalen__, /* wif */ 0,
                        0, 0, 0, /* dest, prior, exp, */
                        8, gid, fid, lid);

          log_event__.timestamp = mtlk_log_get_timestamp();
          
          logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE_VER2, &log_event__, LOGPKT_EVENT_HDR_SIZE_VER2);
          
          p__ += LOGPKT_EVENT_HDR_SIZE_VER2;
          packet_size -= LOGPKT_EVENT_HDR_SIZE_VER2;
                                           
	  mtlk_log_signal.src_task_id = src_task_id;
	  mtlk_log_signal.dst_task_id = dst_task_id;
	  mtlk_log_signal.len = message_size;
      
          LOGPKT_PUT_SIGNAL_HEADER(mtlk_log_signal);

          packet_size -= LOGPKT_SIGNAL_HDR_SIZE;
                                           
          MTLK_ASSERT((int16)packet_size >= 0);
          MTLK_ASSERT(p__ == current_buffer->data + LOGPKT_EVENT_HDR_SIZE_VER2 + LOGPKT_SIGNAL_HDR_SIZE);
        }

        LOGPKT_PUT_SIGNAL_BODY(packet, packet_size);

        MTLK_ASSERT(p__ == current_buffer->data + current_buffer->data_size);

        packet += packet_size;

        ++ current_buffer;
      }
      mtlk_log_new_pkt_release_multi(buffers);
    }
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const char *) (s1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const char *) (s1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const char *) (s1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_SDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s5len__ = strlen(s5) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_STRING_SIZE(s5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_STRING(s5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (p2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_PPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (p1), (const void *) (p2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, const char * s6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s6len__ = strlen(s6) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_STRING_SIZE(s6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_STRING(s6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const char *) (s6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 6)
__MTLK_FLOG void
__ILOG6_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 6, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_PPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const void *) (p1), (const void *) (p2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const char *) (s1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const void *) (p2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (p1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const void *) (p1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 5)
__MTLK_FLOG void
__ILOG5_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 5, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 6)
__MTLK_FLOG void
__ILOG6_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 6, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 5)
__MTLK_FLOG void
__ILOG5_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 5, fmt, (const void *) (y1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDPDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4, int32 d5, int32 d6, int32 d7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 5)
__MTLK_FLOG void
__ILOG5_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 5, fmt, (int32) (d1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 5)
__MTLK_FLOG void
__ILOG5_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 5, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_PPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (p1), (const void *) (p2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (const void *) (p2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (p1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (p1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (p2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DSDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (p1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_SCALAR_SIZE(d9);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_INT32(d9);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_PPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, const void * p3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (p1), (const void *) (p2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SPPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2, const void * p3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const void *) (p2), (const void *) (p3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const char *) (s1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2, const void * p3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const void *) (p2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DPDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (p2), (int32) (d3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (const void *) (p3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (const void *) (p1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const void *) (p2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_HHD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1, int64 h2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(h1)
                       + LOGPKT_SCALAR_SIZE(h2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT64(h1);
      LOGPKT_PUT_INT64(h2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int64) (h1), (int64) (h2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDPDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4, const void * p5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(p5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_PTR(p5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4), (const void *) (p5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DPPPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, const void * p4, int32 d5, int32 d6, int32 d7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const void *) (p2), (const void *) (p3), (const void *) (p4), (int32) (d5), (int32) (d6), (int32) (d7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const void *) (p1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (p2), (const void *) (p3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDDPPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, const void * p4, const void * p5, int32 d6, int32 d7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(p5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_PTR(p5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (const void *) (p4), (const void *) (p5), (int32) (d6), (int32) (d7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_KK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * k2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_IP6ADDR_SIZE(k1)
                       + LOGPKT_IP6ADDR_SIZE(k2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_IP6ADDR(k1);
      LOGPKT_PUT_IP6ADDR(k2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (k1), (const void *) (k2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (p2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__CAPWAP1_8(const char *fname, uint8 gid, uint8 fid, uint16 lid, uint8 arg1, void *arg2, size_t arg3, uint8 arg4, int arg5)
{
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  int flags__ = mtlk_log_get_flags(1, 8, gid);
  if ((flags__ & LOG_TARGET_CAPWAP) != 0)
  {
    mtlk_ndev_send_capwap_packet(arg1, arg2, arg3, arg4, arg5);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDHPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5, int32 d6, int32 d7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(h3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT64(h3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5), (int32) (d6), (int32) (d7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (const void *) (y1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDHPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(h3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT64(h3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDHPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(h3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT64(h3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (p1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDHPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(h3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT64(h3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (p1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SPDPDPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2, int32 d3, const void * p4, int32 d5, const void * p6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(p6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_PTR(p6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const void *) (p2), (int32) (d3), (const void *) (p4), (int32) (d5), (const void *) (p6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDDDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9, int32 d10)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_SCALAR_SIZE(d9)
                       + LOGPKT_SCALAR_SIZE(d10);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_INT32(d9);
      LOGPKT_PUT_INT32(d10);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDDDYDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, const void * y6, int32 d7, int32 d8, int32 d9)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_MACADDR_SIZE(y6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_SCALAR_SIZE(d9);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_MACADDR(y6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_INT32(d9);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const void *) (y6), (int32) (d7), (int32) (d8), (int32) (d9));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDDDYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, const void * y6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_MACADDR_SIZE(y6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_MACADDR(y6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const void *) (y6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const void *) (y1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, const char * s4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;
    size_t s4len__ = strlen(s4) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_STRING_SIZE(s4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_STRING(s4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (const char *) (s4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDDDSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5, int32 d6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s5len__ = strlen(s5) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_STRING_SIZE(s5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_STRING(s5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5), (int32) (d6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_SDPPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const void * p3, const void * p4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const char *) (s1), (int32) (d2), (const void *) (p3), (const void *) (p4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DYSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const char * s3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_STRING_SIZE(s3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_STRING(s3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const void *) (y2), (const char *) (s3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDDDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, const char * s7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s7len__ = strlen(s7) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_STRING_SIZE(s7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_STRING(s7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (const char *) (s7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const void *) (p2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DSY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const char *) (s2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_K_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_IP6ADDR_SIZE(k1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_IP6ADDR(k1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (k1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 5)
__MTLK_FLOG void
__ILOG5_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 5, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (y1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_K_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_IP6ADDR_SIZE(k1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_IP6ADDR(k1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (k1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_KY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_IP6ADDR_SIZE(k1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_IP6ADDR(k1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (k1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_IP6ADDR_SIZE(k2)
                       + LOGPKT_IP6ADDR_SIZE(k3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_IP6ADDR(k2);
      LOGPKT_PUT_IP6ADDR(k3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (k2), (const void *) (k3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const void *) (y2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_IP6ADDR_SIZE(k2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_IP6ADDR(k2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (k2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_IP6ADDR_SIZE(k2)
                       + LOGPKT_IP6ADDR_SIZE(k3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_IP6ADDR(k2);
      LOGPKT_PUT_IP6ADDR(k3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (k2), (const void *) (k3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DKKD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_IP6ADDR_SIZE(k2)
                       + LOGPKT_IP6ADDR_SIZE(k3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_IP6ADDR(k2);
      LOGPKT_PUT_IP6ADDR(k3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (k2), (const void *) (k3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 5)
__MTLK_FLOG void
__ILOG5_KK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * k2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_IP6ADDR_SIZE(k1)
                       + LOGPKT_IP6ADDR_SIZE(k2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_IP6ADDR(k1);
      LOGPKT_PUT_IP6ADDR(k2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 5, fmt, (const void *) (k1), (const void *) (k2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_IP6ADDR_SIZE(k2)
                       + LOGPKT_IP6ADDR_SIZE(k3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_IP6ADDR(k2);
      LOGPKT_PUT_IP6ADDR(k3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (k2), (const void *) (k3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DKD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_IP6ADDR_SIZE(k2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_IP6ADDR(k2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (k2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_KKD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * k2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_IP6ADDR_SIZE(k1)
                       + LOGPKT_IP6ADDR_SIZE(k2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_IP6ADDR(k1);
      LOGPKT_PUT_IP6ADDR(k2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (k1), (const void *) (k2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const void *) (p1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_YY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (y1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_PDPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, const void * p3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (p1), (int32) (d2), (const void *) (p3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SDSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const char * s3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (int32) (d2), (const char *) (s3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * k2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_IP6ADDR_SIZE(k2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_IP6ADDR(k2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const void *) (k2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const char *) (s1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (int32) (d2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_SSS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const char *) (s1), (const char *) (s2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_SSS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_IP6ADDR_SIZE(k2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_IP6ADDR(k2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (const void *) (k2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DYDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3, const void * y4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_MACADDR_SIZE(y4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_MACADDR(y4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (y2), (int32) (d3), (const void *) (y4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DYY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (const void *) (y2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, const char * s5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s5len__ = strlen(s5) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_STRING_SIZE(s5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_STRING(s5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (const void *) (y3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDDYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, const void * y4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (const void *) (y4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DSDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, const char * s5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;
    size_t s5len__ = strlen(s5) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_STRING_SIZE(s5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_STRING(s5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (const char *) (s5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_SDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDSDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4, const void * y5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_MACADDR_SIZE(y5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_MACADDR(y5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4), (const void *) (y5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DYS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (const void *) (y2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DSY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const char *) (s2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DYY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const void * y3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_MACADDR_SIZE(y3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_MACADDR(y3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (y2), (const void *) (y3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDYY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3, const void * y4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (const void *) (y3), (const void *) (y4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (y2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (const void *) (y3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_YDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (const void *) (y2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (y2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 9)
__MTLK_FLOG void
__ILOG9_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 9, fmt);
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 9 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_HHD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1, int64 h2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(h1)
                       + LOGPKT_SCALAR_SIZE(h2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT64(h1);
      LOGPKT_PUT_INT64(h2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int64) (h1), (int64) (h2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (y1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const char * s3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s3len__ = strlen(s3) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_STRING_SIZE(s3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_STRING(s3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (int32) (d2), (const char *) (s3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const void *) (y2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_H_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(h1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT64(h1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int64) (h1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DH_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int64 h2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(h2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT64(h2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int64) (h2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_PPPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, const void * p3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (p1), (const void *) (p2), (const void *) (p3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_PPPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, const void * p3, const void * p4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (p1), (const void *) (p2), (const void *) (p3), (const void *) (p4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SDDDDSDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5, const char * s6, int32 d7, int32 d8, int32 d9, int32 d10, int32 d11)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s6len__ = strlen(s6) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_STRING_SIZE(s6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_SCALAR_SIZE(d9)
                       + LOGPKT_SCALAR_SIZE(d10)
                       + LOGPKT_SCALAR_SIZE(d11);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_STRING(s6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_INT32(d9);
      LOGPKT_PUT_INT32(d10);
      LOGPKT_PUT_INT32(d11);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const char *) (s6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10), (int32) (d11));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (const void *) (y2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (y1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (const void *) (y1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DSDDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9, int32 d10)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_SCALAR_SIZE(d9)
                       + LOGPKT_SCALAR_SIZE(d10);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_INT32(d9);
      LOGPKT_PUT_INT32(d10);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYDDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9, int32 d10, int32 d11, int32 d12)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_SCALAR_SIZE(d9)
                       + LOGPKT_SCALAR_SIZE(d10)
                       + LOGPKT_SCALAR_SIZE(d11)
                       + LOGPKT_SCALAR_SIZE(d12);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_INT32(d9);
      LOGPKT_PUT_INT32(d10);
      LOGPKT_PUT_INT32(d11);
      LOGPKT_PUT_INT32(d12);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10), (int32) (d11), (int32) (d12));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYDDDDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6, int32 d7, int32 d8, const void * y9)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_MACADDR_SIZE(y9);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_MACADDR(y9);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (const void *) (y9));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, const char * s5, int32 d6, int32 d7, int32 d8, int32 d9)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;
    size_t s5len__ = strlen(s5) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_STRING_SIZE(s5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8)
                       + LOGPKT_SCALAR_SIZE(d9);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_STRING(s5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);
      LOGPKT_PUT_INT32(d9);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (const char *) (s5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, const char * s5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;
    size_t s5len__ = strlen(s5) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_STRING_SIZE(s5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_STRING(s5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (const char *) (s5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSYYKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, const void * k5, const void * k6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_MACADDR_SIZE(y3)
                       + LOGPKT_MACADDR_SIZE(y4)
                       + LOGPKT_IP6ADDR_SIZE(k5)
                       + LOGPKT_IP6ADDR_SIZE(k6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_MACADDR(y3);
      LOGPKT_PUT_MACADDR(y4);
      LOGPKT_PUT_IP6ADDR(k5);
      LOGPKT_PUT_IP6ADDR(k6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (const void *) (k5), (const void *) (k6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_PHHD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int64 h2, int64 h3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(h2)
                       + LOGPKT_SCALAR_SIZE(h3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT64(h2);
      LOGPKT_PUT_INT64(h3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (p1), (int64) (h2), (int64) (h3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_YDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_YDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (y1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_PY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const void *) (p1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_PY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (p1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (p2), (const void *) (p3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 6)
__MTLK_FLOG void
__ILOG6_DDDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const void * p5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(p5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_PTR(p5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 6, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const void *) (p5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 6)
__MTLK_FLOG void
__ILOG6_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 6, fmt, (int32) (d1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DPDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (const void *) (p2), (int32) (d3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_PPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (p1), (const void *) (p2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_DDPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_PDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (p1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_CCDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int8 c1, int8 c2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(c1)
                       + LOGPKT_SCALAR_SIZE(c2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT8(c1);
      LOGPKT_PUT_INT8(c2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int8) (c1), (int8) (c2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_SDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_PP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const void *) (p1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_PP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(p2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_PTR(p2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const void *) (p1), (const void *) (p2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SDDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, const void * p5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(p5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_PTR(p5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (const void *) (p5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (int32) (d1), (const void *) (p2), (const void *) (p3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CWARNING(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7)
                       + LOGPKT_SCALAR_SIZE(d8);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);
      LOGPKT_PUT_INT32(d8);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_HHDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1, int64 h2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(h1)
                       + LOGPKT_SCALAR_SIZE(h2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT64(h1);
      LOGPKT_PUT_INT64(h2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (int64) (h1), (int64) (h2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (int32) (d1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const void *) (y1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(p2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_PTR(p2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (p2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 3)
__MTLK_FLOG void
__ILOG3_SDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const void * p3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(p3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_PTR(p3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 3, fmt, (const char *) (s1), (int32) (d2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 4, fmt, (const void *) (p1), (int32) (d2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SSDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_MACADDR_SIZE(y2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_MACADDR(y2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const void *) (y2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_MACADDR_SIZE(y2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_MACADDR(y2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (const char *) (s1), (const void *) (y2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5)
                       + LOGPKT_SCALAR_SIZE(d6)
                       + LOGPKT_SCALAR_SIZE(d7);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_INT32(d1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);
      LOGPKT_PUT_INT32(d6);
      LOGPKT_PUT_INT32(d7);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_SS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL)
__MTLK_FLOG void
__RLOG_SSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_SCALAR_SIZE(d5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_INT32(d4);
      LOGPKT_PUT_INT32(d5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_MACADDR_SIZE(y1)
                       + LOGPKT_SCALAR_SIZE(d2);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_MACADDR(y1);
      LOGPKT_PUT_INT32(d2);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const void *) (y1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SSDPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, const void * p4, const void * p5)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4)
                       + LOGPKT_SCALAR_SIZE(p5);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);
      LOGPKT_PUT_PTR(p5);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 1, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3), (const void *) (p4), (const void *) (p5));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(d3);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_INT32(d3);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (const char *) (s2), (int32) (d3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, const void * p4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(p4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_INT32(d2);
      LOGPKT_PUT_INT32(d3);
      LOGPKT_PUT_PTR(p4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (const void *) (p4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_SSPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * p3, int32 d4)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;
    size_t s1len__ = strlen(s1) + 1;
    size_t s2len__ = strlen(s2) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_STRING_SIZE(s1)
                       + LOGPKT_STRING_SIZE(s2)
                       + LOGPKT_SCALAR_SIZE(p3)
                       + LOGPKT_SCALAR_SIZE(d4);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_STRING(s1);
      LOGPKT_PUT_STRING(s2);
      LOGPKT_PUT_PTR(p3);
      LOGPKT_PUT_INT32(d4);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const char *) (s1), (const char *) (s2), (const void *) (p3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1)
{
#if (IWLWAV_RTLOG_FLAGS & (RTLF_REMOTE_ENABLED | RTLF_CONSOLE_ENABLED))
  int flags__ = mtlk_log_get_flags(level, oid, gid);
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_REMOTE_ENABLED)
  #ifndef __KLOCWORK__
  if ((flags__ & LOG_TARGET_REMOTE) != 0) {

    int32 lid_int32 = lid;
    size_t fnamelen__ = strlen(fname) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(p1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
      /* incorrect packing. Client side assumes this structure    */
      /* is 1-byte packed, but some compilers have issues with    */
      /* creation of such structures.                             */
      /* WARNING: Because of this type of usage order of fields   */
      /* in the sctructure is important and must be preserved.    */
      logpkt_memcpy(p__, LOGPKT_EVENT_HDR_SIZE, &log_event__, LOGPKT_EVENT_HDR_SIZE);

      p__ += LOGPKT_EVENT_HDR_SIZE;

      LOGPKT_PUT_STRING(fname);
      LOGPKT_PUT_INT32(lid_int32);
      LOGPKT_PUT_PTR(p1);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CLOG(fname, lid, 0, fmt, (const void *) (p1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 0 */


