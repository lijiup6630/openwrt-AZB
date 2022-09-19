#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_YSD(fmt, y1, s2, d3)
#else

__MTLK_FLOG void
__ILOG2_YSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const char * s2, int32 d3);

#define ILOG2_YSD(fmt, y1, s2, d3) \
  __ILOG2_YSD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__WLOG_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define WLOG_DD(fmt, d1, d2) \
  __WLOG_DD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_Y(fmt, y1)
#else

__MTLK_FLOG void
__ELOG_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1);

#define ELOG_Y(fmt, y1) \
  __ELOG_Y_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_V(fmt)
#else

__MTLK_FLOG void
__ELOG_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ELOG_V(fmt) \
  __ELOG_V_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDDDDD(fmt, d1, d2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ILOG3_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ILOG3_DDDDDD(fmt, d1, d2, d3, d4, d5, d6) \
  __ILOG3_DDDDDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDDDD(fmt, d1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG3_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG3_DDDDD(fmt, d1, d2, d3, d4, d5) \
  __ILOG3_DDDDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_YDD(fmt, y1, d2, d3)
#else

__MTLK_FLOG void
__ILOG1_YDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3);

#define ILOG1_YDD(fmt, y1, d2, d3) \
  __ILOG1_YDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_YD(fmt, y1, d2)
#else

__MTLK_FLOG void
__ELOG_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2);

#define ELOG_YD(fmt, y1, d2) \
  __ELOG_YD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_V(fmt)
#else

__MTLK_FLOG void
__WLOG_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define WLOG_V(fmt) \
  __WLOG_V_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_D(fmt, d1)
#else

__MTLK_FLOG void
__ELOG_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ELOG_D(fmt, d1) \
  __ELOG_D_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_YP(fmt, y1, p2)
#else

__MTLK_FLOG void
__ILOG3_YP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * p2);

#define ILOG3_YP(fmt, y1, p2) \
  __ILOG3_YP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_Y(fmt, y1)
#else

__MTLK_FLOG void
__ILOG3_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1);

#define ILOG3_Y(fmt, y1) \
  __ILOG3_Y_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_YDDD(fmt, y1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG0_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4);

#define ILOG0_YDDD(fmt, y1, d2, d3, d4) \
  __ILOG0_YDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG0_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG0_DD(fmt, d1, d2) \
  __ILOG0_DD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ELOG_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ELOG_DD(fmt, d1, d2) \
  __ELOG_DD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_V(fmt)
#else

__MTLK_FLOG void
__ILOG2_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ILOG2_V(fmt) \
  __ILOG2_V_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_YD(fmt, y1, d2)
#else

__MTLK_FLOG void
__ILOG3_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2);

#define ILOG3_YD(fmt, y1, d2) \
  __ILOG3_YD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_YY(fmt, y1, y2)
#else

__MTLK_FLOG void
__ILOG2_YY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * y2);

#define ILOG2_YY(fmt, y1, y2) \
  __ILOG2_YY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_YPY(fmt, y1, p2, y3)
#else

__MTLK_FLOG void
__ILOG2_YPY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * p2, const void * y3);

#define ILOG2_YPY(fmt, y1, p2, y3) \
  __ILOG2_YPY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (const void *) (p2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_Y(fmt, y1)
#else

__MTLK_FLOG void
__ILOG2_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1);

#define ILOG2_Y(fmt, y1) \
  __ILOG2_Y_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_YPP(fmt, y1, p2, p3)
#else

__MTLK_FLOG void
__ILOG3_YPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * p2, const void * p3);

#define ILOG3_YPP(fmt, y1, p2, p3) \
  __ILOG3_YPP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (const void *) (p2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_YSDD(fmt, y1, s2, d3, d4)
#else

__MTLK_FLOG void
__ILOG0_YSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const char * s2, int32 d3, int32 d4);

#define ILOG0_YSDD(fmt, y1, s2, d3, d4) \
  __ILOG0_YSDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (const char *) (s2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG2_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG2_D(fmt, d1) \
  __ILOG2_D_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_PDD(fmt, p1, d2, d3)
#else

__MTLK_FLOG void
__ILOG2_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3);

#define ILOG2_PDD(fmt, p1, d2, d3) \
  __ILOG2_PDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DP(fmt, d1, p2)
#else

__MTLK_FLOG void
__ELOG_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2);

#define ELOG_DP(fmt, d1, p2) \
  __ELOG_DP_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG1_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG1_DD(fmt, d1, d2) \
  __ILOG1_DD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG1_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define ILOG1_DDDD(fmt, d1, d2, d3, d4) \
  __ILOG1_DDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ILOG1_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ILOG1_DDD(fmt, d1, d2, d3) \
  __ILOG1_DDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG0_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define ILOG0_DDDD(fmt, d1, d2, d3, d4) \
  __ILOG0_DDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ELOG_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ELOG_DDD(fmt, d1, d2, d3) \
  __ELOG_DDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ILOG0_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ILOG0_DDD(fmt, d1, d2, d3) \
  __ILOG0_DDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_D(fmt, d1)
#else

__MTLK_FLOG void
__WLOG_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define WLOG_D(fmt, d1) \
  __WLOG_D_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDCD(fmt, d1, d2, c3, d4)
#else

__MTLK_FLOG void
__ILOG0_DDCD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int8 c3, int32 d4);

#define ILOG0_DDCD(fmt, d1, d2, c3, d4) \
  __ILOG0_DDCD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int8) (c3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SSS(fmt, s1, s2, s3)
#else

__MTLK_FLOG void
__ILOG0_SSS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const char * s3);

#define ILOG0_SSS(fmt, s1, s2, s3) \
  __ILOG0_SSS_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define SLOG1(src_task_id, dst_task_id, message_type, message)
#else

__MTLK_FLOG void
__SLOG1_8(const char *fname, uint8 gid, uint8 fid, uint16 lid, uint16 src_task_id, uint16 dst_task_id, uint16 message_size, char *message);

#define SLOG1(src_task_id, dst_task_id, message_type, message) \
  __SLOG1_8(LOG_CONSOLE_TEXT_INFO, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               src_task_id, dst_task_id, sizeof(*message), (char *)message)
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG3_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG3_DD(fmt, d1, d2) \
  __ILOG3_DD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG2_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG2_DD(fmt, d1, d2) \
  __ILOG2_DD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_PD(fmt, p1, d2)
#else

__MTLK_FLOG void
__ILOG2_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2);

#define ILOG2_PD(fmt, p1, d2) \
  __ILOG2_PD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define SLOG0(src_task_id, dst_task_id, message_type, message)
#else

__MTLK_FLOG void
__SLOG0_8(const char *fname, uint8 gid, uint8 fid, uint16 lid, uint16 src_task_id, uint16 dst_task_id, uint16 message_size, char *message);

#define SLOG0(src_task_id, dst_task_id, message_type, message) \
  __SLOG0_8(LOG_CONSOLE_TEXT_INFO, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               src_task_id, dst_task_id, sizeof(*message), (char *)message)
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSDDD(fmt, d1, s2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG0_DSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5);

#define ILOG0_DSDDD(fmt, d1, s2, d3, d4, d5) \
  __ILOG0_DSDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG1_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG1_D(fmt, d1) \
  __ILOG1_D_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_S(fmt, s1)
#else

__MTLK_FLOG void
__WLOG_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define WLOG_S(fmt, s1) \
  __WLOG_S_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ILOG1_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ILOG1_SD(fmt, s1, d2) \
  __ILOG1_SD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ELOG_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ELOG_SD(fmt, s1, d2) \
  __ELOG_SD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_V(fmt)
#else

__MTLK_FLOG void
__ILOG0_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ILOG0_V(fmt) \
  __ILOG0_V_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG0_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG0_D(fmt, d1) \
  __ILOG0_D_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__ELOG_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define ELOG_DDDD(fmt, d1, d2, d3, d4) \
  __ELOG_DDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDSD(fmt, d1, d2, s3, d4)
#else

__MTLK_FLOG void
__ILOG1_DDSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4);

#define ILOG1_DDSD(fmt, d1, d2, s3, d4) \
  __ILOG1_DDSD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DSD(fmt, d1, s2, d3)
#else

__MTLK_FLOG void
__ILOG2_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3);

#define ILOG2_DSD(fmt, d1, s2, d3) \
  __ILOG2_DSD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DSDD(fmt, d1, s2, d3, d4)
