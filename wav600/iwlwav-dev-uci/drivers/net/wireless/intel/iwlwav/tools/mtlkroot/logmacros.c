#if (IWLWAV_RTLOG_MAX_DLEVEL >= 4)
__MTLK_FLOG void
__ILOG4_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
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
__ILOG4_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
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
__ILOG4_SDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
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
__ELOG_SDDP_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, const void * p4)
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
__ELOG_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_V_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_C_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int8 c1)
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
                       + LOGPKT_SCALAR_SIZE(c1);
    uint8 *pdata__;
    mtlk_log_event_t log_event__;
    mtlk_log_buf_entry_t *pbuf__ = mtlk_log_new_pkt_reserve(LOGPKT_EVENT_HDR_SIZE + datalen__, &pdata__);
    if (pbuf__ != NULL) {
      uint8 *p__ = pdata__;

      MTLK_ASSERT(pdata__ != NULL);
      MTLK_ASSERT(datalen__ <= 2047);

   // OLD header format
   // log_event__.info = LOG_MAKE_INFO(0, oid, gid);
   // log_event__.info_ex = LOG_MAKE_INFO_EX(fid, lid, datalen__, 0);

   // NEW header format
   // LOG_MAKE_INFO(log_event__, ver, dsize, wif, dest, prior, exp, oid, gid, fid, lid)
      LOG_MAKE_INFO(log_event__, /* ver */ 0, datalen__, /* wif */ 0,
                    0, 0, 0, /* dest, prior, exp, */
                    oid, gid, fid, lid);

      log_event__.timestamp = mtlk_log_get_timestamp();

      /* We do not copy the whole structure to avoid issues with  */
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

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int8) (c1));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL)
__MTLK_FLOG void
__WLOG_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
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
    CWARNING(fname, lid, fmt, (const char *) (s1), (int32) (d2));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_SDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
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
__ELOG_DDSDDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4, int32 d5, int32 d6)
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
      LOGPKT_PUT_STRING(s3);
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
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4), (int32) (d5), (int32) (d6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_SDDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4)
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
    CLOG(fname, lid, 2, fmt, (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 0)
__MTLK_FLOG void
__ILOG0_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1)
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
__ELOG_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2)
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
__ILOG0_SDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
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
__ILOG2_DPP_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3)
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
    CLOG(fname, lid, 2, fmt, (int32) (d1), (const void *) (p2), (const void *) (p3));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_DDDDS_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5)
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
__ELOG_DDDDSS_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5, const char * s6)
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
    size_t s6len__ = strlen(s6) + 1;

    size_t datalen__ = LOGPKT_STRING_SIZE(fname)
                       + LOGPKT_SCALAR_SIZE(lid_int32)
                       + LOGPKT_SCALAR_SIZE(d1)
                       + LOGPKT_SCALAR_SIZE(d2)
                       + LOGPKT_SCALAR_SIZE(d3)
                       + LOGPKT_SCALAR_SIZE(d4)
                       + LOGPKT_STRING_SIZE(s5)
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
      LOGPKT_PUT_STRING(s5);
      LOGPKT_PUT_STRING(s6);

      MTLK_ASSERT(p__ == pdata__ + datalen__ + LOGPKT_EVENT_HDR_SIZE);
      mtlk_log_new_pkt_release(pbuf__);
    }
  }
  #endif /*__KLOCWORK__*/
#endif
#if (IWLWAV_RTLOG_FLAGS & RTLF_CONSOLE_ENABLED)
  if ((flags__ & LOG_TARGET_CONSOLE) != 0) {
    CERROR(fname, lid, fmt, (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5), (const char *) (s6));
  }
#endif
}
#endif /* IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 2)
__MTLK_FLOG void
__ILOG2_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
__MTLK_FLOG void
__ILOG1_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2)
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
__ILOG1_DDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3)
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


#if (IWLWAV_RTLOG_MAX_DLEVEL >= IWLWAV_RTLOG_ERROR_DLEVEL)
__MTLK_FLOG void
__ELOG_PP_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2)
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


