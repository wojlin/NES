#include "../include/color_palette.h"

color_palette_t  load_palette_from_file(const char *filename) {
    color_palette_t color_palette;
    
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    size_t bytes_read = fread(color_palette.colors, sizeof(uint8_t), PALETTE_AMOUNT * PALETTE_SIZE * 3, file);
    if (bytes_read != PALETTE_AMOUNT * PALETTE_SIZE * 3) {
        printf("Failed to read complete file or file size mismatch\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);

    return color_palette;
}
