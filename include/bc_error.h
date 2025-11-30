#ifndef BC_ERROR_H
#define BC_ERROR_H

typedef enum {
    BC_OK = 0,
    BC_ERROR_GENERIC = -1,
    BC_ERROR_INVALID_ARG = -2,
    BC_ERROR_NOMEM = -3,
    BC_ERROR_TIMEOUT = -4,
    BC_ERROR_NOT_IMPLEMENTED = -5,
    BC_ERROR_IO = -6,
    BC_ERROR_NET = -7,
} bc_status;

const char* bc_status_to_string(bc_status status);

#endif // BC_ERROR_H
