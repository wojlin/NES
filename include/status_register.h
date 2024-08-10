#ifndef STATUS_REGISTER_H
#define STATUS_REGISTER_H

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
} status_register_t;


typedef enum {
    CARRY_FLAG,
    ZERO_FLAG,
    INTERRUPT_DISABLE,
    DECIMAL_MODE,
    BREAK_COMMAND,
    OVERFLOW_FLAG,
    NEGATIVE_FLAG
} status_field_t;


void update_status_register_by_field(status_register_t *status_register, status_field_t field, bool value);
void update_status_register_by_value(status_register_t *status_register, uint8_t new_value);

void print_status_register(status_register_t *status_register);

#endif // STATUS_REGISTER_H
