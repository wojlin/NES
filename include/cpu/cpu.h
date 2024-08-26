#ifndef CPU_H
#define CPU_H


#include <stdio.h>
#include <stdbool.h> // For bool
#include <stdio.h>   // For printf
#include <stdint.h>  // For uint8_t
#include <stdlib.h>  // For exit and EXIT_FAILURE
#include <string.h>  // For memset


#include "cpu_status_register.h"
#include "../utils.h"

#define START_ADDRESS 0x1000
#define RAM_SIZE 65536
#define STACK_SIZE 255

typedef struct cpu_t
{   
    /*
    THE REGISTERS INSIDE THE 6502 MICROPROCESSOR

    Almost all calculations are done in the microprocessor. Registers are
    special pieces of memory in the processor which are used to carry out, and
    store information about calculations. The 6502 has the following registers:
    */

    uint8_t accumulator;
    /*
    THE ACCUMULATOR

    This is THE most important register in the microprocessor. Various ma-
    chine language instructions allow you to copy the contents of a memory
    location into the accumulator, copy the contents of the accumulator into
    a memory location, modify the contents of the accumulator or some other
    register directly, without affecting any memory. And the accumulator is
    the only register that has instructions for performing math.
    */
    

    uint8_t x_register;
    /*
    THE X INDEX REGISTER

    This is a very important register. There are instructions for nearly
    all of the transformations you can make to the accumulator. But there are
    other instructions for things that only the X register can do. Various
    machine language instructions allow you to copy the contents of a memory
    location into the X register, copy the contents of the X register into a
    memory location, and modify the contents of the X, or some other register
    directly.
    */
    
    uint8_t y_register;
    /*
    THE Y INDEX REGISTER

    This is a very important register. There are instructions for nearly
    all of the transformations you can make to the accumulator, and the X
    register. But there are other instructions for things that only the Y
    register can do. Various machine language instructions allow you to copy
    the contents of a memory location into the Y register, copy the contents
    of the Y register into a memory location, and modify the contents of the
    Y, or some other register directly.
    */
    
    cpu_status_register_t status_register;
    /*
     THE STATUS REGISTER

    This register consists of eight "flags" (a flag = something that indi-
    cates whether something has, or has not occurred). Bits of this register
    are altered depending on the result of arithmetic and logical operations.
    These bits are described below:

    Bit No. 7   6   5   4   3   2   1   0
            S   V       B   D   I   Z   C

    Bit0 - C - Carry flag: this holds the carry out of the most significant
    bit in any arithmetic operation. In subtraction operations however, this
    flag is cleared - set to 0 - if a borrow is required, set to 1 - if no
    borrow is required. The carry flag is also used in shift and rotate
    logical operations.

    Bit1 - Z - Zero flag: this is set to 1 when any arithmetic or logical
    operation produces a zero result, and is set to 0 if the result is
    non-zero.

    Bit 2 - I: this is an interrupt enable/disable flag. If it is set,
    interrupts are disabled. If it is cleared, interrupts are enabled.

    Bit 3 - D: this is the decimal mode status flag. When set, and an Add with
    Carry or Subtract with Carry instruction is executed, the source values are
    treated as valid BCD (Binary Coded Decimal, eg. 0x00-0x99 = 0-99) numbers.
    The result generated is also a BCD number.

    Bit 4 - B: this is set when a software interrupt (BRK instruction) is
    executed.

    Bit 5: not used. Supposed to be logical 1 at all times.

    Bit 6 - V - Overflow flag: when an arithmetic operation produces a result
    too large to be represented in a byte, V is set.

    Bit 7 - S - Sign flag: this is set if the result of an operation is
    negative, cleared if positive.

    The most commonly used flags are C, Z, V, S.
    */
    
    uint16_t program_counter;
    /*
    THE PROGRAM COUNTER

    This contains the address of the current machine language instruction
    being executed. Since the operating system is always "RUN"ning in the
    Commodore VIC-20 (or, for that matter, any computer), the program counter
    is always changing. It could only be stopped by halting the microprocessor
    in some way.
    */

    uint8_t stack_pointer;
    /*
    THE STACK POINTER

    This register contains the location of the first empty place on the
    stack. The stack is used for temporary storage by machine language pro-
    grams, and by the computer.
    */



    /*MEMORY*/

    uint8_t memory[RAM_SIZE];

    uint8_t stack[STACK_SIZE];

}cpu_t;

typedef void (*cpu_opcode_handler_t)(cpu_t *cpu, uint8_t opcode);

typedef struct {
    char name[15];
    uint8_t size;
    uint8_t cycles;
    uint8_t opcode;
    cpu_opcode_handler_t handler;
} cpu_opcode_entry_t;

void cpu_init(cpu_t *cpu);
bool cpu_execute(cpu_t *cpu);
uint8_t cpu_fetch_byte(cpu_t *cpu);
void cpu_illegal_instruction(uint8_t opcode);
uint8_t cpu_read_byte(cpu_t *cpu, uint16_t address);
void cpu_write_byte(cpu_t *cpu, uint16_t address, uint8_t value);
void cpu_print_instruction(cpu_t *cpu, cpu_opcode_entry_t *entry);

#endif //CPU_H