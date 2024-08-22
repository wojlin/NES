#include "../include/cpu/cpu_addressing_modes.h"

void cpu_addressing_accumulator(cpu_t *cpu)
{
    // TODO
}

uint8_t cpu_addressing_immediate(cpu_t *cpu)
{
    uint8_t value = cpu_fetch_byte(cpu);
    return value;
}

uint8_t cpu_addressing_zero_page(cpu_t *cpu)
{
    uint8_t address = cpu_fetch_byte(cpu);
    return cpu->memory[address];
}

uint8_t cpu_addressing_zero_page_x(cpu_t *cpu)
{
    uint8_t address = cpu_fetch_byte(cpu) + cpu->x_register;
    return cpu->memory[address];
}

uint8_t cpu_addressing_zero_page_y(cpu_t *cpu)
{
    uint8_t address = cpu_fetch_byte(cpu) + cpu->x_register;
    return cpu->memory[address];
}

void cpu_addressing_relative(cpu_t *cpu)
{
    // TODO
}

uint8_t cpu_addressing_absolute(cpu_t *cpu)
{
    uint8_t address_high = cpu_fetch_byte(cpu);
    uint8_t address_low = cpu_fetch_byte(cpu);
    uint16_t address = ((address_high << 8) | address_low);
    return cpu->memory[address];
}

uint8_t cpu_addressing_absolute_x(cpu_t *cpu)
{
    uint8_t address_high = cpu_fetch_byte(cpu);
    uint8_t address_low = cpu_fetch_byte(cpu);
    uint16_t address = ((address_high << 8) | address_low) + cpu->x_register;
    return cpu->memory[address];
}

uint8_t cpu_addressing_absolute_y(cpu_t *cpu)
{
    uint8_t address_high = cpu_fetch_byte(cpu);
    uint8_t address_low = cpu_fetch_byte(cpu);
    uint16_t address = ((address_high << 8) | address_low) + cpu->y_register;
    return cpu->memory[address];
}

uint8_t cpu_addressing_indirect(cpu_t *cpu)
{
    uint8_t address_low = cpu_fetch_byte(cpu);
    uint8_t address_high = cpu_fetch_byte(cpu);
    uint16_t address = ((address_high << 8) | address_low);
    return cpu->memory[address];
}

uint8_t cpu_addressing_indexed_indirect(cpu_t *cpu)
{
    uint8_t indirect_address_ptr = cpu_fetch_byte(cpu) + cpu->x_register;
    uint8_t lsb = cpu->memory[indirect_address_ptr];
    uint8_t msb = cpu->memory[(indirect_address_ptr + 1) & 0xFF]; 
    uint16_t address = (msb << 8) | lsb;

    return cpu->memory[address];
}

uint8_t cpu_addressing_indirect_indexed(cpu_t *cpu)
{
    uint8_t lsb = cpu_fetch_byte(cpu) + cpu->x_register;
    uint8_t msb = cpu->y_register;
    uint16_t address = (msb << 8) | lsb;

    return cpu->memory[address];
}