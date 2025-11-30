#include "bc_error.h"

const char* bc_status_to_string(bc_status status) {
    switch (status) {
        case BC_OK: return "Success";
        case BC_ERROR_GENERIC: return "Generic Error";
        case BC_ERROR_INVALID_ARG: return "Invalid Argument";
        case BC_ERROR_NOMEM: return "Out of Memory";
        case BC_ERROR_TIMEOUT: return "Timeout";
        case BC_ERROR_NOT_IMPLEMENTED: return "Not Implemented";
        case BC_ERROR_IO: return "I/O Error";
        case BC_ERROR_NET: return "Network Error";
        default: return "Unknown Error";
    }
}
