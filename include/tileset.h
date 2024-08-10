#ifndef TILESET_H
#define TILESET_H

#include "../include/rom_file.h"

#define TILES_AMOUNT 512


typedef struct
{
    uint8_t tile_id;
}tile_t;

typedef struct
{
    tile_t tiles[TILES_AMOUNT];
}tileset_t;

tileset_t create_tileset(rom_t *rom, uint8_t bank_number);

#endif //TILESET_H
