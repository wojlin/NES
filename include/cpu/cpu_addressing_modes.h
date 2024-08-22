#ifndef CPU_ADDRESSING_MODES_H
#define CPU_ADDRESSING_MODES_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "cpu.h"

void cpu_addressing_accumulator(cpu_t *cpu);
uint8_t cpu_addressing_immediate(cpu_t *cpu);
uint8_t cpu_addressing_zero_page(cpu_t *cpu);
uint8_t cpu_addressing_zero_page_x(cpu_t *cpu);
uint8_t cpu_addressing_zero_page_y(cpu_t *cpu);
void cpu_addressing_relative(cpu_t *cpu);
uint8_t cpu_addressing_absolute(cpu_t *cpu);
uint8_t cpu_addressing_absolute_x(cpu_t *cpu);
uint8_t cpu_addressing_absolute_y(cpu_t *cpu);
uint8_t cpu_addressing_indirect(cpu_t *cpu);
uint8_t cpu_addressing_indexed_indirect(cpu_t *cpu);
uint8_t cpu_addressing_indirect_indexed(cpu_t *cpu);

#endif //CPU_ADDRESSING_MODES_H