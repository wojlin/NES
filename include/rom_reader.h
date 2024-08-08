#ifndef ROM_READER_H
#define ROM_READER_H

#include <stddef.h> // For size_t
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // For memcpy function

typedef struct
{
    uint8_t prg_banks_amount;
    uint8_t chr_banks_amount;
    uint8_t ram_banks_amount;
    bool vertical_mirror;  
    bool battery_ram_presence; // true for battery-backed RAM atmemory locations 0x6000-0x7FFF
    bool trainer_presence; // true for 512-byte trainer at memory locations 0x7000-0x71FF
    bool four_screen_mirroring;
    uint8_t mapper_number;
}rom_t;

unsigned char* read_bytes_from_rom(const char *filename, long pos, size_t amount, size_t *out_size);

void read_rom(rom_t *rom, const char *filename);

#endif // ROM_READER_H
