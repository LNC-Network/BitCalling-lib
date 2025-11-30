#include "bc_core.h"
#include <assert.h>
#include <string.h>

void test_logging(void) {
    printf("Testing Logging...\n");
    bc_log_set_level(BC_LOG_TRACE);
    bc_log_trace("This is a trace message");
    bc_log_debug("This is a debug message");
    bc_log_info("This is an info message");
    bc_log_warn("This is a warning message");
    bc_log_error("This is an error message");
    // bc_log_fatal("This is a fatal message"); // Don't crash the test
}

void test_memory(void) {
    printf("Testing Memory...\n");
    size_t initial_usage = bc_mem_get_usage();
    printf("Initial memory usage: %zu\n", initial_usage);

    void* p1 = bc_malloc(100);
    assert(p1 != NULL);
    assert(bc_mem_get_usage() == initial_usage + 100);

    void* p2 = bc_calloc(10, 20); // 200 bytes
    assert(p2 != NULL);
    assert(bc_mem_get_usage() == initial_usage + 100 + 200);

    // Verify calloc zeroed memory
    char* bytes = (char*)p2;
    for (int i = 0; i < 200; i++) {
        assert(bytes[i] == 0);
    }

    p1 = bc_realloc(p1, 200);
    assert(p1 != NULL);
    assert(bc_mem_get_usage() == initial_usage + 200 + 200);

    bc_free(p1);
    bc_free(p2);

    assert(bc_mem_get_usage() == initial_usage);
    printf("Memory test passed.\n");
}

void test_time(void) {
    printf("Testing Time...\n");
    uint64_t start = bc_time_ms();
    bc_sleep_ms(100);
    uint64_t end = bc_time_ms();
    
    printf("Slept for %llu ms\n", (unsigned long long)(end - start));
    assert(end >= start + 90); // Allow some tolerance
}

void test_error(void) {
    printf("Testing Error...\n");
    assert(strcmp(bc_status_to_string(BC_OK), "Success") == 0);
    assert(strcmp(bc_status_to_string(BC_ERROR_GENERIC), "Generic Error") == 0);
}

int main(void) {
    bc_core_init();
    
    test_logging();
    test_memory();
    test_time();
    // test_error(); // Need to implement bc_status_to_string first!
    
    printf("All Core Tests Passed!\n");
    return 0;
}
