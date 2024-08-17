#include "../include/cpu.h"

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


void cpu_illegal_instruction(uint8_t opcode)
{
    printf("'0x%02X' is an illegal instruction, terminating program...\n", opcode);
    exit(EXIT_FAILURE);
}


/*
    LDA                  LDA Load accumulator with memory                 LDA

    Operation:  M -> A                                    N Z C I D V
                                                        / / _ _ _ _
                                (Ref: 2.1.1)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Immediate     |   LDA #Oper           |    A9   |    2    |    2     |
    |  Zero Page     |   LDA Oper            |    A5   |    2    |    3     |
    |  Zero Page,X   |   LDA Oper,X          |    B5   |    2    |    4     |
    |  Absolute      |   LDA Oper            |    AD   |    3    |    4     |
    |  Absolute,X    |   LDA Oper,X          |    BD   |    3    |    4*    |
    |  Absolute,Y    |   LDA Oper,Y          |    B9   |    3    |    4*    |
    |  (Indirect,X)  |   LDA (Oper,X)        |    A1   |    2    |    6     |
    |  (Indirect),Y  |   LDA (Oper),Y        |    B1   |    2    |    5*    |
    +----------------+-----------------------+---------+---------+----------+
    * Add 1 if page boundary is crossed.
*/
void cpu_opcode_lda(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0xA9:
        {
            cpu->accumulator = cpu_fetch_byte(cpu);;
            break;
        }
        case 0xA5:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            cpu->accumulator = cpu->memory[address];
            break;
        }
        case 0xB5:
        {
            uint16_t address = cpu_fetch_byte(cpu) + cpu->x_register;
            cpu->accumulator = cpu->memory[address];
            break;
        }
        case 0xAD:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            cpu->accumulator = cpu->memory[address];
            break;
        }
        case 0xBD:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            address += cpu->x_register;
            cpu->accumulator = cpu->memory[address];
            break;
        }
        case 0xB9:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            address += cpu->y_register;
            cpu->accumulator = cpu->memory[address];
            break;
        }
        case 0xA1:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            address += cpu->x_register;
            cpu->accumulator = cpu->memory[address];
            break;
        }
        case 0xB1:
        {
            uint8_t address_high = cpu->y_register;
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            cpu->accumulator = cpu->memory[address];
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }

        if(cpu->accumulator == 0)
        {
            status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 1);
        }
        else
        {
            status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 0);
        }
        
        if((cpu->accumulator >> 7) == 1)
        {
            status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 1);
        }
        else
        {
            status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 0);
        }

    };
}


/*
    LDX                   LDX Load index X with memory                    LDX

    Operation:  M -> X                                    N Z C I D V
                                                        / / _ _ _ _
                                    (Ref: 7.0)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Immediate     |   LDX #Oper           |    A2   |    2    |    2     |
    |  Zero Page     |   LDX Oper            |    A6   |    2    |    3     |
    |  Zero Page,Y   |   LDX Oper,Y          |    B6   |    2    |    4     |
    |  Absolute      |   LDX Oper            |    AE   |    3    |    4     |
    |  Absolute,Y    |   LDX Oper,Y          |    BE   |    3    |    4*    |
    +----------------+-----------------------+---------+---------+----------+
    * Add 1 when page boundary is crossed.
*/
void cpu_opcode_ldx(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0xA2:
        {
            cpu->x_register = cpu_fetch_byte(cpu);
            break;
        }
        case 0xA6:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            cpu->x_register = cpu->memory[address];
            break;
        }
        case 0xB6:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            cpu->x_register = cpu->memory[address + cpu->y_register];
            break;
        }
        case 0xAE:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            cpu->x_register = cpu->memory[address];
            break;
        }
        case 0xBE:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            address += cpu->y_register;
            cpu->x_register = cpu->memory[address];
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };

    if(cpu->x_register == 0)
    {
        status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 1);
    }
    else
    {
        status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 0);
    }
    
    if((cpu->x_register >> 7) == 1)
    {
        status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 1);
    }
    else
    {
        status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 0);
    }
}


/*
    LDY                   LDY Load index Y with memory                    LDY
                                                        N Z C I D V
    Operation:  M -> Y                                    / / _ _ _ _
                                    (Ref: 7.1)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Immediate     |   LDY #Oper           |    A0   |    2    |    2     |
    |  Zero Page     |   LDY Oper            |    A4   |    2    |    3     |
    |  Zero Page,X   |   LDY Oper,X          |    B4   |    2    |    4     |
    |  Absolute      |   LDY Oper            |    AC   |    3    |    4     |
    |  Absolute,X    |   LDY Oper,X          |    BC   |    3    |    4*    |
    +----------------+-----------------------+---------+---------+----------+
    * Add 1 when page boundary is crossed.
*/

cpu_opcode_entry_t cpu_opcode_table[] = {
    //instruction       size  cycles   opcode      handler
    {"LDA #0x%02x"      , 2,    2,      0xA9,   cpu_opcode_lda},    // Immediate addressing
    {"LDA 0x%02x"       , 2,    3,      0xA5,   cpu_opcode_lda},    // Zero Page
    {"LDA 0x%02x,X"     , 2,    4,      0xB5,   cpu_opcode_lda},    // Zero Page,X
    {"LDA 0x%04x"       , 3,    4,      0xAD,   cpu_opcode_lda},    // Absolute
    {"LDA 0x%04x,X"     , 3,    4,      0xBD,   cpu_opcode_lda},    // Absolute,X
    {"LDA 0x%04x,Y"     , 3,    4,      0xB9,   cpu_opcode_lda},    // Absolute,Y
    {"LDA (0x%02x,X)"   , 2,    6,      0xA1,   cpu_opcode_lda},    // (Indirect,X)
    {"LDA (0x%02x),Y"   , 2,    5,      0xB1,   cpu_opcode_lda},    // (Indirect),Y
    {"LDX #0x%02x"      , 2,    2,      0xA2,   cpu_opcode_ldx},    // Immediate addressing
    {"LDX 0x%02x"       , 2,    3,      0xA6,   cpu_opcode_ldx},    // Zero Page
    {"LDX 0x%02x,Y"     , 2,    4,      0xB6,   cpu_opcode_ldx},    // Zero Page,Y
    {"LDX 0x%04x"       , 3,    4,      0xAE,   cpu_opcode_ldx},    // Absolute
    {"LDX 0x%04x,Y"     , 3,    4,      0xBE,   cpu_opcode_ldx},    // Absolute,Y
    // Add more opcodes here
};

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

    printf("FETCHED:        0x%02X\n", opcode);
    
    int num_opcodes = sizeof(cpu_opcode_table) / sizeof(cpu_opcode_entry_t);

    for (int i = 0; i < num_opcodes; i++) {
        if (cpu_opcode_table[i].opcode == opcode) {
            cpu_print_instruction(cpu, &cpu_opcode_table[i]);
            cpu_opcode_table[i].handler(cpu, opcode);
            found = true;
            break;
        }
    }
    return found;
}