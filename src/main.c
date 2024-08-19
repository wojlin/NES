#include <stdio.h>

#include "../include/status_register.h"
#include "../include/cpu.h"



int main()
{
    cpu_t cpu;
    cpu_init(&cpu);
    cpu.memory[START_ADDRESS] = 0xA9; // LDA
    cpu.memory[START_ADDRESS + 1] = 0x0F; 
    cpu.memory[START_ADDRESS + 2] = 0xA2; // LDX
    cpu.memory[START_ADDRESS + 3] = 0x09;
    cpu.memory[START_ADDRESS + 4] = 0xA0; // LDY
    cpu.memory[START_ADDRESS + 5] = 0x11; 
    cpu.memory[START_ADDRESS + 6] = 0xEA; // NOP
    cpu.memory[START_ADDRESS + 7] = 0x09; // ORA
    cpu.memory[START_ADDRESS + 5] = 0x00; 
    cpu.memory[0] = 0xF0;

    bool working = true;
    while(working)
    {
        working = cpu_execute(&cpu);
    }
    printf("%d\n", cpu.memory[0]);
    return 0;
}