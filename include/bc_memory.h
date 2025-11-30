#ifndef BC_MEMORY_H
#define BC_MEMORY_H

#include <stddef.h>

void* bc_malloc(size_t size);
void* bc_calloc(size_t count, size_t size);
void* bc_realloc(void* ptr, size_t size);
void  bc_free(void* ptr);

// Debug stats
size_t bc_mem_get_usage(void);

#endif // BC_MEMORY_H
