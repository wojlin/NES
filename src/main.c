#include <stdio.h>


#include "../include/cpu/cpu_status_register.h"
#include "../include/cpu/cpu.h"
#include "../include/cpu/cpu_addressing_modes.h"


int main()
{
    cpu_t cpu;
    cpu_init(&cpu);
    cpu.memory[0] = 0xF0;
    cpu.memory[START_ADDRESS] = 0xA9; // LDA
    cpu.memory[START_ADDRESS + 1] = 0x0F; 
    cpu.memory[START_ADDRESS + 2] = 0xA2; // LDX
    cpu.memory[START_ADDRESS + 3] = 0x09;
    cpu.memory[START_ADDRESS + 4] = 0xA0; // LDY
    cpu.memory[START_ADDRESS + 5] = 0x11; 
    cpu.memory[START_ADDRESS + 6] = 0xEA; // NOP
    cpu.memory[START_ADDRESS + 7] = 0x09; // ORA
    cpu.memory[START_ADDRESS + 8] = 0x00; 
    cpu.memory[START_ADDRESS + 9] = 0x48; // PHA
    cpu.memory[START_ADDRESS + 10] = 0x08; // PHP
    cpu.memory[START_ADDRESS + 11] = 0x68; // PLA
    cpu.memory[START_ADDRESS + 12] = 0x28; // PLP
    cpu.memory[START_ADDRESS + 13] = 0x2A; // ROL
    cpu.memory[START_ADDRESS + 14] = 0x6A; // ROR
    cpu.memory[START_ADDRESS + 15] = 0x69; // ADC
    cpu.memory[START_ADDRESS + 16] = 0x55; 

    bool working = true;
    while(working)
    {
        working = cpu_execute(&cpu);
    }
    return 0;
}