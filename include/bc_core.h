#ifndef BC_CORE_H
#define BC_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "bc_platform.h"
#include "bc_error.h"
#include "bc_log.h"
#include "bc_memory.h"
#include "bc_time.h"
#include "bc_atomic.h"

// Basic types and definitions for BitCalling

void bc_core_init(void);

#endif // BC_CORE_H
