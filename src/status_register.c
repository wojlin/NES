#include "../include/status_register.h"

void update_status_register_by_field(status_register_t *status_register, status_field_t field, bool value)
{
    switch (field) {
        case CARRY_FLAG:
            status_register->carry_flag = value;
            break;
        case ZERO_FLAG:
            status_register->zero_flag = value;
            break;
        case INTERRUPT_DISABLE:
            status_register->interrupt_disable = value;
            break;
        case DECIMAL_MODE:
            status_register->decimal_mode = value;
            break;
        case BREAK_COMMAND:
            status_register->break_command = value;
            break;
        case OVERFLOW_FLAG:
            status_register->overflow_flag = value;
            break;
        case NEGATIVE_FLAG:
            status_register->negative_flag = value;
            break;
        default:
            break;
    }

    // Update the status register value after setting the flag
    status_register->value = 
          (status_register->carry_flag        << 0)
        | (status_register->zero_flag         << 1)
        | (status_register->interrupt_disable << 2)
        | (status_register->decimal_mode      << 3)
        | (status_register->break_command     << 4)
        | (0                                     << 5)  // Bit 5 is unused
        | (status_register->overflow_flag     << 6)
        | (status_register->negative_flag     << 7);
}

void update_status_register_by_value(status_register_t *status_register, uint8_t new_value)
{
    status_register->carry_flag =        ((new_value >> 0) & 1) == 1 ? true : false;
    status_register->zero_flag =         ((new_value >> 1) & 1) == 1 ? true : false;
    status_register->interrupt_disable = ((new_value >> 2) & 1) == 1 ? true : false;
    status_register->decimal_mode =      ((new_value >> 3) & 1) == 1 ? true : false;
    status_register->break_command =     ((new_value >> 4) & 1) == 1 ? true : false;
    // unused bit (5)
    status_register->overflow_flag =     ((new_value >> 6) & 1) == 1 ? true : false;
    status_register->negative_flag =     ((new_value >> 7) & 1) == 1 ? true : false;
    status_register->value = new_value;
}

void print_status_register(status_register_t *status_register) 
{
    printf("### status register ###\n");
    printf("value: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (status_register->value >> i) & 1);
    }
    printf("\n");
    printf("carry flag: %s\n", status_register->carry_flag ? "true" : "false");
    printf("zero flag: %s\n", status_register->zero_flag ? "true" : "false");
    printf("interrupt disable: %s\n", status_register->interrupt_disable ? "true" : "false");
    printf("decimal mode: %s\n", status_register->decimal_mode ? "true" : "false");
    printf("break command: %s\n", status_register->break_command ? "true" : "false");
    printf("overflow flag: %s\n", status_register->overflow_flag ? "true" : "false");
    printf("negative flag: %s\n", status_register->negative_flag ? "true" : "false");
    printf("#######################\n");
}