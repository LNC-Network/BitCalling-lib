#ifndef BC_TIME_H
#define BC_TIME_H

#include <stdint.h>

// Returns monotonic time in milliseconds
uint64_t bc_time_ms(void);

// Returns monotonic time in microseconds
uint64_t bc_time_us(void);

void bc_sleep_ms(uint32_t ms);

#endif // BC_TIME_H