#else

__MTLK_FLOG void
__ELOG_DSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4);

#define ELOG_DSDD(fmt, d1, s2, d3, d4) \
  __ELOG_DSDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDS(fmt, d1, d2, s3)
#else

__MTLK_FLOG void
__ILOG2_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3);

#define ILOG2_DDS(fmt, d1, d2, s3) \
  __ILOG2_DDS_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG2_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define ILOG2_DDDD(fmt, d1, d2, d3, d4) \
  __ILOG2_DDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ILOG2_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ILOG2_DDD(fmt, d1, d2, d3) \
  __ILOG2_DDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG3_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define ILOG3_DDDD(fmt, d1, d2, d3, d4) \
  __ILOG3_DDDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG4_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG4_S(fmt, s1) \
  __ILOG4_S_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ILOG4_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ILOG4_SD(fmt, s1, d2) \
  __ILOG4_SD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ILOG4_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ILOG4_SDD(fmt, s1, d2, d3) \
  __ILOG4_SDD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_S(fmt, s1)
#else

__MTLK_FLOG void
__ELOG_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ELOG_S(fmt, s1) \
  __ELOG_S_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SDDP(fmt, s1, d2, d3, p4)
#else

__MTLK_FLOG void
__ELOG_SDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, const void * p4);

#define ELOG_SDDP(fmt, s1, d2, d3, p4) \
  __ELOG_SDDP_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDS(fmt, d1, d2, d3, d4, s5)
#else

__MTLK_FLOG void
__ELOG_DDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5);

#define ELOG_DDDDS(fmt, d1, d2, d3, d4, s5) \
  __ELOG_DDDDS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SDDD(fmt, s1, d2, d3, d4)
#else

__MTLK_FLOG void
__ELOG_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4);

#define ELOG_SDDD(fmt, s1, d2, d3, d4) \
  __ELOG_SDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7, d8)
#else

__MTLK_FLOG void
__ELOG_DDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8);

#define ELOG_DDDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7, d8) \
  __ELOG_DDDDDDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DP(fmt, d1, p2)
#else

__MTLK_FLOG void
__ILOG2_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2);

#define ILOG2_DP(fmt, d1, p2) \
  __ILOG2_DP_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG4_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG4_DD(fmt, d1, d2) \
  __ILOG4_DD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG4_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG4_D(fmt, d1) \
  __ILOG4_D_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DS(fmt, d1, s2)
#else

__MTLK_FLOG void
__ILOG1_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2);

#define ILOG1_DS(fmt, d1, s2) \
  __ILOG1_DS_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_V(fmt)
#else

__MTLK_FLOG void
__ILOG1_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ILOG1_V(fmt) \
  __ILOG1_V_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DPDD(fmt, d1, p2, d3, d4)
#else

__MTLK_FLOG void
__ILOG1_DPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, int32 d4);

#define ILOG1_DPDD(fmt, d1, p2, d3, d4) \
  __ILOG1_DPDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDDDDD(fmt, d1, d2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ILOG1_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ILOG1_DDDDDD(fmt, d1, d2, d3, d4, d5, d6) \
  __ILOG1_DDDDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG3_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG3_D(fmt, d1) \
  __ILOG3_D_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG1_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG1_S(fmt, s1) \
  __ILOG1_S_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SP(fmt, s1, p2)
#else

__MTLK_FLOG void
__ILOG1_SP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2);

#define ILOG1_SP(fmt, s1, p2) \
  __ILOG1_SP_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SS(fmt, s1, s2)
#else

__MTLK_FLOG void
__ILOG1_SS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2);

#define ILOG1_SS(fmt, s1, s2) \
  __ILOG1_SS_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_PPDDD(fmt, p1, p2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG1_PPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3, int32 d4, int32 d5);

#define ILOG1_PPDDD(fmt, p1, p2, d3, d4, d5) \
  __ILOG1_PPDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDDS(fmt, d1, d2, d3, d4, d5, s6)
#else

__MTLK_FLOG void
__ELOG_DDDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, const char * s6);

#define ELOG_DDDDDS(fmt, d1, d2, d3, d4, d5, s6) \
  __ELOG_DDDDDS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const char *) (s6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 6)
#define ILOG6_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG6_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG6_S(fmt, s1) \
  __ILOG6_S_8(LOG_CONSOLE_TEXT_INFO, 6, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_PPD(fmt, p1, p2, d3)
#else

__MTLK_FLOG void
__ELOG_PPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3);

#define ELOG_PPD(fmt, p1, p2, d3) \
  __ELOG_PPD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ELOG_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ELOG_SDD(fmt, s1, d2, d3) \
  __ELOG_SDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ILOG2_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ILOG2_SDD(fmt, s1, d2, d3) \
  __ILOG2_SDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DPP(fmt, d1, p2, p3)
#else

__MTLK_FLOG void
__ILOG0_DPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3);

#define ILOG0_DPP(fmt, d1, p2, p3) \
  __ILOG0_DPP_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_PDD(fmt, p1, d2, d3)
#else

__MTLK_FLOG void
__ILOG0_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3);

#define ILOG0_PDD(fmt, p1, d2, d3) \
  __ILOG0_PDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_PD(fmt, p1, d2)
#else

__MTLK_FLOG void
__ILOG4_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2);

#define ILOG4_PD(fmt, p1, d2) \
  __ILOG4_PD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 5)
#define ILOG5_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ILOG5_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ILOG5_DDD(fmt, d1, d2, d3) \
  __ILOG5_DDD_8(LOG_CONSOLE_TEXT_INFO, 5, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 6)
#define ILOG6_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG6_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG6_DD(fmt, d1, d2) \
  __ILOG6_DD_8(LOG_CONSOLE_TEXT_INFO, 6, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ILOG3_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ILOG3_DDD(fmt, d1, d2, d3) \
  __ILOG3_DDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 5)
#define ILOG5_YD(fmt, y1, d2)
#else

__MTLK_FLOG void
__ILOG5_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2);

#define ILOG5_YD(fmt, y1, d2) \
  __ILOG5_YD_8(LOG_CONSOLE_TEXT_INFO, 5, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_V(fmt)
#else

__MTLK_FLOG void
__ILOG3_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ILOG3_V(fmt) \
  __ILOG3_V_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDPDDDD(fmt, d1, d2, p3, d4, d5, d6, d7)
#else

__MTLK_FLOG void
__ELOG_DDPDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4, int32 d5, int32 d6, int32 d7);

#define ELOG_DDPDDDD(fmt, d1, d2, p3, d4, d5, d6, d7) \
  __ELOG_DDPDDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 5)
#define ILOG5_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG5_DD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG5_DD(fmt, d1, d2) \
  __ILOG5_DD_8(LOG_CONSOLE_TEXT_INFO, 5, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 5)
#define ILOG5_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG5_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG5_D(fmt, d1) \
  __ILOG5_D_8(LOG_CONSOLE_TEXT_INFO, 5, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_PPD(fmt, p1, p2, d3)
#else

__MTLK_FLOG void
__ILOG0_PPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3);

#define ILOG0_PPD(fmt, p1, p2, d3) \
  __ILOG0_PPD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DPD(fmt, d1, p2, d3)
#else

__MTLK_FLOG void
__WLOG_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3);

#define WLOG_DPD(fmt, d1, p2, d3) \
  __WLOG_DPD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_P(fmt, p1)
#else

__MTLK_FLOG void
__ILOG2_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1);

#define ILOG2_P(fmt, p1) \
  __ILOG2_P_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_PDD(fmt, p1, d2, d3)
#else

__MTLK_FLOG void
__ILOG3_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3);

#define ILOG3_PDD(fmt, p1, d2, d3) \
  __ILOG3_PDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DPDDD(fmt, d1, p2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG1_DPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, int32 d4, int32 d5);

#define ILOG1_DPDDD(fmt, d1, p2, d3, d4, d5) \
  __ILOG1_DPDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDDDD(fmt, d1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG0_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG0_DDDDD(fmt, d1, d2, d3, d4, d5) \
  __ILOG0_DDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DSDP(fmt, d1, s2, d3, p4)
#else

__MTLK_FLOG void
__ILOG1_DSDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, const void * p4);

#define ILOG1_DSDP(fmt, d1, s2, d3, p4) \
  __ILOG1_DSDP_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DS(fmt, d1, s2)
#else

