#include "bc_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static bc_log_level g_level = BC_LOG_INFO;
static bc_log_callback g_callback = NULL;

// Simple mutex for thread safety (using C11 threads if available, or platform specific)
// For now, we'll assume single threaded init or rely on atomic/platform specific later if needed for strictness.
// In a real high-perf scenario, we might use a lock-free queue.
// For this stage, we will just use standard IO which is usually thread-safe enough for debug.

void bc_log_init(void) {
    // No-op for now
}

void bc_log_set_level(bc_log_level level) {
    g_level = level;
}

void bc_log_set_callback(bc_log_callback cb) {
    g_callback = cb;
}

static const char* level_strings[] = {
    "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
};

static const char* level_colors[] = {
    "\x1b[94m", // TRACE - Light Blue
    "\x1b[36m", // DEBUG - Cyan
    "\x1b[32m", // INFO  - Green
    "\x1b[33m", // WARN  - Yellow
    "\x1b[31m", // ERROR - Red
    "\x1b[35m"  // FATAL - Magenta
};

void bc_log_msg(bc_log_level level, const char *file, int line, const char *fmt, ...) {
    if (level < g_level) return;

    va_list args;
    
    // If callback is set, delegate
    if (g_callback) {
        va_start(args, fmt);
        g_callback(level, file, line, fmt, args);
        va_end(args);
        return;
    }

    // Default console logging
    // Get time
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    char time_buf[16];
    time_buf[strftime(time_buf, sizeof(time_buf), "%H:%M:%S", lt)] = '\0';

    // Print to stderr
    fprintf(stderr, "%s %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ", 
            time_buf, level_colors[level], level_strings[level], file, line);
    
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
}
