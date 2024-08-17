#include <stdio.h>

#include "../include/status_register.h"
#include "../include/cpu.h"



int main()
{
    cpu_t cpu;
    cpu_init(&cpu);
    cpu.memory[START_ADDRESS] = 0xA9; // 169
    cpu.memory[START_ADDRESS + 1] = 0x20; // 32
    cpu.memory[START_ADDRESS + 2] = 0xA2; // 169
    cpu.memory[START_ADDRESS + 3] = 0x09; // 32

    bool working = true;
    while(working)
    {
        working = cpu_execute(&cpu);
    }
    return 0;
}