__MTLK_FLOG void
__ILOG0_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2);

#define ILOG0_DS(fmt, d1, s2) \
  __ILOG0_DS_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDDDD(fmt, d1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG2_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG2_DDDDD(fmt, d1, d2, d3, d4, d5) \
  __ILOG2_DDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_PD(fmt, p1, d2)
#else

__MTLK_FLOG void
__ILOG0_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2);

#define ILOG0_PD(fmt, p1, d2) \
  __ILOG0_PD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSDDDD(fmt, d1, s2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ILOG0_DSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ILOG0_DSDDDD(fmt, d1, s2, d3, d4, d5, d6) \
  __ILOG0_DSDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSDDDDDD(fmt, d1, s2, d3, d4, d5, d6, d7, d8)
#else

__MTLK_FLOG void
__ILOG0_DSDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8);

#define ILOG0_DSDDDDDD(fmt, d1, s2, d3, d4, d5, d6, d7, d8) \
  __ILOG0_DSDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSDDDDDDD(fmt, d1, s2, d3, d4, d5, d6, d7, d8, d9)
#else

__MTLK_FLOG void
__ILOG0_DSDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9);

#define ILOG0_DSDDDDDDD(fmt, d1, s2, d3, d4, d5, d6, d7, d8, d9) \
  __ILOG0_DSDDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_PPP(fmt, p1, p2, p3)
#else

__MTLK_FLOG void
__ILOG0_PPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, const void * p3);

#define ILOG0_PPP(fmt, p1, p2, p3) \
  __ILOG0_PPP_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SPPP(fmt, s1, p2, p3, p4)
#else

__MTLK_FLOG void
__ILOG0_SPPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2, const void * p3, const void * p4);

#define ILOG0_SPPP(fmt, s1, p2, p3, p4) \
  __ILOG0_SPPP_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (p2), (const void *) (p3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ILOG3_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ILOG3_SDD(fmt, s1, d2, d3) \
  __ILOG3_SDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ILOG0_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ILOG0_SDD(fmt, s1, d2, d3) \
  __ILOG0_SDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SPP(fmt, s1, p2, p3)
#else

__MTLK_FLOG void
__ILOG0_SPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2, const void * p3);

#define ILOG0_SPP(fmt, s1, p2, p3) \
  __ILOG0_SPP_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (p2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDP(fmt, d1, d2, p3)
#else

__MTLK_FLOG void
__ILOG3_DDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3);

#define ILOG3_DDP(fmt, d1, d2, p3) \
  __ILOG3_DDP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DPDP(fmt, d1, p2, d3, p4)
#else

__MTLK_FLOG void
__ILOG3_DPDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, const void * p4);

#define ILOG3_DPDP(fmt, d1, p2, d3, p4) \
  __ILOG3_DPDP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDPP(fmt, d1, d2, p3, p4)
#else

__MTLK_FLOG void
__ILOG3_DDPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, const void * p4);

#define ILOG3_DDPP(fmt, d1, d2, p3, p4) \
  __ILOG3_DDPP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (p3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_D(fmt, d1)
#else

__MTLK_FLOG void
__RLOG_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define RLOG_D(fmt, d1) \
  __RLOG_D_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_P(fmt, p1)
#else

__MTLK_FLOG void
__WLOG_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1);

#define WLOG_P(fmt, p1) \
  __WLOG_P_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DPD(fmt, d1, p2, d3)
#else

__MTLK_FLOG void
__ILOG0_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3);

#define ILOG0_DPD(fmt, d1, p2, d3) \
  __ILOG0_DPD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_HHD(fmt, h1, h2, d3)
#else

__MTLK_FLOG void
__ILOG1_HHD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1, int64 h2, int32 d3);

#define ILOG1_HHD(fmt, h1, h2, d3) \
  __ILOG1_HHD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int64) (h1), (int64) (h2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDPD(fmt, d1, d2, p3, d4)
#else

__MTLK_FLOG void
__ILOG3_DDPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4);

#define ILOG3_DDPD(fmt, d1, d2, p3, d4) \
  __ILOG3_DDPD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDPDP(fmt, d1, d2, p3, d4, p5)
#else

__MTLK_FLOG void
__ILOG0_DDPDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4, const void * p5);

#define ILOG0_DDPDP(fmt, d1, d2, p3, d4, p5) \
  __ILOG0_DDPDP_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4), (const void *) (p5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__WLOG_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define WLOG_DDD(fmt, d1, d2, d3) \
  __WLOG_DDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DPPPDDD(fmt, d1, p2, p3, p4, d5, d6, d7)
#else

__MTLK_FLOG void
__ILOG0_DPPPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, const void * p4, int32 d5, int32 d6, int32 d7);

#define ILOG0_DPPPDDD(fmt, d1, p2, p3, p4, d5, d6, d7) \
  __ILOG0_DPPPDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (const void *) (p3), (const void *) (p4), (int32) (d5), (int32) (d6), (int32) (d7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__RLOG_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define RLOG_DDDD(fmt, d1, d2, d3, d4) \
  __RLOG_DDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_P(fmt, p1)
#else

__MTLK_FLOG void
__ELOG_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1);

#define ELOG_P(fmt, p1) \
  __ELOG_P_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DPPD(fmt, d1, p2, p3, d4)
#else

__MTLK_FLOG void
__ILOG1_DPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, int32 d4);

#define ILOG1_DPPD(fmt, d1, p2, p3, d4) \
  __ILOG1_DPPD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (const void *) (p3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DS(fmt, d1, s2)
#else

__MTLK_FLOG void
__ELOG_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2);

#define ELOG_DS(fmt, d1, s2) \
  __ELOG_DS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDDPPDD(fmt, d1, d2, d3, p4, p5, d6, d7)
#else

__MTLK_FLOG void
__ILOG0_DDDPPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, const void * p4, const void * p5, int32 d6, int32 d7);

#define ILOG0_DDDPPDD(fmt, d1, d2, d3, p4, p5, d6, d7) \
  __ILOG0_DDDPPDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (const void *) (p4), (const void *) (p5), (int32) (d6), (int32) (d7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DP(fmt, d1, p2)
#else

__MTLK_FLOG void
__ILOG4_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2);

#define ILOG4_DP(fmt, d1, p2) \
  __ILOG4_DP_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_KK(fmt, k1, k2)
#else

__MTLK_FLOG void
__ILOG1_KK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * k2);

#define ILOG1_KK(fmt, k1, k2) \
  __ILOG1_KK_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (k1), (const void *) (k2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_S(fmt, s1)
#else

__MTLK_FLOG void
__RLOG_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define RLOG_S(fmt, s1) \
  __RLOG_S_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DPP(fmt, d1, p2, p3)
#else

__MTLK_FLOG void
__ILOG3_DPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3);

#define ILOG3_DPP(fmt, d1, p2, p3) \
  __ILOG3_DPP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DP(fmt, d1, p2)
#else

__MTLK_FLOG void
__ILOG3_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2);

#define ILOG3_DP(fmt, d1, p2) \
  __ILOG3_DP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_YDDD(fmt, y1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG3_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4);

#define ILOG3_YDDD(fmt, y1, d2, d3, d4) \
  __ILOG3_YDDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define CAPWAP1(arg1, arg2, arg3, arg4, arg5)
#else

__MTLK_FLOG void
__CAPWAP1_8(const char *fname, uint8 gid, uint8 fid, uint16 lid, uint8 arg1, void *arg2, size_t arg3, uint8 arg4, int arg5);

#define CAPWAP1(arg1, arg2, arg3, arg4, arg5) \
  __CAPWAP1_8(LOG_CONSOLE_TEXT_INFO, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               arg1, arg2, arg3, arg4, arg5)
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDHPDDD(fmt, d1, d2, h3, p4, d5, d6, d7)
#else

__MTLK_FLOG void
__ILOG3_DDHPDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5, int32 d6, int32 d7);

#define ILOG3_DDHPDDD(fmt, d1, d2, h3, p4, d5, d6, d7) \
  __ILOG3_DDHPDDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5), (int32) (d6), (int32) (d7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_YD(fmt, y1, d2)
#else

__MTLK_FLOG void
__WLOG_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2);

#define WLOG_YD(fmt, y1, d2) \
  __WLOG_YD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDHPDD(fmt, d1, d2, h3, p4, d5, d6)
#else

__MTLK_FLOG void
__ILOG0_DDHPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5, int32 d6);

