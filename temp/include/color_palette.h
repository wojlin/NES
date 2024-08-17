#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include <stddef.h> // For size_t
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // For memcpy function


#define PALETTE_FILE_SIZE 1536 
#define PALETTE_SIZE 64
#define PALETTE_AMOUNT 8

typedef struct {
    uint8_t colors[PALETTE_AMOUNT][PALETTE_SIZE][3];
} color_palette_t;



/**
 * Load a color palette from a file.
 * @param palette Pointer to the color_palette_t structure to load colors into.
 * @param filename Path to the file containing the color palette data.
 */
color_palette_t load_palette_from_file(const char *filename);


#endif // COLOR_PALETTE_H
