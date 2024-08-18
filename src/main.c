#include <stdio.h>

#include "../include/status_register.h"
#include "../include/cpu.h"



int main()
{
    cpu_t cpu;
    cpu_init(&cpu);
    cpu.memory[START_ADDRESS] = 0xA9; // LDA
    cpu.memory[START_ADDRESS + 1] = 0x20; 
    cpu.memory[START_ADDRESS + 2] = 0xA2; // LDX
    cpu.memory[START_ADDRESS + 3] = 0x09;
    cpu.memory[START_ADDRESS + 4] = 0xA0; // LDY
    cpu.memory[START_ADDRESS + 5] = 0x11; 
    cpu.memory[START_ADDRESS + 6] = 0xEA; // NOP

    bool working = true;
    while(working)
    {
        working = cpu_execute(&cpu);
    }
    return 0;
}