#define ILOG0_DDHPDD(fmt, d1, d2, h3, p4, d5, d6) \
  __ILOG0_DDHPDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ILOG1_SDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ILOG1_SDD(fmt, s1, d2, d3) \
  __ILOG1_SDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDHPD(fmt, d1, d2, h3, p4, d5)
#else

__MTLK_FLOG void
__ILOG3_DDHPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5);

#define ILOG3_DDHPD(fmt, d1, d2, h3, p4, d5) \
  __ILOG3_DDHPD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_P(fmt, p1)
#else

__MTLK_FLOG void
__ILOG3_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1);

#define ILOG3_P(fmt, p1) \
  __ILOG3_P_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDHPDD(fmt, d1, d2, h3, p4, d5, d6)
#else

__MTLK_FLOG void
__ILOG3_DDHPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int64 h3, const void * p4, int32 d5, int32 d6);

#define ILOG3_DDHPDD(fmt, d1, d2, h3, p4, d5, d6) \
  __ILOG3_DDHPDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int64) (h3), (const void *) (p4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_PD(fmt, p1, d2)
#else

__MTLK_FLOG void
__ILOG3_PD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2);

#define ILOG3_PD(fmt, p1, d2) \
  __ILOG3_PD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG0_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG0_S(fmt, s1) \
  __ILOG0_S_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SPDPDPDD(fmt, s1, p2, d3, p4, d5, p6, d7, d8)
#else

__MTLK_FLOG void
__ILOG0_SPDPDPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * p2, int32 d3, const void * p4, int32 d5, const void * p6, int32 d7, int32 d8);

#define ILOG0_SPDPDPDD(fmt, s1, p2, d3, p4, d5, p6, d7, d8) \
  __ILOG0_SPDPDPDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (p2), (int32) (d3), (const void *) (p4), (int32) (d5), (const void *) (p6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SDDDD(fmt, s1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG0_SDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG0_SDDDD(fmt, s1, d2, d3, d4, d5) \
  __ILOG0_SDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDDDDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10)
#else

__MTLK_FLOG void
__ILOG2_DDDDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9, int32 d10);

#define ILOG2_DDDDDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10) \
  __ILOG2_DDDDDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDDYDDD(fmt, d1, d2, d3, d4, d5, y6, d7, d8, d9)
#else

__MTLK_FLOG void
__ELOG_DDDDDYDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, const void * y6, int32 d7, int32 d8, int32 d9);

#define ELOG_DDDDDYDDD(fmt, d1, d2, d3, d4, d5, y6, d7, d8, d9) \
  __ELOG_DDDDDYDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const void *) (y6), (int32) (d7), (int32) (d8), (int32) (d9))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDDYDD(fmt, d1, d2, d3, d4, d5, y6, d7, d8)
#else

__MTLK_FLOG void
__ELOG_DDDDDYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, const void * y6, int32 d7, int32 d8);

#define ELOG_DDDDDYDD(fmt, d1, d2, d3, d4, d5, y6, d7, d8) \
  __ELOG_DDDDDYDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const void *) (y6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_Y(fmt, y1)
#else

__MTLK_FLOG void
__ILOG4_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1);

#define ILOG4_Y(fmt, y1) \
  __ILOG4_Y_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSDS(fmt, d1, s2, d3, s4)
#else

__MTLK_FLOG void
__ILOG0_DSDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, const char * s4);

#define ILOG0_DSDS(fmt, d1, s2, d3, s4) \
  __ILOG0_DSDS_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (const char *) (s4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DY(fmt, d1, y2)
#else

__MTLK_FLOG void
__WLOG_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2);

#define WLOG_DY(fmt, d1, y2) \
  __WLOG_DY_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDDDDD(fmt, d1, d2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ILOG2_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ILOG2_DDDDDD(fmt, d1, d2, d3, d4, d5, d6) \
  __ILOG2_DDDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDDDSDDD(fmt, d1, d2, d3, d4, s5, d6, d7, d8)
#else

__MTLK_FLOG void
__ILOG1_DDDDSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5, int32 d6, int32 d7, int32 d8);

#define ILOG1_DDDDSDDD(fmt, d1, d2, d3, d4, s5, d6, d7, d8) \
  __ILOG1_DDDDSDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5), (int32) (d6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_SDPPDD(fmt, s1, d2, p3, p4, d5, d6)
#else

__MTLK_FLOG void
__ILOG3_SDPPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const void * p3, const void * p4, int32 d5, int32 d6);

#define ILOG3_SDPPDD(fmt, s1, d2, p3, p4, d5, d6) \
  __ILOG3_SDPPDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (const void *) (p3), (const void *) (p4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDY(fmt, d1, d2, y3)
#else

__MTLK_FLOG void
__ILOG1_DDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3);

#define ILOG1_DDY(fmt, d1, d2, y3) \
  __ILOG1_DDY_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DYSD(fmt, d1, y2, s3, d4)
#else

__MTLK_FLOG void
__ELOG_DYSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const char * s3, int32 d4);

#define ELOG_DYSD(fmt, d1, y2, s3, d4) \
  __ELOG_DYSD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (const char *) (s3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DY(fmt, d1, y2)
#else

__MTLK_FLOG void
__ELOG_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2);

#define ELOG_DY(fmt, d1, y2) \
  __ELOG_DY_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DY(fmt, d1, y2)
#else

__MTLK_FLOG void
__ILOG1_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2);

#define ILOG1_DY(fmt, d1, y2) \
  __ILOG1_DY_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DY(fmt, d1, y2)
#else

__MTLK_FLOG void
__ILOG2_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2);

#define ILOG2_DY(fmt, d1, y2) \
  __ILOG2_DY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DY(fmt, d1, y2)
#else

__MTLK_FLOG void
__ILOG3_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2);

#define ILOG3_DY(fmt, d1, y2) \
  __ILOG3_DY_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDDDD(fmt, d1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG1_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG1_DDDDD(fmt, d1, d2, d3, d4, d5) \
  __ILOG1_DDDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDDDDDS(fmt, d1, d2, d3, d4, d5, d6, s7)
#else

__MTLK_FLOG void
__ILOG2_DDDDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, const char * s7);

#define ILOG2_DDDDDDS(fmt, d1, d2, d3, d4, d5, d6, s7) \
  __ILOG2_DDDDDDS_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (const char *) (s7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DPD(fmt, d1, p2, d3)
#else

__MTLK_FLOG void
__ELOG_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3);

#define ELOG_DPD(fmt, d1, p2, d3) \
  __ELOG_DPD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DSY(fmt, d1, s2, y3)
#else

__MTLK_FLOG void
__ILOG3_DSY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, const void * y3);

#define ILOG3_DSY(fmt, d1, s2, y3) \
  __ILOG3_DSY_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_K(fmt, k1)
#else

__MTLK_FLOG void
__ILOG2_K_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1);

#define ILOG2_K(fmt, k1) \
  __ILOG2_K_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (k1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 5)
#define ILOG5_V(fmt)
#else

__MTLK_FLOG void
__ILOG5_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ILOG5_V(fmt) \
  __ILOG5_V_8(LOG_CONSOLE_TEXT_INFO, 5, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_Y(fmt, y1)
#else

__MTLK_FLOG void
__ILOG1_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1);

#define ILOG1_Y(fmt, y1) \
  __ILOG1_Y_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_K(fmt, k1)
#else

__MTLK_FLOG void
__ILOG1_K_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1);

#define ILOG1_K(fmt, k1) \
  __ILOG1_K_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (k1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_KY(fmt, k1, y2)
#else

__MTLK_FLOG void
__ILOG1_KY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * y2);

#define ILOG1_KY(fmt, k1, y2) \
  __ILOG1_KY_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (k1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DKK(fmt, d1, k2, k3)
#else

__MTLK_FLOG void
__ILOG1_DKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3);

#define ILOG1_DKK(fmt, d1, k2, k3) \
  __ILOG1_DKK_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (k2), (const void *) (k3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DYD(fmt, d1, y2, d3)
#else

__MTLK_FLOG void
__ELOG_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3);

#define ELOG_DYD(fmt, d1, y2, d3) \
  __ELOG_DYD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DK(fmt, d1, k2)
#else

__MTLK_FLOG void
__ILOG3_DK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2);

