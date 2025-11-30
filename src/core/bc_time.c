#include "bc_time.h"
#include "bc_platform.h"
#include <time.h>

#if defined(BC_PLATFORM_WINDOWS)
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/time.h>
#endif

void bc_sleep_ms(uint32_t ms) {
#if defined(BC_PLATFORM_WINDOWS)
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

uint64_t bc_time_ms(void) {
    return bc_time_us() / 1000;
}

uint64_t bc_time_us(void) {
#if defined(BC_PLATFORM_WINDOWS)
    static LARGE_INTEGER s_frequency;
    static int s_initialized = 0;
    if (!s_initialized) {
        QueryPerformanceFrequency(&s_frequency);
        s_initialized = 1;
    }
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    return (uint64_t)((now.QuadPart * 1000000) / s_frequency.QuadPart);
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000 + (ts.tv_nsec / 1000);
#endif
}
