#ifndef PPU_H
#define PPU_H

#include <stdio.h>
#include <stdint.h>

static const uint16_t VRAM_MEMORY_SIZE = 65535       // 64KB memory from 0x0000-0xFFFFF

typedef struct
{
    uint16_t vram[VRAM_MEMORY_SIZE];
} PPU;

#endif // PPU_H2ddd