#define ILOG3_DK(fmt, d1, k2) \
  __ILOG3_DK_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (k2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DKK(fmt, d1, k2, k3)
#else

__MTLK_FLOG void
__ILOG3_DKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3);

#define ILOG3_DKK(fmt, d1, k2, k3) \
  __ILOG3_DKK_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (k2), (const void *) (k3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DKKD(fmt, d1, k2, k3, d4)
#else

__MTLK_FLOG void
__ILOG3_DKKD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3, int32 d4);

#define ILOG3_DKKD(fmt, d1, k2, k3, d4) \
  __ILOG3_DKKD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (k2), (const void *) (k3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 5)
#define ILOG5_KK(fmt, k1, k2)
#else

__MTLK_FLOG void
__ILOG5_KK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * k2);

#define ILOG5_KK(fmt, k1, k2) \
  __ILOG5_KK_8(LOG_CONSOLE_TEXT_INFO, 5, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (k1), (const void *) (k2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 5 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DKK(fmt, d1, k2, k3)
#else

__MTLK_FLOG void
__ILOG2_DKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, const void * k3);

#define ILOG2_DKK(fmt, d1, k2, k3) \
  __ILOG2_DKK_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (k2), (const void *) (k3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DKD(fmt, d1, k2, d3)
#else

__MTLK_FLOG void
__ILOG1_DKD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2, int32 d3);

#define ILOG1_DKD(fmt, d1, k2, d3) \
  __ILOG1_DKD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (k2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_KKD(fmt, k1, k2, d3)
#else

__MTLK_FLOG void
__ILOG1_KKD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * k1, const void * k2, int32 d3);

#define ILOG1_KKD(fmt, k1, k2, d3) \
  __ILOG1_KKD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (k1), (const void *) (k2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_V(fmt)
#else

__MTLK_FLOG void
__ILOG4_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ILOG4_V(fmt) \
  __ILOG4_V_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_P(fmt, p1)
#else

__MTLK_FLOG void
__ILOG4_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1);

#define ILOG4_P(fmt, p1) \
  __ILOG4_P_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SSD(fmt, s1, s2, d3)
#else

__MTLK_FLOG void
__ILOG1_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3);

#define ILOG1_SSD(fmt, s1, s2, d3) \
  __ILOG1_SSD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG2_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG2_S(fmt, s1) \
  __ILOG2_S_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SS(fmt, s1, s2)
#else

__MTLK_FLOG void
__ILOG2_SS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2);

#define ILOG2_SS(fmt, s1, s2) \
  __ILOG2_SS_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DSD(fmt, d1, s2, d3)
#else

__MTLK_FLOG void
__ELOG_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3);

#define ELOG_DSD(fmt, d1, s2, d3) \
  __ELOG_DSD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SDDD(fmt, s1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG1_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4);

#define ILOG1_SDDD(fmt, s1, d2, d3, d4) \
  __ILOG1_SDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_YY(fmt, y1, y2)
#else

__MTLK_FLOG void
__ILOG1_YY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, const void * y2);

#define ILOG1_YY(fmt, y1, y2) \
  __ILOG1_YY_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DSDDD(fmt, d1, s2, d3, d4, d5)
#else

__MTLK_FLOG void
__ELOG_DSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5);

#define ELOG_DSDDD(fmt, d1, s2, d3, d4, d5) \
  __ELOG_DSDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDSDD(fmt, d1, d2, s3, d4, d5)
#else

__MTLK_FLOG void
__ILOG2_DDSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4, int32 d5);

#define ILOG2_DDSDD(fmt, d1, d2, s3, d4, d5) \
  __ILOG2_DDSDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDSD(fmt, d1, d2, s3, d4)
#else

__MTLK_FLOG void
__ILOG3_DDSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4);

#define ILOG3_DDSD(fmt, d1, d2, s3, d4) \
  __ILOG3_DDSD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ILOG0_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ILOG0_SD(fmt, s1, d2) \
  __ILOG0_SD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_SSD(fmt, s1, s2, d3)
#else

__MTLK_FLOG void
__ILOG3_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3);

#define ILOG3_SSD(fmt, s1, s2, d3) \
  __ILOG3_SSD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG4_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define ILOG4_DDDD(fmt, d1, d2, d3, d4) \
  __ILOG4_DDDD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_PDPD(fmt, p1, d2, p3, d4)
#else

__MTLK_FLOG void
__ILOG2_PDPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, const void * p3, int32 d4);

#define ILOG2_PDPD(fmt, p1, d2, p3, d4) \
  __ILOG2_PDPD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2), (const void *) (p3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SDSD(fmt, s1, d2, s3, d4)
#else

__MTLK_FLOG void
__ILOG1_SDSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const char * s3, int32 d4);

#define ILOG1_SDSD(fmt, s1, d2, s3, d4) \
  __ILOG1_SDSD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (const char *) (s3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SK(fmt, s1, k2)
#else

__MTLK_FLOG void
__ILOG1_SK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * k2);

#define ILOG1_SK(fmt, s1, k2) \
  __ILOG1_SK_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (k2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ILOG2_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ILOG2_SD(fmt, s1, d2) \
  __ILOG2_SD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG3_S_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG3_S(fmt, s1) \
  __ILOG3_S_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SDS(fmt, s1, d2, s3)
#else

__MTLK_FLOG void
__ILOG2_SDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const char * s3);

#define ILOG2_SDS(fmt, s1, d2, s3) \
  __ILOG2_SDS_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DDS(fmt, d1, d2, s3)
#else

__MTLK_FLOG void
__ILOG0_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3);

#define ILOG0_DDS(fmt, d1, d2, s3) \
  __ILOG0_DDS_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DDDD(fmt, d1, d2, d3, d4)
#else

__MTLK_FLOG void
__WLOG_DDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4);

#define WLOG_DDDD(fmt, d1, d2, d3, d4) \
  __WLOG_DDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_SSS(fmt, s1, s2, s3)
#else

__MTLK_FLOG void
__ILOG3_SSS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const char * s3);

#define ILOG3_SSS(fmt, s1, s2, s3) \
  __ILOG3_SSS_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_SSS(fmt, s1, s2, s3)
#else

__MTLK_FLOG void
__RLOG_SSS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const char * s3);

#define RLOG_SSS(fmt, s1, s2, s3) \
  __RLOG_SSS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DK(fmt, d1, k2)
#else

__MTLK_FLOG void
__ILOG4_DK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * k2);

#define ILOG4_DK(fmt, d1, k2) \
  __ILOG4_DK_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (k2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DYDY(fmt, d1, y2, d3, y4)
#else

__MTLK_FLOG void
__ILOG2_DYDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3, const void * y4);

#define ILOG2_DYDY(fmt, d1, y2, d3, y4) \
  __ILOG2_DYDY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (int32) (d3), (const void *) (y4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DYY(fmt, d1, y2, y3)
#else

__MTLK_FLOG void
__ILOG4_DYY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const void * y3);

#define ILOG4_DYY(fmt, d1, y2, y3) \
  __ILOG4_DYY_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DY(fmt, d1, y2)
#else

__MTLK_FLOG void
__ILOG0_DY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2);

#define ILOG0_DY(fmt, d1, y2) \
  __ILOG0_DY_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SDDDS(fmt, s1, d2, d3, d4, s5)
#else

__MTLK_FLOG void
__ILOG1_SDDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, const char * s5);

#define ILOG1_SDDDS(fmt, s1, d2, d3, d4, s5) \
  __ILOG1_SDDDS_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDYD(fmt, d1, d2, y3, d4)
#else

__MTLK_FLOG void
__ILOG1_DDYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3, int32 d4);

#define ILOG1_DDYD(fmt, d1, d2, y3, d4) \
  __ILOG1_DDYD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (y3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDDYD(fmt, d1, d2, d3, y4, d5)
#else

__MTLK_FLOG void
__ILOG3_DDDYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, const void * y4, int32 d5);

#define ILOG3_DDDYD(fmt, d1, d2, d3, y4, d5) \
  __ILOG3_DDDYD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (const void *) (y4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DDDDDD(fmt, d1, d2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ILOG4_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ILOG4_DDDDDD(fmt, d1, d2, d3, d4, d5, d6) \
  __ILOG4_DDDDDD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDD(fmt, d1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ELOG_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ELOG_DDDDD(fmt, d1, d2, d3, d4, d5) \
  __ELOG_DDDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DS(fmt, d1, s2)
#else

__MTLK_FLOG void
__ILOG2_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2);

#define ILOG2_DS(fmt, d1, s2) \
  __ILOG2_DS_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDY(fmt, d1, d2, y3)
#else

__MTLK_FLOG void
__ILOG2_DDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3);

#define ILOG2_DDY(fmt, d1, d2, y3) \
  __ILOG2_DDY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DSDDS(fmt, d1, s2, d3, d4, s5)
#else

__MTLK_FLOG void
__ILOG1_DSDDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, const char * s5);

