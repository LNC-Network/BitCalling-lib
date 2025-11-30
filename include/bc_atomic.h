#ifndef BC_ATOMIC_H
#define BC_ATOMIC_H

#include "bc_platform.h"

#if defined(__STDC_NO_ATOMICS__)
    #error "C11 Atomics not supported"
#else
    #include <stdatomic.h>
#endif

// Wrapper types for convenience if needed, or just use standard types
typedef atomic_int bc_atomic_int;
typedef atomic_bool bc_atomic_bool;
typedef atomic_size_t bc_atomic_size_t;

#endif // BC_ATOMIC_H
