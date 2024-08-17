#ifndef TILESET_H
#define TILESET_H

#include "../include/rom_file.h"

#define TILES_AMOUNT 512
#define TILE_SIZE_PX 8
#define TILE_SIZE_BYTES 16
#define TILE_PIXEL_SIZE_BITS 2

typedef struct
{
    uint8_t tile_id;
    uint8_t color_index[TILE_SIZE_PX][TILE_SIZE_PX];
}tile_t;

typedef struct
{
    tile_t tiles[TILES_AMOUNT];
}tileset_t;

tileset_t create_tileset(rom_t *rom, uint8_t bank_number);

#endif //TILESET_H
