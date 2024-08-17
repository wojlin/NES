#include "../include/tileset.h"

tileset_t create_tileset(rom_t *rom, uint8_t bank_number)
{
    tileset_t tileset;

    if (bank_number >= rom->chr_banks_amount) {
        printf("Error: CHR bank number %d out of range. Max bank number is %d.\n", bank_number, rom->chr_banks_amount - 1);
        exit(EXIT_FAILURE);
    }

    uint8_t* chr_bank = rom->chr_banks[bank_number];

    if (chr_bank == NULL) {
        printf(stderr, "Error: CHR bank %d is NULL.\n", bank_number);
        exit(EXIT_FAILURE);
    }

    size_t memory_pos = 0;
    uint8_t current_tile[TILE_SIZE_BYTES];

    for(size_t i = 0; i < TILES_AMOUNT; i++)
    {
        if (memory_pos + TILE_SIZE_BYTES > CHR_ROM_SIZE) {
            printf("Error: memory_pos %zu out of bounds in CHR bank %d.\n", memory_pos, bank_number);
            exit(EXIT_FAILURE);
        }

        memcpy(current_tile, &chr_bank[memory_pos], TILE_SIZE_BYTES);
        memory_pos += TILE_SIZE_BYTES;

        tile_t *tile = &tileset.tiles[i];
        tile->tile_id = i;
        
        for(uint8_t y = 0; y < TILE_SIZE_PX; y++)
        {
            for(uint8_t x = 0; x < TILE_SIZE_PX; x++)
            {
                //uint8_t current_pixel = (y*TILE_SIZE_PX) + x;
                
                uint8_t first_byte = current_tile[y];
                uint8_t second_byte = current_tile[y + 8];

                uint8_t first_bit = (first_byte >> x) & 0x01;
                uint8_t second_bit = (second_byte >> x) & 0x01;

                uint8_t pixel_index = (first_bit << 1) | (second_bit & 0x01);

                tile->color_index[y][x] = pixel_index;
            }
        }
    }
    
    

    return tileset;
}