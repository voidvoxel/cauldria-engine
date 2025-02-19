#if !defined(VOIDVOXEL__CAULDRIA__LOG_HPP)
#define VOIDVOXEL__CAULDRIA__LOG_HPP

#include <raylib.h>

// TraceLogDebug(const char *message)
#if DEBUG
SetTraceLogLevel(LOG_DEBUG)
#define TraceLogDebug(message) TraceLog(LOG_DEBUG, message)
#else
#define TraceLogDebug(message) ((void) 0)
#endif

#define TraceLogError(message) TraceLog(LOG_ERROR, message)
#define TraceLogFatal(message) TraceLog(LOG_FATAL, message)
#define TraceLogInfo(message) TraceLog(LOG_INFO, message)
#define TraceLogWarn(message) TraceLog(LOG_WARNING, message)

#endif
