#include "../include/tileset.h"

tileset_t create_tileset(rom_t *rom, uint8_t bank_number)
{
    if (bank_number >= rom->chr_banks_amount) {
        printf("Error: CHR bank number %d out of range. Max bank number is %d.\n", bank_number, rom->chr_banks_amount - 1);
        exit(EXIT_FAILURE);
    }

    uint8_t* chr_bank = rom->chr_banks[bank_number];
    
    tileset_t tileset;

    return tileset;
}