
#ifndef NES_H
#define NES_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "status_register.h"
#include "cpu.h"

#define MEMORY_SIZE 65535               // 64KB memory from 0x0000-0xFFFFF
#define ZERO_PAGE_SIZE 256              // zero page from 0x000-0x00FF 0-255
#define STACK_SIZE 256                  // stack from 0x0100-0x01FF 256-511
#define RAM_SIZE 1536                   // ramfrom 0x0200-0x07FF 512-2047                                               
#define IO_REGISTERS_SIZE 34            // io registers from (0x2000-0x2007) (8192-8199) and (0x4000-0x401F) (16384-16415)     
#define EXPANSION_ROM_SIZE 8160         // expansion rom from (0X4020-0x5FFF) (16416-24575) 8160
#define SRAM_SIZE 8189                  // sram from (0x6000-0x7FFD) (24576-32765)
#define PRG_ROM_LOWER_BANK_SIZE 16384   // prg-rom lower bank from (0x8000-0xBFFF) (32768-49151)
#define PRG_ROM_UPPER_BANK_SIZE 16384   // prg-rom upper bank from (0xC000-0xFFFF) (49152-65535)


// 0 0x0000 - 2047 0x07FF  is mirrored 3 times at    2048 0x0800  - 8191 0x1FFF 
// This means that, for example, any data written to $0000 will also be written to $0800, $1000 and $180
// copied zero page, stack and ram to 1FFF 8191


typedef struct
{
    uint16_t zero_page[ZERO_PAGE_SIZE];
    uint16_t stack[STACK_SIZE];
    uint16_t ram[RAM_SIZE];
    uint16_t io_registers[IO_REGISTERS_SIZE];
    uint16_t expansion_rom[EXPANSION_ROM_SIZE];
    uint16_t sram[SRAM_SIZE];
    uint16_t pgr_rom_lower_bank[PRG_ROM_LOWER_BANK_SIZE];
    uint16_t pgr_rom_upper_bank[PRG_ROM_UPPER_BANK_SIZE];

    cpu_t cpu;


} nes_t;

#endif // NES_H