#define ILOG1_DSDDS(fmt, d1, s2, d3, d4, s5) \
  __ILOG1_DSDDS_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (const char *) (s5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_SDDDD(fmt, s1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG4_SDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG4_SDDDD(fmt, s1, d2, d3, d4, d5) \
  __ILOG4_SDDDD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SDDDD(fmt, s1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG2_SDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG2_SDDDD(fmt, s1, d2, d3, d4, d5) \
  __ILOG2_SDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSD(fmt, d1, s2, d3)
#else

__MTLK_FLOG void
__ILOG0_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3);

#define ILOG0_DSD(fmt, d1, s2, d3) \
  __ILOG0_DSD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDSDY(fmt, d1, d2, s3, d4, y5)
#else

__MTLK_FLOG void
__ILOG1_DDSDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4, const void * y5);

#define ILOG1_DDSDY(fmt, d1, d2, s3, d4, y5) \
  __ILOG1_DDSDY_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4), (const void *) (y5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DYS(fmt, d1, y2, s3)
#else

__MTLK_FLOG void
__WLOG_DYS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const char * s3);

#define WLOG_DYS(fmt, d1, y2, s3) \
  __WLOG_DYS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSY(fmt, d1, s2, y3)
#else

__MTLK_FLOG void
__ILOG0_DSY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, const void * y3);

#define ILOG0_DSY(fmt, d1, s2, y3) \
  __ILOG0_DSY_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DSY(fmt, d1, s2, y3)
#else

__MTLK_FLOG void
__ILOG2_DSY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, const void * y3);

#define ILOG2_DSY(fmt, d1, s2, y3) \
  __ILOG2_DSY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DYY(fmt, d1, y2, y3)
#else

__MTLK_FLOG void
__ILOG2_DYY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, const void * y3);

#define ILOG2_DYY(fmt, d1, y2, y3) \
  __ILOG2_DYY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (const void *) (y3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDYY(fmt, d1, d2, y3, y4)
#else

__MTLK_FLOG void
__ILOG2_DDYY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3, const void * y4);

#define ILOG2_DDYY(fmt, d1, d2, y3, y4) \
  __ILOG2_DDYY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (y3), (const void *) (y4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DYD(fmt, d1, y2, d3)
#else

__MTLK_FLOG void
__ILOG2_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3);

#define ILOG2_DYD(fmt, d1, y2, d3) \
  __ILOG2_DYD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDYD(fmt, d1, d2, y3, d4)
#else

__MTLK_FLOG void
__ILOG2_DDYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * y3, int32 d4);

#define ILOG2_DDYD(fmt, d1, d2, y3, d4) \
  __ILOG2_DDYD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (y3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_YDDDDDD(fmt, y1, d2, d3, d4, d5, d6, d7)
#else

__MTLK_FLOG void
__ILOG3_YDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7);

#define ILOG3_YDDDDDD(fmt, y1, d2, d3, d4, d5, d6, d7) \
  __ILOG3_YDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DYD(fmt, d1, y2, d3)
#else

__MTLK_FLOG void
__WLOG_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3);

#define WLOG_DYD(fmt, d1, y2, d3) \
  __WLOG_DYD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DYD(fmt, d1, y2, d3)
#else

__MTLK_FLOG void
__ILOG1_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3);

#define ILOG1_DYD(fmt, d1, y2, d3) \
  __ILOG1_DYD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 9)
#define ILOG9_V(fmt)
#else

__MTLK_FLOG void
__ILOG9_V_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ILOG9_V(fmt) \
  __ILOG9_V_8(LOG_CONSOLE_TEXT_INFO, 9, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 9 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SDDD(fmt, s1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG0_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4);

#define ILOG0_SDDD(fmt, s1, d2, d3, d4) \
  __ILOG0_SDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_YDDD(fmt, y1, d2, d3, d4)
#else

__MTLK_FLOG void
__ELOG_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4);

#define ELOG_YDDD(fmt, y1, d2, d3, d4) \
  __ELOG_YDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_HHD(fmt, h1, h2, d3)
#else

__MTLK_FLOG void
__ELOG_HHD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1, int64 h2, int32 d3);

#define ELOG_HHD(fmt, h1, h2, d3) \
  __ELOG_HHD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int64) (h1), (int64) (h2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DS(fmt, d1, s2)
#else

__MTLK_FLOG void
__WLOG_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2);

#define WLOG_DS(fmt, d1, s2) \
  __WLOG_DS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDS(fmt, d1, d2, s3)
#else

__MTLK_FLOG void
__ILOG1_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3);

#define ILOG1_DDS(fmt, d1, d2, s3) \
  __ILOG1_DDS_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DSD(fmt, d1, s2, d3)
#else

__MTLK_FLOG void
__ILOG1_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3);

#define ILOG1_DSD(fmt, d1, s2, d3) \
  __ILOG1_DSD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDS(fmt, d1, d2, s3)
#else

__MTLK_FLOG void
__ELOG_DDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3);

#define ELOG_DDS(fmt, d1, d2, s3) \
  __ELOG_DDS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_YD(fmt, y1, d2)
#else

__MTLK_FLOG void
__ILOG1_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2);

#define ILOG1_YD(fmt, y1, d2) \
  __ILOG1_YD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SDS(fmt, s1, d2, s3)
#else

__MTLK_FLOG void
__ILOG0_SDS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const char * s3);

#define ILOG0_SDS(fmt, s1, d2, s3) \
  __ILOG0_SDS_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (const char *) (s3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DYDD(fmt, d1, y2, d3, d4)
#else

__MTLK_FLOG void
__ILOG0_DYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3, int32 d4);

#define ILOG0_DYDD(fmt, d1, y2, d3, d4) \
  __ILOG0_DYDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_SDDD(fmt, s1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG3_SDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4);

#define ILOG3_SDDD(fmt, s1, d2, d3, d4) \
  __ILOG3_SDDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_H(fmt, h1)
#else

__MTLK_FLOG void
__ILOG2_H_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1);

#define ILOG2_H(fmt, h1) \
  __ILOG2_H_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int64) (h1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DH(fmt, d1, h2)
#else

__MTLK_FLOG void
__ILOG2_DH_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int64 h2);

#define ILOG2_DH(fmt, d1, h2) \
  __ILOG2_DH_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int64) (h2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_PPPP(fmt, p1, p2, p3, p4)
#else

__MTLK_FLOG void
__ILOG2_PPPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, const void * p3, const void * p4);

#define ILOG2_PPPP(fmt, p1, p2, p3, p4) \
  __ILOG2_PPPP_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2), (const void *) (p3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__RLOG_SD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define RLOG_SD(fmt, s1, d2) \
  __RLOG_SD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_PPPPD(fmt, p1, p2, p3, p4, d5)
#else

__MTLK_FLOG void
__ILOG1_PPPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, const void * p3, const void * p4, int32 d5);

#define ILOG1_PPPPD(fmt, p1, p2, p3, p4, d5) \
  __ILOG1_PPPPD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2), (const void *) (p3), (const void *) (p4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SDDDDSDDDDD(fmt, s1, d2, d3, d4, d5, s6, d7, d8, d9, d10, d11)
#else

__MTLK_FLOG void
__ILOG1_SDDDDSDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5, const char * s6, int32 d7, int32 d8, int32 d9, int32 d10, int32 d11);

#define ILOG1_SDDDDSDDDDD(fmt, s1, d2, d3, d4, d5, s6, d7, d8, d9, d10, d11) \
  __ILOG1_SDDDDSDDDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (const char *) (s6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10), (int32) (d11))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SY(fmt, s1, y2)
#else

__MTLK_FLOG void
__ILOG0_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2);

#define ILOG0_SY(fmt, s1, y2) \
  __ILOG0_SY_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DYD(fmt, d1, y2, d3)
#else

__MTLK_FLOG void
__ILOG3_DYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * y2, int32 d3);

