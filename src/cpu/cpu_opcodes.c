#include "../include/cpu/cpu_opcodes.h"

cpu_opcode_entry_t cpu_opcode_table[] = {

    //instruction       size  cycles   opcode      handler

    //INSTRUCTION ADC
    {"ADC #0x%02x"      , 2,    2,      0x69,   cpu_opcode_adc},    // Immediate
    {"ADC 0x%02x"       , 2,    3,      0x65,   cpu_opcode_adc},    // Zero Page
    {"ADC 0x%02x,X"     , 2,    4,      0x75,   cpu_opcode_adc},    // Zero Page,X
    {"ADC 0x%04x"       , 3,    4,      0x60,   cpu_opcode_adc},    // Absolute
    {"ADC 0x%04x,X"     , 3,    4,      0x70,   cpu_opcode_adc},    // Absolute,X
    {"ADC 0x%04x,Y"     , 3,    4,      0x79,   cpu_opcode_adc},    // Absolute,Y
    {"ADC (0x%02x,X)"   , 2,    6,      0x61,   cpu_opcode_adc},    // (Indirect,X)
    {"ADC (0x%02x),Y"   , 2,    5,      0x71,   cpu_opcode_adc},    // (Indirect),Y

    //INSTRUCTION AND
    {"AND #0x%02x"      , 2,    2,      0x29,   cpu_opcode_and},    // Immediate
    {"AND 0x%02x"       , 2,    3,      0x25,   cpu_opcode_and},    // Zero Page
    {"AND 0x%02x,X"     , 2,    4,      0x35,   cpu_opcode_and},    // Zero Page,X
    {"AND 0x%04x"       , 3,    4,      0x2D,   cpu_opcode_and},    // Absolute
    {"AND 0x%04x,X"     , 3,    4,      0x3D,   cpu_opcode_and},    // Absolute,X
    {"AND 0x%04x,Y"     , 3,    4,      0x39,   cpu_opcode_and},    // Absolute,Y
    {"AND (0x%02x,X)"   , 2,    6,      0x21,   cpu_opcode_and},    // (Indirect,X)
    {"AND (0x%02x),Y"   , 2,    5,      0x21,   cpu_opcode_and},    // (Indirect,Y)

    //INSTRUCTION LDA
    {"LDA #0x%02x"      , 2,    2,      0xA9,   cpu_opcode_lda},    // Immediate addressing
    {"LDA 0x%02x"       , 2,    3,      0xA5,   cpu_opcode_lda},    // Zero Page
    {"LDA 0x%02x,X"     , 2,    4,      0xB5,   cpu_opcode_lda},    // Zero Page,X
    {"LDA 0x%04x"       , 3,    4,      0xAD,   cpu_opcode_lda},    // Absolute
    {"LDA 0x%04x,X"     , 3,    4,      0xBD,   cpu_opcode_lda},    // Absolute,X
    {"LDA 0x%04x,Y"     , 3,    4,      0xB9,   cpu_opcode_lda},    // Absolute,Y
    {"LDA (0x%02x,X)"   , 2,    6,      0xA1,   cpu_opcode_lda},    // (Indirect,X)
    {"LDA (0x%02x),Y"   , 2,    5,      0xB1,   cpu_opcode_lda},    // (Indirect),Y

    //INSTRUCTION LDX
    {"LDX #0x%02x"      , 2,    2,      0xA2,   cpu_opcode_ldx},    // Immediate addressing
    {"LDX 0x%02x"       , 2,    3,      0xA6,   cpu_opcode_ldx},    // Zero Page
    {"LDX 0x%02x,Y"     , 2,    4,      0xB6,   cpu_opcode_ldx},    // Zero Page,Y
    {"LDX 0x%04x"       , 3,    4,      0xAE,   cpu_opcode_ldx},    // Absolute
    {"LDX 0x%04x,Y"     , 3,    4,      0xBE,   cpu_opcode_ldx},    // Absolute,Y

    //INSTRUCTION LDY
    {"LDY #0x%02x"      , 2,    2,      0xA0,   cpu_opcode_ldy},    // Immediate addressing
    {"LDY 0x%02x"       , 2,    3,      0xA4,   cpu_opcode_ldy},    // Zero Page
    {"LDY 0x%02x,X"     , 3,    4,      0xB4,   cpu_opcode_ldy},    // Zero Page, X
    {"LDY 0x%04x"       , 3,    4,      0xAC,   cpu_opcode_ldy},    // Absolute
    {"LDY 0x%04x,X"     , 3,    4,      0xBC,   cpu_opcode_ldy},    // Absolute,X

    //INSTRUCTION LSR
    {"LSR A"            , 1,    2,      0x4A,   cpu_opcode_lsr},    // Accumulator
    {"LSR 0x%02x"       , 2,    5,      0x46,   cpu_opcode_lsr},    // Zero Page
    {"LSR 0x%02x,X"     , 2,    6,      0x56,   cpu_opcode_lsr},    // Zero Page,X
    {"LSR 0x%04x"       , 3,    6,      0x4E,   cpu_opcode_lsr},    // Absolute
    {"LSR 0x%04x,X"     , 3,    7,      0x5E,   cpu_opcode_lsr},    // Absolute,X

    //INSTRUCTION NOP
    {"NOP"              , 1,    2,      0xEA,   cpu_opcode_nop},    // Implied

    //INSTRUCTION ORA
    {"ORA #0x%02x"      , 2,    2,      0x09,   cpu_opcode_ora},    // Immediate
    {"ORA 0x%02x"       , 2,    3,      0x05,   cpu_opcode_ora},    // Zero Page
    {"ORA 0x%02x,X"     , 2,    4,      0x15,   cpu_opcode_ora},    // Zero Page,X
    {"ORA 0x%04x"       , 3,    4,      0x0D,   cpu_opcode_ora},    // Absolute
    {"ORA 0x%04x,X"     , 3,    4,      0x1D,   cpu_opcode_ora},    // Absolute,X
    {"ORA 0x%04x,Y"     , 3,    4,      0x19,   cpu_opcode_ora},    // Absolute,Y
    {"ORA (0x%02x,X)"   , 2,    6,      0x01,   cpu_opcode_ora},    // (Indirect,X)
    {"ORA (0x%02x),Y"   , 2,    5,      0x11,   cpu_opcode_ora},    // (Indirect),Y

    //INSTRUCTION PHA
    {"PHA"              , 1,    3,      0x48,   cpu_opcode_pha},    // Implied

    //INSTRUCTION PHP
    {"PHP"              , 1,    3,      0x08,   cpu_opcode_php},    // Implied

    //INSTRUCTION PLA
    {"PLA"              , 1,    4,      0x68,   cpu_opcode_pla},    // Implied

    //INSTRUCTION PLP
    {"PLP"              , 1,    4,      0x28,   cpu_opcode_plp},    // Implied

    //INSTRUCTION ROL
    {"ROL A"            , 1,    2,      0x2A,   cpu_opcode_rol},    // Accumulator
    {"ROL 0x%02x"       , 2,    5,      0x26,   cpu_opcode_rol},    // Zero Page
    {"ROL 0x%02x,X"     , 2,    6,      0x36,   cpu_opcode_rol},    // Zero Page,X
    {"ROL 0x%04x"       , 3,    6,      0x2E,   cpu_opcode_rol},    // Absolute
    {"ROL 0x%04x,X"     , 3,    7,      0x3E,   cpu_opcode_rol},    // Absolute,X

    //INSTRUCTION ROR
    {"ROR A"            , 1,    2,      0x6A,   cpu_opcode_ror},    // Accumulator
    {"ROR 0x%02x"       , 2,    5,      0x66,   cpu_opcode_ror},    // Zero Page
    {"ROR 0x%02x,X"     , 2,    5,      0x76,   cpu_opcode_ror},    // Zero Page,X
    {"ROR 0x%04x"       , 3,    6,      0x6E,   cpu_opcode_ror},    // Absolute
    {"ROR 0x%04x,X"     , 3,    7,      0x7E,   cpu_opcode_ror},    // Absolute,X
};  

