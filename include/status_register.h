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
} StatusRegister;


typedef enum {
    CARRY_FLAG,
    ZERO_FLAG,
    INTERRUPT_DISABLE,
    DECIMAL_MODE,
    BREAK_COMMAND,
    OVERFLOW_FLAG,
    NEGATIVE_FLAG
} StatusField;


void update_status_register_by_field(StatusRegister *status_register, StatusField field, bool value);
void update_status_register_by_value(StatusRegister *status_register, uint8_t new_value);

#endif // STATUS_REGISTER_H