#define ILOG3_DYD(fmt, d1, y2, d3) \
  __ILOG3_DYD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (y2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_Y(fmt, y1)
#else

__MTLK_FLOG void
__ILOG0_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1);

#define ILOG0_Y(fmt, y1) \
  __ILOG0_Y_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_Y(fmt, y1)
#else

__MTLK_FLOG void
__WLOG_Y_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1);

#define WLOG_Y(fmt, y1) \
  __WLOG_Y_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DSD(fmt, d1, s2, d3)
#else

__MTLK_FLOG void
__WLOG_DSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3);

#define WLOG_DSD(fmt, d1, s2, d3) \
  __WLOG_DSD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DSDD(fmt, d1, s2, d3, d4)
#else

__MTLK_FLOG void
__ILOG1_DSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4);

#define ILOG1_DSDD(fmt, d1, s2, d3, d4) \
  __ILOG1_DSDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DSDDDDDDDD(fmt, d1, s2, d3, d4, d5, d6, d7, d8, d9, d10)
#else

__MTLK_FLOG void
__ILOG0_DSDDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9, int32 d10);

#define ILOG0_DSDDDDDDDD(fmt, d1, s2, d3, d4, d5, d6, d7, d8, d9, d10) \
  __ILOG0_DSDDDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ILOG4_DDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ILOG4_DDD(fmt, d1, d2, d3) \
  __ILOG4_DDD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYDDDDDDDD(fmt, s1, s2, y3, y4, d5, d6, d7, d8, d9, d10, d11, d12)
#else

__MTLK_FLOG void
__ILOG2_SSYYDDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6, int32 d7, int32 d8, int32 d9, int32 d10, int32 d11, int32 d12);

#define ILOG2_SSYYDDDDDDDD(fmt, s1, s2, y3, y4, d5, d6, d7, d8, d9, d10, d11, d12) \
  __ILOG2_SSYYDDDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9), (int32) (d10), (int32) (d11), (int32) (d12))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYDDDDY(fmt, s1, s2, y3, y4, d5, d6, d7, d8, y9)
#else

__MTLK_FLOG void
__ILOG2_SSYYDDDDY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6, int32 d7, int32 d8, const void * y9);

#define ILOG2_SSYYDDDDY(fmt, s1, s2, y3, y4, d5, d6, d7, d8, y9) \
  __ILOG2_SSYYDDDDY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8), (const void *) (y9))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYDDDD(fmt, s1, s2, y3, y4, d5, d6, d7, d8)
#else

__MTLK_FLOG void
__ILOG2_SSYYDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6, int32 d7, int32 d8);

#define ILOG2_SSYYDDDD(fmt, s1, s2, y3, y4, d5, d6, d7, d8) \
  __ILOG2_SSYYDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYSDDDD(fmt, s1, s2, y3, y4, s5, d6, d7, d8, d9)
#else

__MTLK_FLOG void
__ILOG2_SSYYSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, const char * s5, int32 d6, int32 d7, int32 d8, int32 d9);

#define ILOG2_SSYYSDDDD(fmt, s1, s2, y3, y4, s5, d6, d7, d8, d9) \
  __ILOG2_SSYYSDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (const char *) (s5), (int32) (d6), (int32) (d7), (int32) (d8), (int32) (d9))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYDD(fmt, s1, s2, y3, y4, d5, d6)
#else

__MTLK_FLOG void
__ILOG2_SSYYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5, int32 d6);

#define ILOG2_SSYYDD(fmt, s1, s2, y3, y4, d5, d6) \
  __ILOG2_SSYYDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYD(fmt, s1, s2, y3, y4, d5)
#else

__MTLK_FLOG void
__ILOG2_SSYYD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, int32 d5);

#define ILOG2_SSYYD(fmt, s1, s2, y3, y4, d5) \
  __ILOG2_SSYYD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYS(fmt, s1, s2, y3, y4, s5)
#else

__MTLK_FLOG void
__ILOG2_SSYYS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, const char * s5);

#define ILOG2_SSYYS(fmt, s1, s2, y3, y4, s5) \
  __ILOG2_SSYYS_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (const char *) (s5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSYYKK(fmt, s1, s2, y3, y4, k5, k6)
#else

__MTLK_FLOG void
__ILOG2_SSYYKK_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * y3, const void * y4, const void * k5, const void * k6);

#define ILOG2_SSYYKK(fmt, s1, s2, y3, y4, k5, k6) \
  __ILOG2_SSYYKK_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (y3), (const void *) (y4), (const void *) (k5), (const void *) (k6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_PHHD(fmt, p1, h2, h3, d4)
#else

__MTLK_FLOG void
__ILOG3_PHHD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int64 h2, int64 h3, int32 d4);

#define ILOG3_PHHD(fmt, p1, h2, h3, d4) \
  __ILOG3_PHHD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int64) (h2), (int64) (h3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_YDDDDDDD(fmt, y1, d2, d3, d4, d5, d6, d7, d8)
#else

__MTLK_FLOG void
__ILOG1_YDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8);

#define ILOG1_YDDDDDDD(fmt, y1, d2, d3, d4, d5, d6, d7, d8) \
  __ILOG1_YDDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_YDD(fmt, y1, d2, d3)
#else

__MTLK_FLOG void
__ILOG3_YDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3);

#define ILOG3_YDD(fmt, y1, d2, d3) \
  __ILOG3_YDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_PY(fmt, p1, y2)
#else

__MTLK_FLOG void
__ILOG1_PY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * y2);

#define ILOG1_PY(fmt, p1, y2) \
  __ILOG1_PY_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_PY(fmt, p1, y2)
#else

__MTLK_FLOG void
__ILOG3_PY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * y2);

#define ILOG3_PY(fmt, p1, y2) \
  __ILOG3_PY_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DP(fmt, d1, p2)
#else

__MTLK_FLOG void
__ILOG1_DP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2);

#define ILOG1_DP(fmt, d1, p2) \
  __ILOG1_DP_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DPPD(fmt, d1, p2, p3, d4)
#else

__MTLK_FLOG void
__ILOG2_DPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, int32 d4);

#define ILOG2_DPPD(fmt, d1, p2, p3, d4) \
  __ILOG2_DPPD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (const void *) (p3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 6)
#define ILOG6_DDDDP(fmt, d1, d2, d3, d4, p5)
#else

__MTLK_FLOG void
__ILOG6_DDDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const void * p5);

#define ILOG6_DDDDP(fmt, d1, d2, d3, d4, p5) \
  __ILOG6_DDDDP_8(LOG_CONSOLE_TEXT_INFO, 6, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const void *) (p5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 6)
#define ILOG6_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG6_D_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG6_D(fmt, d1) \
  __ILOG6_D_8(LOG_CONSOLE_TEXT_INFO, 6, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 6 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DPDP(fmt, d1, p2, d3, p4)
#else

__MTLK_FLOG void
__ILOG1_DPDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3, const void * p4);

#define ILOG1_DPDP(fmt, d1, p2, d3, p4) \
  __ILOG1_DPDP_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_DS(fmt, d1, s2)
#else

__MTLK_FLOG void
__RLOG_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2);

#define RLOG_DS(fmt, d1, s2) \
  __RLOG_DS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_DDDDD(fmt, d1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__RLOG_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5);

#define RLOG_DDDDD(fmt, d1, d2, d3, d4, d5) \
  __RLOG_DDDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DDDDDD(fmt, d1, d2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__WLOG_DDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6);

#define WLOG_DDDDDD(fmt, d1, d2, d3, d4, d5, d6) \
  __WLOG_DDDDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_PPD(fmt, p1, p2, d3)
#else

__MTLK_FLOG void
__ILOG3_PPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2, int32 d3);

#define ILOG3_PPD(fmt, p1, p2, d3) \
  __ILOG3_PPD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_DDPDD(fmt, d1, d2, p3, d4, d5)
#else

__MTLK_FLOG void
__ILOG3_DDPDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const void * p3, int32 d4, int32 d5);

#define ILOG3_DDPDD(fmt, d1, d2, p3, d4, d5) \
  __ILOG3_DDPDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const void *) (p3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_PDDDD(fmt, p1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG2_PDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3, int32 d4, int32 d5);

#define ILOG2_PDDDD(fmt, p1, d2, d3, d4, d5) \
  __ILOG2_PDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_CCDD(fmt, c1, c2, d3, d4)
#else

__MTLK_FLOG void
__ILOG1_CCDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int8 c1, int8 c2, int32 d3, int32 d4);