size_t cpu_get_opcode_amount()
{
    return sizeof(cpu_opcode_table) / sizeof(cpu_opcode_entry_t);
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
            cpu->accumulator = cpu_fetch_byte(cpu);
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
void cpu_opcode_ldy(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0xA0:
        {
            cpu->y_register = cpu_fetch_byte(cpu);
            break;
        }
        case 0xA4:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            cpu->y_register = cpu->memory[address];
            break;
        }
        case 0xB4:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            cpu->y_register = cpu->memory[address + cpu->y_register];
            break;
        }
        case 0xAC:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            cpu->y_register = cpu->memory[address];
            break;
        }
        case 0xBC:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            address += cpu->x_register;
            cpu->y_register = cpu->memory[address];
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };

    if(cpu->y_register == 0)
    {
        status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 1);
    }
    else
    {
        status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 0);
    }
    
    if((cpu->y_register >> 7) == 1)
    {
        status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 1);
    }
    else
    {
        status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 0);
    }
}

/*
    LSR          LSR Shift right one bit (memory or accumulator)          LSR

                    +-+-+-+-+-+-+-+-+
    Operation:  0 -> |7|6|5|4|3|2|1|0| -> C               N Z C I D V
                    +-+-+-+-+-+-+-+-+                    0 / / _ _ _
                                    (Ref: 10.1)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Accumulator   |   LSR A               |    4A   |    1    |    2     |
    |  Zero Page     |   LSR Oper            |    46   |    2    |    5     |
    |  Zero Page,X   |   LSR Oper,X          |    56   |    2    |    6     |
    |  Absolute      |   LSR Oper            |    4E   |    3    |    6     |
    |  Absolute,X    |   LSR Oper,X          |    5E   |    3    |    7     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_lsr(cpu_t *cpu, uint8_t opcode)
{
    uint8_t old_value;
    uint16_t address;

    switch(opcode)
    {
        case 0x4A:
        {
            old_value = cpu->accumulator;
            cpu->accumulator >>= 1;
            break;
        }
        case 0x46:
        {   
            address = cpu_fetch_byte(cpu);
            old_value = cpu->memory[address];
            cpu->memory[address] >>= 1;
            break;
        }
        case 0x56:
        {
            address = cpu_fetch_byte(cpu) + cpu->x_register;
            old_value = cpu->memory[address];
            cpu->memory[address] >>= 1;
            break;
        }
        case 0x4E:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            address = ((address_high << 8) | address_low);
            old_value = cpu->memory[address];
            cpu->memory[address] >>= 1;
            break;
        }
        case 0x5E:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            address = ((address_high << 8) | address_low) + cpu->x_register;
            old_value = cpu->memory[address];
            cpu->memory[address] >>= 1;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };

    if((old_value & 0x01) != 0)
    {
        status_register_update_by_field(&cpu->status_register, CARRY_FLAG, 1);
    }
    else
    {
        status_register_update_by_field(&cpu->status_register, CARRY_FLAG, 0);
    }

    if(opcode == 0x4A)
    {
        if(cpu->accumulator == 0)
        {
            status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 1);
        }
        else
        {
            status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 0);
        }

        if((cpu->accumulator & 0x80) == 0x80)
        {
            status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 1);
        }else
        {
            status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 0);
        }

    }else
    {
        if(cpu->memory[address] == 0)
        {
            status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 1);
        }
        else
        {
            status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 0);
        }

        if((cpu->memory[address] & 0x80) == 0x80)
        {
            status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 1);
        }else
        {
            status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 0);
        }
    }


    

}


/*
    NOP                         NOP No operation                          NOP
                                                        N Z C I D V
    Operation:  No Operation (2 cycles)                   _ _ _ _ _ _

    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Implied       |   NOP                 |    EA   |    1    |    2     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_nop(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0xEA:
        {
            cpu->accumulator = cpu->accumulator; // only to suppress warning
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };
}



/*
    ORA                 ORA "OR" memory with accumulator                  ORA

    Operation: A V M -> A                                 N Z C I D V
                                                        / / _ _ _ _
                                (Ref: 2.2.3.1)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Immediate     |   ORA #Oper           |    09   |    2    |    2     |
    |  Zero Page     |   ORA Oper            |    05   |    2    |    3     |
    |  Zero Page,X   |   ORA Oper,X          |    15   |    2    |    4     |
    |  Absolute      |   ORA Oper            |    0D   |    3    |    4     |
    |  Absolute,X    |   ORA Oper,X          |    1D   |    3    |    4*    |
    |  Absolute,Y    |   ORA Oper,Y          |    19   |    3    |    4*    |
    |  (Indirect,X)  |   ORA (Oper,X)        |    01   |    2    |    6     |
    |  (Indirect),Y  |   ORA (Oper),Y        |    11   |    2    |    5     |
    +----------------+-----------------------+---------+---------+----------+
    * Add 1 on page crossing
*/
void cpu_opcode_ora(cpu_t *cpu, uint8_t opcode)
{
    uint16_t address;

    switch(opcode)
    {
        case 0x09:
        {
            address = cpu_fetch_byte(cpu);
            cpu->memory[address] |= cpu->accumulator;
            break;
        }
        case 0x05:
        {
            address = cpu_fetch_byte(cpu);
            cpu->memory[address] |= cpu->accumulator;
            break;
        }
        case 0x15:
        {
            address = cpu_fetch_byte(cpu) + cpu->x_register;
            cpu->memory[address] |= cpu->accumulator;
            break;
        }case 0x0D:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            address = ((address_high << 8) | address_low);
            cpu->memory[address] |= cpu->accumulator;
            break;
        }
        case 0x1D:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            address = ((address_high << 8) | address_low) +cpu->x_register;
            cpu->memory[address] |= cpu->accumulator;
            break;
        }
        case 0x19:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            address = ((address_high << 8) | address_low) +cpu->y_register;
            cpu->memory[address] |= cpu->accumulator;
            break;
        }
        case 0x01:
        {
            address = cpu_fetch_byte(cpu);
            address += cpu->x_register;
            cpu->memory[address] |= cpu->accumulator;
            break;
        }
        case 0x11:
        {
            uint8_t address_high = cpu->y_register;
            uint8_t address_low = cpu_fetch_byte(cpu);
            address = (address_high << 8) | address_low;
            cpu->memory[address] |= cpu->accumulator;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };

    if(cpu->accumulator == 0)
    {
        status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 1);
    }else
    {
        status_register_update_by_field(&cpu->status_register, ZERO_FLAG, 0);
    }

    if((cpu->memory[address] >> 7) == 1)
    {
        status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 1);
    }else
    {
        status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, 0);
    }
}

