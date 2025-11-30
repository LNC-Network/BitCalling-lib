#include "bc_memory.h"
#include "bc_atomic.h"
#include <stdlib.h>

static bc_atomic_size_t g_mem_usage = 0;

// We need to track size of allocations to decrement correctly.
// A simple strategy is to allocate extra bytes to store the size.
// [size_t size][payload...]

void* bc_malloc(size_t size) {
    if (size == 0) return NULL;
    
    size_t total_size = sizeof(size_t) + size;
    void* ptr = malloc(total_size);
    if (!ptr) return NULL;

    *(size_t*)ptr = size;
    atomic_fetch_add(&g_mem_usage, size);
    
    return (char*)ptr + sizeof(size_t);
}

void* bc_calloc(size_t count, size_t size) {
    size_t total_req = count * size;
    if (total_req == 0) return NULL;

    size_t total_alloc = sizeof(size_t) + total_req;
    void* ptr = calloc(1, total_alloc);
    if (!ptr) return NULL;

    *(size_t*)ptr = total_req;
    atomic_fetch_add(&g_mem_usage, total_req);

    return (char*)ptr + sizeof(size_t);
}

void bc_free(void* ptr) {
    if (!ptr) return;

    char* real_ptr = (char*)ptr - sizeof(size_t);
    size_t size = *(size_t*)real_ptr;

    atomic_fetch_sub(&g_mem_usage, size);
    free(real_ptr);
}

void* bc_realloc(void* ptr, size_t size) {
    if (!ptr) return bc_malloc(size);
    if (size == 0) {
        bc_free(ptr);
        return NULL;
    }

    char* real_ptr = (char*)ptr - sizeof(size_t);
    size_t old_size = *(size_t*)real_ptr;

    size_t total_size = sizeof(size_t) + size;
    void* new_ptr = realloc(real_ptr, total_size);
    if (!new_ptr) return NULL; // Original ptr is still valid

    *(size_t*)new_ptr = size;
    
    // Update usage: -old + new
    atomic_fetch_sub(&g_mem_usage, old_size);
    atomic_fetch_add(&g_mem_usage, size);

    return (char*)new_ptr + sizeof(size_t);
}

size_t bc_mem_get_usage(void) {
    return atomic_load(&g_mem_usage);
}