#define ILOG1_CCDD(fmt, c1, c2, d3, d4) \
  __ILOG1_CCDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int8) (c1), (int8) (c2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SDDDDD(fmt, s1, d2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ELOG_SDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ELOG_SDDDDD(fmt, s1, d2, d3, d4, d5, d6) \
  __ELOG_SDDDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_PP(fmt, p1, p2)
#else

__MTLK_FLOG void
__ELOG_PP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2);

#define ELOG_PP(fmt, p1, p2) \
  __ELOG_PP_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_PP(fmt, p1, p2)
#else

__MTLK_FLOG void
__ILOG3_PP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2);

#define ILOG3_PP(fmt, p1, p2) \
  __ILOG3_PP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SDDDP(fmt, s1, d2, d3, d4, p5)
#else

__MTLK_FLOG void
__ILOG1_SDDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4, const void * p5);

#define ILOG1_SDDDP(fmt, s1, d2, d3, d4, p5) \
  __ILOG1_SDDDP_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4), (const void *) (p5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DPPD(fmt, d1, p2, p3, d4)
#else

__MTLK_FLOG void
__ILOG0_DPPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3, int32 d4);

#define ILOG0_DPPD(fmt, d1, p2, p3, d4) \
  __ILOG0_DPPD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (const void *) (p3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_DDDDD(fmt, d1, d2, d3, d4, d5)
#else

__MTLK_FLOG void
__WLOG_DDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5);

#define WLOG_DDDDD(fmt, d1, d2, d3, d4, d5) \
  __WLOG_DDDDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7, d8)
#else

__MTLK_FLOG void
__ILOG1_DDDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7, int32 d8);

#define ILOG1_DDDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7, d8) \
  __ILOG1_DDDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7), (int32) (d8))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_HHDD(fmt, h1, h2, d3, d4)
#else

__MTLK_FLOG void
__ILOG3_HHDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int64 h1, int64 h2, int32 d3, int32 d4);

#define ILOG3_HHDD(fmt, h1, h2, d3, d4) \
  __ILOG3_HHDD_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int64) (h1), (int64) (h2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_DS(fmt, d1, s2)
#else

__MTLK_FLOG void
__ILOG4_DS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const char * s2);

#define ILOG4_DS(fmt, d1, s2) \
  __ILOG4_DS_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_YD(fmt, y1, d2)
#else

__MTLK_FLOG void
__ILOG4_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2);

#define ILOG4_YD(fmt, y1, d2) \
  __ILOG4_YD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_YDDD(fmt, y1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG4_YDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2, int32 d3, int32 d4);

#define ILOG4_YDDD(fmt, y1, d2, d3, d4) \
  __ILOG4_YDDD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DPD(fmt, d1, p2, d3)
#else

__MTLK_FLOG void
__ILOG2_DPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, int32 d3);

#define ILOG2_DPD(fmt, d1, p2, d3) \
  __ILOG2_DPD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 3)
#define ILOG3_SDP(fmt, s1, d2, p3)
#else

__MTLK_FLOG void
__ILOG3_SDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, const void * p3);

#define ILOG3_SDP(fmt, s1, d2, p3) \
  __ILOG3_SDP_8(LOG_CONSOLE_TEXT_INFO, 3, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 3 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_PDD(fmt, p1, d2, d3)
#else

__MTLK_FLOG void
__ILOG4_PDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, int32 d2, int32 d3);

#define ILOG4_PDD(fmt, p1, d2, d3) \
  __ILOG4_PDD_8(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SSDDDDD(fmt, s1, s2, d3, d4, d5, d6, d7)
#else

__MTLK_FLOG void
__ILOG0_SSDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7);

#define ILOG0_SSDDDDD(fmt, s1, s2, d3, d4, d5, d6, d7) \
  __ILOG0_SSDDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SSDDDD(fmt, s1, s2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ILOG1_SSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ILOG1_SSDDDD(fmt, s1, s2, d3, d4, d5, d6) \
  __ILOG1_SSDDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SSDDDD(fmt, s1, s2, d3, d4, d5, d6)
#else

__MTLK_FLOG void
__ILOG0_SSDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5, int32 d6);

#define ILOG0_SSDDDD(fmt, s1, s2, d3, d4, d5, d6) \
  __ILOG0_SSDDDD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_SY(fmt, s1, y2)
#else

__MTLK_FLOG void
__RLOG_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2);

#define RLOG_SY(fmt, s1, y2) \
  __RLOG_SY_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SY(fmt, s1, y2)
#else

__MTLK_FLOG void
__ILOG2_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2);

#define ILOG2_SY(fmt, s1, y2) \
  __ILOG2_SY_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SYDD(fmt, s1, y2, d3, d4)
#else

__MTLK_FLOG void
__ILOG1_SYDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2, int32 d3, int32 d4);

#define ILOG1_SYDD(fmt, s1, y2, d3, d4) \
  __ILOG1_SYDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (y2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SY(fmt, s1, y2)
#else

__MTLK_FLOG void
__ELOG_SY_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const void * y2);

#define ELOG_SY(fmt, s1, y2) \
  __ELOG_SY_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const void *) (y2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7)
#else

__MTLK_FLOG void
__ILOG2_DDDDDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, int32 d5, int32 d6, int32 d7);

#define ILOG2_DDDDDDD(fmt, d1, d2, d3, d4, d5, d6, d7) \
  __ILOG2_DDDDDDD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (int32) (d5), (int32) (d6), (int32) (d7))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SSD(fmt, s1, s2, d3)
#else

__MTLK_FLOG void
__ILOG0_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3);

#define ILOG0_SSD(fmt, s1, s2, d3) \
  __ILOG0_SSD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_SS(fmt, s1, s2)
#else

__MTLK_FLOG void
__RLOG_SS_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2);

#define RLOG_SS(fmt, s1, s2) \
  __RLOG_SS_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL)
#define RLOG_SSDD(fmt, s1, s2, d3, d4)
#else

__MTLK_FLOG void
__RLOG_SSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4);

#define RLOG_SSDD(fmt, s1, s2, d3, d4) \
  __RLOG_SSDD_8(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_RELEASE_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_RELEASE_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SSDD(fmt, s1, s2, d3, d4)
#else

__MTLK_FLOG void
__ILOG1_SSDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4);

#define ILOG1_SSDD(fmt, s1, s2, d3, d4) \
  __ILOG1_SSDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SSDDD(fmt, s1, s2, d3, d4, d5)
#else

__MTLK_FLOG void
__ILOG1_SSDDD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, int32 d4, int32 d5);

#define ILOG1_SSDDD(fmt, s1, s2, d3, d4, d5) \
  __ILOG1_SSDDD_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3), (int32) (d4), (int32) (d5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_YD(fmt, y1, d2)
#else

__MTLK_FLOG void
__ILOG2_YD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * y1, int32 d2);

#define ILOG2_YD(fmt, y1, d2) \
  __ILOG2_YD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (y1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SSDPP(fmt, s1, s2, d3, p4, p5)
#else

__MTLK_FLOG void
__ILOG1_SSDPP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3, const void * p4, const void * p5);

#define ILOG1_SSDPP(fmt, s1, s2, d3, p4, p5) \
  __ILOG1_SSDPP_8(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3), (const void *) (p4), (const void *) (p5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SSD(fmt, s1, s2, d3)
#else

__MTLK_FLOG void
__ILOG2_SSD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, int32 d3);

#define ILOG2_SSD(fmt, s1, s2, d3) \
  __ILOG2_SSD_8(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SDDP(fmt, s1, d2, d3, p4)
#else

__MTLK_FLOG void
__ILOG0_SDDP_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, const void * p4);

#define ILOG0_SDDP(fmt, s1, d2, d3, p4) \
  __ILOG0_SDDP_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SSPD(fmt, s1, s2, p3, d4)
#else

__MTLK_FLOG void
__ILOG0_SSPD_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, const char * s2, const void * p3, int32 d4);

#define ILOG0_SSPD(fmt, s1, s2, p3, d4) \
  __ILOG0_SSPD_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (const char *) (s2), (const void *) (p3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_P(fmt, p1)
#else

__MTLK_FLOG void
__ILOG0_P_8(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1);

#define ILOG0_P(fmt, p1) \
  __ILOG0_P_8(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


