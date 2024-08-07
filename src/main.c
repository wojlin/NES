#include <stdio.h>

#include "../include/nes.h"
#include "../include/status_register.h"

void print_status_register(StatusRegister *status_register) 
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

int main()
{
    NES nes;
    uint8_t new = 0b00000011;
    update_status_register_by_value(&nes.status_register, new);
    print_status_register(&nes.status_register);
    update_status_register_by_field(&nes.status_register, NEGATIVE_FLAG, true);
    print_status_register(&nes.status_register);
    return 0;
}