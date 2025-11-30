#ifndef BC_LOG_H
#define BC_LOG_H

#include "bc_platform.h"
#include <stdarg.h>

typedef enum {
    BC_LOG_TRACE,
    BC_LOG_DEBUG,
    BC_LOG_INFO,
    BC_LOG_WARN,
    BC_LOG_ERROR,
    BC_LOG_FATAL
} bc_log_level;

typedef void (*bc_log_callback)(bc_log_level level, const char *file, int line, const char *fmt, va_list args);

void bc_log_init(void);
void bc_log_set_level(bc_log_level level);
void bc_log_set_callback(bc_log_callback cb);
void bc_log_msg(bc_log_level level, const char *file, int line, const char *fmt, ...);

#define bc_log_trace(...) bc_log_msg(BC_LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define bc_log_debug(...) bc_log_msg(BC_LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define bc_log_info(...)  bc_log_msg(BC_LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define bc_log_warn(...)  bc_log_msg(BC_LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define bc_log_error(...) bc_log_msg(BC_LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define bc_log_fatal(...) bc_log_msg(BC_LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

#define bc_log(...)       bc_log_info(__VA_ARGS__)

#endif // BC_LOG_H
