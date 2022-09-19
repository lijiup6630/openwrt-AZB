#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG4_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG4_S(fmt, s1) \
  __ILOG4_S_7(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ILOG4_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ILOG4_SD(fmt, s1, d2) \
  __ILOG4_SD_7(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 4)
#define ILOG4_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ILOG4_SDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ILOG4_SDD(fmt, s1, d2, d3) \
  __ILOG4_SDD_7(LOG_CONSOLE_TEXT_INFO, 4, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 4 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_S(fmt, s1)
#else

__MTLK_FLOG void
__WLOG_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define WLOG_S(fmt, s1) \
  __WLOG_S_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_S(fmt, s1)
#else

__MTLK_FLOG void
__ELOG_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ELOG_S(fmt, s1) \
  __ELOG_S_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SDDP(fmt, s1, d2, d3, p4)
#else

__MTLK_FLOG void
__ELOG_SDDP_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, const void * p4);

#define ELOG_SDDP(fmt, s1, d2, d3, p4) \
  __ELOG_SDDP_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (const void *) (p4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_D(fmt, d1)
#else

__MTLK_FLOG void
__ELOG_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ELOG_D(fmt, d1) \
  __ELOG_D_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_S(fmt, s1)
#else

__MTLK_FLOG void
__ILOG1_S_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1);

#define ILOG1_S(fmt, s1) \
  __ILOG1_S_7(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_V(fmt)
#else

__MTLK_FLOG void
__ELOG_V_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt);

#define ELOG_V(fmt) \
  __ELOG_V_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_C(fmt, c1)
#else

__MTLK_FLOG void
__ELOG_C_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int8 c1);

#define ELOG_C(fmt, c1) \
  __ELOG_C_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int8) (c1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG2_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG2_D(fmt, d1) \
  __ILOG2_D_7(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG1_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG1_D(fmt, d1) \
  __ILOG1_D_7(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ELOG_DDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ELOG_DDD(fmt, d1, d2, d3) \
  __ELOG_DDD_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL)
#define WLOG_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__WLOG_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define WLOG_SD(fmt, s1, d2) \
  __WLOG_SD_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_WARNING_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_WARNING_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ELOG_SDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ELOG_SDD(fmt, s1, d2, d3) \
  __ELOG_SDD_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ILOG1_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ILOG1_SD(fmt, s1, d2) \
  __ILOG1_SD_7(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDSDDD(fmt, d1, d2, s3, d4, d5, d6)
#else

__MTLK_FLOG void
__ELOG_DDSDDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, const char * s3, int32 d4, int32 d5, int32 d6);

#define ELOG_DDSDDD(fmt, d1, d2, s3, d4, d5, d6) \
  __ELOG_DDSDDD_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (const char *) (s3), (int32) (d4), (int32) (d5), (int32) (d6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_SDDD(fmt, s1, d2, d3, d4)
#else

__MTLK_FLOG void
__ILOG2_SDDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3, int32 d4);

#define ILOG2_SDDD(fmt, s1, d2, d3, d4) \
  __ILOG2_SDDD_7(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3), (int32) (d4))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG0_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG0_DD(fmt, d1, d2) \
  __ILOG0_DD_7(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_D(fmt, d1)
#else

__MTLK_FLOG void
__ILOG0_D_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1);

#define ILOG0_D(fmt, d1) \
  __ILOG0_D_7(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_SD(fmt, s1, d2)
#else

__MTLK_FLOG void
__ELOG_SD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2);

#define ELOG_SD(fmt, s1, d2) \
  __ELOG_SD_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 0)
#define ILOG0_SDD(fmt, s1, d2, d3)
#else

__MTLK_FLOG void
__ILOG0_SDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const char * s1, int32 d2, int32 d3);

#define ILOG0_SDD(fmt, s1, d2, d3) \
  __ILOG0_SDD_7(LOG_CONSOLE_TEXT_INFO, 0, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const char *) (s1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 0 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ELOG_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ELOG_DD(fmt, d1, d2) \
  __ELOG_DD_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DPP(fmt, d1, p2, p3)
#else

__MTLK_FLOG void
__ILOG2_DPP_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, const void * p2, const void * p3);

#define ILOG2_DPP(fmt, d1, p2, p3) \
  __ILOG2_DPP_7(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (const void *) (p2), (const void *) (p3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDS(fmt, d1, d2, d3, d4, s5)
#else

__MTLK_FLOG void
__ELOG_DDDDS_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5);

#define ELOG_DDDDS(fmt, d1, d2, d3, d4, s5) \
  __ELOG_DDDDS_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_DDDDSS(fmt, d1, d2, d3, d4, s5, s6)
#else

__MTLK_FLOG void
__ELOG_DDDDSS_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3, int32 d4, const char * s5, const char * s6);

#define ELOG_DDDDSS(fmt, d1, d2, d3, d4, s5, s6) \
  __ELOG_DDDDSS_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3), (int32) (d4), (const char *) (s5), (const char *) (s6))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 2)
#define ILOG2_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG2_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG2_DD(fmt, d1, d2) \
  __ILOG2_DD_7(LOG_CONSOLE_TEXT_INFO, 2, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 2 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DD(fmt, d1, d2)
#else

__MTLK_FLOG void
__ILOG1_DD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2);

#define ILOG1_DD(fmt, d1, d2) \
  __ILOG1_DD_7(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < 1)
#define ILOG1_DDD(fmt, d1, d2, d3)
#else

__MTLK_FLOG void
__ILOG1_DDD_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, int32 d1, int32 d2, int32 d3);

#define ILOG1_DDD(fmt, d1, d2, d3) \
  __ILOG1_DDD_7(LOG_CONSOLE_TEXT_INFO, 1, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (int32) (d1), (int32) (d2), (int32) (d3))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < 1 */


#if (IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL)
#define ELOG_PP(fmt, p1, p2)
#else

__MTLK_FLOG void
__ELOG_PP_7(const char *fname, int level, uint8 oid, uint8 gid, uint8 fid, uint16 lid, const char *fmt, const void * p1, const void * p2);

#define ELOG_PP(fmt, p1, p2) \
  __ELOG_PP_7(LOG_CONSOLE_TEXT_INFO, IWLWAV_RTLOG_ERROR_DLEVEL, LOG_LOCAL_OID, LOG_LOCAL_GID, LOG_LOCAL_FID, __LINE__, \
               (fmt), (const void *) (p1), (const void *) (p2))
#endif /* IWLWAV_RTLOG_MAX_DLEVEL < IWLWAV_RTLOG_ERROR_DLEVEL */