/*
    PHA                   PHA Push accumulator on stack                   PHA

    Operation:  A toS                                     N Z C I D V
                                                        _ _ _ _ _ _
                                    (Ref: 8.5)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Implied       |   PHA                 |    48   |    1    |    3     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_pha(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0x48:
        {
            cpu->stack[cpu->stack_pointer++] = cpu->accumulator;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };
}



/*
    PHP                 PHP Push processor status on stack                PHP

    Operation:  P toS                                     N Z C I D V
                                                        _ _ _ _ _ _
                                    (Ref: 8.11)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Implied       |   PHP                 |    08   |    1    |    3     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_php(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0x08:
        {
            cpu->stack[cpu->stack_pointer++] = cpu->status_register.value;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };
}


/*
    PLA                 PLA Pull accumulator from stack                   PLA

    Operation:  A fromS                                   N Z C I D V
                                                        _ _ _ _ _ _
                                    (Ref: 8.6)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Implied       |   PLA                 |    68   |    1    |    4     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_pla(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0x68:
        {
            cpu->accumulator = cpu->stack[cpu->stack_pointer--];
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };
}


/*
    PLP               PLP Pull processor status from stack                PLA

    Operation:  P fromS                                   N Z C I D V
                                                            From Stack
                                    (Ref: 8.12)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Implied       |   PLP                 |    28   |    1    |    4     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_plp(cpu_t *cpu, uint8_t opcode)
{
    switch(opcode)
    {
        case 0x28:
        {
            status_register_update_by_value(&cpu->status_register, cpu->stack[cpu->stack_pointer--]);
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };
}


/*
    ROL          ROL Rotate one bit left (memory or accumulator)          ROL

                +------------------------------+
                |         M or A               |
                |   +-+-+-+-+-+-+-+-+    +-+   |
    Operation:   +-< |7|6|5|4|3|2|1|0| <- |C| <-+         N Z C I D V
                    +-+-+-+-+-+-+-+-+    +-+             / / / _ _ _
                                    (Ref: 10.3)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Accumulator   |   ROL A               |    2A   |    1    |    2     |
    |  Zero Page     |   ROL Oper            |    26   |    2    |    5     |
    |  Zero Page,X   |   ROL Oper,X          |    36   |    2    |    6     |
    |  Absolute      |   ROL Oper            |    2E   |    3    |    6     |
    |  Absolute,X    |   ROL Oper,X          |    3E   |    3    |    7     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_rol(cpu_t *cpu, uint8_t opcode)
{
    uint8_t old_value;
    uint8_t new_value;

    switch(opcode)
    {
        case 0x2A:
        {
            old_value = cpu->accumulator;
            new_value = rotate_left(cpu->accumulator, 1);
            cpu->accumulator = new_value;
            break;
        }
        case 0x26:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            old_value = cpu->memory[address];
            new_value = rotate_left(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        case 0x36:
        {
            uint8_t address = cpu_fetch_byte(cpu) + cpu->x_register;
            old_value = cpu->memory[address];
            new_value = rotate_left(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        case 0x2E:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = ((address_high << 8) | address_low);
            old_value = cpu->memory[address];
            new_value = rotate_left(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        case 0x3E:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = ((address_high << 8) | address_low) + cpu->x_register;
            old_value = cpu->memory[address];
            new_value = rotate_left(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };


    status_register_update_by_field(&cpu->status_register, CARRY_FLAG, get_msb(old_value));
    status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, get_msb(new_value));
}


/*
    ROR          ROR Rotate one bit right (memory or accumulator)         ROR

                +------------------------------+
                |                              |
                |   +-+    +-+-+-+-+-+-+-+-+   |
    Operation:   +-> |C| -> |7|6|5|4|3|2|1|0| >-+         N Z C I D V
                    +-+    +-+-+-+-+-+-+-+-+             / / / _ _ _
                                    (Ref: 10.4)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Accumulator   |   ROR A               |    6A   |    1    |    2     |
    |  Zero Page     |   ROR Oper            |    66   |    2    |    5     |
    |  Zero Page,X   |   ROR Oper,X          |    76   |    2    |    6     |
    |  Absolute      |   ROR Oper            |    6E   |    3    |    6     |
    |  Absolute,X    |   ROR Oper,X          |    7E   |    3    |    7     |
    +----------------+-----------------------+---------+---------+----------+
*/
void cpu_opcode_ror(cpu_t *cpu, uint8_t opcode)
{
    uint8_t old_value;
    uint8_t new_value;

    switch(opcode)
    {
        case 0x6A:
        {
            old_value = cpu->accumulator;
            new_value = rotate_right(cpu->accumulator, 1);
            cpu->accumulator = new_value;
            break;
        }
        case 0x66:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            old_value = cpu->memory[address];
            new_value = rotate_right(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        case 0x76:
        {
            uint8_t address = cpu_fetch_byte(cpu) + cpu->x_register;
            old_value = cpu->memory[address];
            new_value = rotate_right(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        case 0x6E:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = ((address_high << 8) | address_low);
            old_value = cpu->memory[address];
            new_value = rotate_right(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        case 0x7E:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = ((address_high << 8) | address_low) + cpu->x_register;
            old_value = cpu->memory[address];
            new_value = rotate_right(old_value, 1);
            cpu->memory[address] = new_value;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };


    status_register_update_by_field(&cpu->status_register, CARRY_FLAG, get_msb(old_value));
    status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, get_msb(new_value));
}


/*
  ADC               Add memory to accumulator with carry                ADC

  Operation:  A + M + C -> A, C                         N Z C I D V
                                                        / / / _ _ /
                                (Ref: 2.2.1)
  +----------------+-----------------------+---------+---------+----------+
  | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
  +----------------+-----------------------+---------+---------+----------+
  |  Immediate     |   ADC #Oper           |    69   |    2    |    2     |
  |  Zero Page     |   ADC Oper            |    65   |    2    |    3     |
  |  Zero Page,X   |   ADC Oper,X          |    75   |    2    |    4     |
  |  Absolute      |   ADC Oper            |    60   |    3    |    4     |
  |  Absolute,X    |   ADC Oper,X          |    70   |    3    |    4*    |
  |  Absolute,Y    |   ADC Oper,Y          |    79   |    3    |    4*    |
  |  (Indirect,X)  |   ADC (Oper,X)        |    61   |    2    |    6     |
  |  (Indirect),Y  |   ADC (Oper),Y        |    71   |    2    |    5*    |
  +----------------+-----------------------+---------+---------+----------+
  * Add 1 if page boundary is crossed.
*/
void cpu_opcode_adc(cpu_t *cpu, uint8_t opcode)
{
    uint16_t old_value = cpu->accumulator;
    uint16_t value_to_add;

    switch(opcode)
    {
        case 0x69:
        {
            value_to_add = cpu_fetch_byte(cpu);
            cpu->accumulator += value_to_add;
            break;
        }
        case 0x65:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            value_to_add = cpu->memory[address];
            cpu->accumulator += value_to_add;
            break;
        }
        case 0x75:
        {
            uint8_t address = cpu_fetch_byte(cpu);
            value_to_add = cpu->memory[address] + cpu->x_register;
            cpu->accumulator += value_to_add;
            break;
        }
        case 0x60:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = ((address_high << 8) | address_low);
            value_to_add = cpu->memory[address];
            cpu->accumulator += value_to_add;
            break;
        }
        case 0x70:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = ((address_high << 8) | address_low) + cpu->x_register;
            value_to_add = cpu->memory[address];
            cpu->accumulator += value_to_add;
            break;
        }
        case 0x79:
        {
            uint8_t address_high = cpu_fetch_byte(cpu);
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = ((address_high << 8) | address_low) + cpu->y_register;
            value_to_add = cpu->memory[address];
            cpu->accumulator += value_to_add;
            break;
        }
        case 0x61:
        {
            uint8_t address = cpu_fetch_byte(cpu) + cpu->x_register;
            value_to_add = cpu->memory[address];
            cpu->accumulator += value_to_add;
            break;
        }
        case 0x71:
        {
            uint8_t address_high = cpu->y_register;
            uint8_t address_low = cpu_fetch_byte(cpu);
            uint16_t address = (address_high << 8) | address_low;
            value_to_add = cpu->memory[address];
            cpu->accumulator += value_to_add;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }
    };

    uint16_t result = old_value + value_to_add + (cpu->status_register.carry_flag);
    cpu->accumulator = result & 0xFF; // Keep it to 8 bits

    status_register_update_by_field(&cpu->status_register, ZERO_FLAG, cpu->accumulator == 0);
    status_register_update_by_field(&cpu->status_register, CARRY_FLAG, result > 255);
    status_register_update_by_field(&cpu->status_register, NEGATIVE_FLAG, get_msb(cpu->accumulator));
    
    bool overflow = (~(old_value ^ value_to_add) & (old_value ^ result) & 0x80);
    status_register_update_by_field(&cpu->status_register, OVERFLOW_FLAG, overflow);
}


