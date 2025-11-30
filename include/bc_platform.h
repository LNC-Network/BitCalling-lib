#ifndef BC_PLATFORM_H
#define BC_PLATFORM_H

#if defined(_WIN32)
    #define BC_PLATFORM_WINDOWS
#elif defined(__APPLE__)
    #include <TargetConditionals.h>
    #if TARGET_OS_IPHONE
        #define BC_PLATFORM_IOS
    #else
        #define BC_PLATFORM_MACOS
    #endif
#elif defined(__ANDROID__)
    #define BC_PLATFORM_ANDROID
#elif defined(__linux__)
    #define BC_PLATFORM_LINUX
#else
    #error "Unknown platform"
#endif

// Compiler specifics
#if defined(_MSC_VER)
    #define BC_INLINE __inline
    #define BC_EXPORT __declspec(dllexport)
#else
    #define BC_INLINE inline
    #define BC_EXPORT __attribute__((visibility("default")))
#endif

#endif // BC_PLATFORM_H
