#ifndef ROM_READER_H
#define ROM_READER_H

#include <stddef.h> // For size_t
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // For memcpy function

#define TRAINER_SIZE 512
#define PRG_ROM_SIZE 16384 
#define CHR_ROM_SIZE 8192
#define INST_ROM_SIZE 8192
#define PROM_SIZE 32
#define TITLE_SIZE 127

typedef struct
{
    uint8_t prg_banks_amount;
    uint8_t chr_banks_amount;
    uint8_t ram_banks_amount;
    bool vertical_mirror;  
    bool battery_ram_presence; 
    bool trainer_presence; 
    bool alternative_nametable_layout;
    bool vs_unisystem;
    bool play_choice_presence;
    bool nes_2_0_format;
    uint8_t prg_ram_size;
    uint8_t graphic_system; // 0: NTSC 1: PAL
    uint8_t tv_system; // 0: ntsc 2: pal 1/3: dual compatible
    bool prg_ram_present;
    bool bus_conflicts; 
    uint8_t mapper_number;
    char author[5];

    uint8_t trainer[TRAINER_SIZE];
    uint8_t **prg_banks;
    uint8_t **chr_banks;
    uint8_t playchoice_inst_rom[INST_ROM_SIZE];
    uint8_t playchoice_prom[PROM_SIZE];

    bool title_present;
    char title[TITLE_SIZE];

    size_t file_size;

}rom_t;

unsigned char* read_bytes_from_rom(const char *filename, long pos, size_t amount, size_t *out_size);

size_t get_rom_size(const char *filename);

void read_rom(rom_t *rom, const char *filename);

void deallocate_rom(rom_t *rom);

void print_rom_file(rom_t *rom);

#endif // ROM_READER_H