/*
    AND                  "AND" memory with accumulator                    AND

    Operation:  A /\ M -> A                               N Z C I D V
                                                        / / _ _ _ _
                                (Ref: 2.2.3.0)
    +----------------+-----------------------+---------+---------+----------+
    | Addressing Mode| Assembly Language Form| OP CODE |No. Bytes|No. Cycles|
    +----------------+-----------------------+---------+---------+----------+
    |  Immediate     |   AND #Oper           |    29   |    2    |    2     |
    |  Zero Page     |   AND Oper            |    25   |    2    |    3     |
    |  Zero Page,X   |   AND Oper,X          |    35   |    2    |    4     |
    |  Absolute      |   AND Oper            |    2D   |    3    |    4     |
    |  Absolute,X    |   AND Oper,X          |    3D   |    3    |    4*    |
    |  Absolute,Y    |   AND Oper,Y          |    39   |    3    |    4*    |
    |  (Indirect,X)  |   AND (Oper,X)        |    21   |    2    |    6     |
    |  (Indirect,Y)  |   AND (Oper),Y        |    31   |    2    |    5     |
    +----------------+-----------------------+---------+---------+----------+
    * Add 1 if page boundary is crossed.
*/
void cpu_opcode_and(cpu_t *cpu, uint8_t opcode)
{   
    uint8_t memory_value;
    uint8_t accumulator_value = cpu->accumulator;

    switch(opcode)
    {
        case 0x29:
        {
            memory_value = cpu_fetch_byte(cpu);
            cpu->accumulator = memory_value & accumulator_value;
            break;
        }
        case 0x25:
        {
            memory_value = cpu->memory[cpu_fetch_byte(cpu)];
            cpu->accumulator = memory_value & accumulator_value;
            break;
        }
        case 0x35:
        {
            memory_value = cpu->memory[cpu_fetch_byte(cpu) + cpu->x_register];
            cpu->accumulator = memory_value & accumulator_value;
            break;
        }
        default:
        {
            cpu_illegal_instruction(opcode);
        }

    };
}