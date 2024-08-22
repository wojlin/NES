#ifndef CPU_OPCODES_H
#define CPU_OPCODES_H

#include <stdio.h>
#include <stdbool.h> // For bool
#include <stdio.h>   // For printf
#include <stdint.h>  // For uint8_t
#include <stdlib.h>  // For exit and EXIT_FAILURE
#include <string.h>  // For memset

#include "cpu.h"



// done: 14/56



void cpu_opcode_lda(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_ldx(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_ldy(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_lsr(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_nop(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_ora(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_pha(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_php(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_pla(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_plp(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_rol(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_ror(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_adc(cpu_t *cpu, uint8_t opcode);
void cpu_opcode_and(cpu_t *cpu, uint8_t opcode);


size_t cpu_get_opcode_amount();

extern cpu_opcode_entry_t cpu_opcode_table[];

#endif //CPU_OPCODES_H