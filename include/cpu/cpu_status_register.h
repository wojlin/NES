#ifndef CPU_STATUS_REGISTER_H
#define CPU_STATUS_REGISTER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint8_t value;
    bool carry_flag;
    bool zero_flag;
    bool interrupt_disable;
    bool decimal_mode;
    bool break_command;
    bool overflow_flag;
    bool negative_flag;
} cpu_status_register_t;


typedef enum {
    CARRY_FLAG,
    ZERO_FLAG,
    INTERRUPT_DISABLE,
    DECIMAL_MODE,
    BREAK_COMMAND,
    OVERFLOW_FLAG,
    NEGATIVE_FLAG
} cpu_status_field_t;


void status_register_update_by_field(cpu_status_register_t *status_register, cpu_status_field_t field, bool value);
void status_register_update_by_value(cpu_status_register_t *status_register, uint8_t new_value);
void status_register_print(cpu_status_register_t *status_register);

#endif // CPU_STATUS_REGISTER_H
