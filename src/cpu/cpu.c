#include "../include/cpu/cpu_opcodes.h"
#include "../include/cpu/cpu.h"


void cpu_init(cpu_t *cpu)
{
    cpu->accumulator = 0;
    cpu->x_register = 0;
    cpu->y_register = 0;
    cpu->stack_pointer = 0;
    cpu->program_counter = START_ADDRESS;
    status_register_update_by_value(&cpu->status_register, 0);
    memset(cpu->memory, 0, sizeof(cpu->memory));
}

uint8_t cpu_read_byte(cpu_t *cpu, uint16_t address)
{
    uint8_t value = cpu->memory[address];
    return value;
}

uint8_t cpu_fetch_byte(cpu_t *cpu)
{
    uint8_t value = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    return value;
}

void cpu_write_byte(cpu_t *cpu, uint16_t address, uint8_t value)
{
    cpu->memory[address] = value;
}

void cpu_illegal_instruction(uint8_t opcode)
{
    printf("'0x%02X' is an illegal instruction, terminating program...\n", opcode);
    exit(EXIT_FAILURE);
}


void cpu_print_instruction(cpu_t *cpu, cpu_opcode_entry_t *entry) 
{
    uint64_t result = 0;
    uint8_t length = entry->size - 1;  // The number of bytes to read

    for (size_t i = 0; i < length; i++) {
        result <<= 8;  // Shift the current result 8 bits to the left to make space for the next byte
        uint16_t address = cpu->program_counter + i;
        uint8_t r_byte = cpu_read_byte(cpu, address);
        result |= r_byte;  // Combine the next byte using bitwise OR
    }

    printf("INSTRUCTION:    ");
    printf(entry->name, result); 
    printf("\n");
}


bool cpu_execute(cpu_t *cpu)
{   

    bool found = false;

    uint8_t opcode = cpu_fetch_byte(cpu);

    //printf("FETCHED:        0x%02X\n", opcode);
    
    
    size_t num_opcodes = cpu_get_opcode_amount();

    for (size_t i = 0; i < num_opcodes; i++) {
        if (cpu_opcode_table[i].opcode == opcode) {
            cpu_print_instruction(cpu, &cpu_opcode_table[i]);
            cpu_opcode_table[i].handler(cpu, opcode);
            found = true;
            break;
        }
    }
    
    return found;
}