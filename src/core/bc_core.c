#include "bc_core.h"
#include <stdarg.h>

void bc_core_init(void) {
    bc_log_init();
    bc_log_info("[CORE] BitCalling Core Initialized");
}
