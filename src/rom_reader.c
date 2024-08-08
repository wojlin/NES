#include "../include/rom_reader.h"

unsigned char* read_bytes_from_rom(const char *filename, long pos, size_t amount, size_t *out_size) {
    FILE *file = fopen(filename, "rb"); // Open the file in binary mode
    if (file == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    if (fseek(file, pos, SEEK_SET) != 0) { // Move the file pointer to position 'pos'
        printf("Error seeking file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    unsigned char *buffer = (unsigned char *)malloc(amount); // Allocate memory for 'amount' bytes
    if (buffer == NULL) {
        printf("Memory allocation error\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(buffer, 1, amount, file); // Read 'amount' bytes from the file
    if (bytesRead < amount) {
        if (feof(file)) {
            printf("End of file reached before reading %zu bytes\n", amount);
            exit(EXIT_FAILURE);
        } else if (ferror(file)) {
            printf("Error reading file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file); // Close the file

    *out_size = bytesRead; // Return the actual size read
    return buffer; // Return the buffer containing the read bytes
}


void read_rom(rom_t *rom, const char *filename)
{
    size_t returned_size;
    unsigned char *returned_data;

    //// HEADER START ////
    
    returned_data = read_bytes_from_rom(filename, 0, 3, &returned_size);
    if(returned_data[0] == 'N' && returned_data[1] == 'E' && returned_data[2] == 'S')
    {
        // pass
    }
    else
    {
        printf("invalid ines identifier!\n");
        free(returned_data);
        exit(EXIT_FAILURE);
    }

    returned_data = read_bytes_from_rom(filename, 3, 1, &returned_size);
    if(returned_data[0] == 0x1A)
    {
        // pass
    }
    else
    {
        printf("invalid file identifier!\n");
        free(returned_data);
        exit(EXIT_FAILURE);
    }

    returned_data = read_bytes_from_rom(filename, 4, 1, &returned_size);
    rom->prg_banks_amount = returned_data[0];

    returned_data = read_bytes_from_rom(filename, 5, 1, &returned_size);
    rom->chr_banks_amount = returned_data[0];


    uint8_t lower_bits;
    uint8_t upper_bits;
    uint8_t value;

    returned_data = read_bytes_from_rom(filename, 6, 1, &returned_size);

    rom->vertical_mirror =          ((returned_data[0] >> 0) & 1) == 1 ? true : false;
    rom->battery_ram_presence =     ((returned_data[0] >> 1) & 1) == 1 ? true : false;
    rom->trainer_presence =         ((returned_data[0] >> 2) & 1) == 1 ? true : false;
    rom->four_screen_mirroring =    ((returned_data[0] >> 3) & 1) == 1 ? true : false;
    lower_bits = (returned_data[0] & (0x0F));

    returned_data = read_bytes_from_rom(filename, 7, 1, &returned_size);

    if (((returned_data[0] >> 4) & (0x0F)) == 0)
    {
        //pass
    }
    else
    {
        printf("reserved bits are not set to 0!\n");
        free(returned_data);
        exit(EXIT_FAILURE);
    }

    upper_bits = (returned_data[0] & (0x0F));

    
    value = (upper_bits << 4) | (lower_bits & 0x0F);
    rom->mapper_number = value;

    returned_data = read_bytes_from_rom(filename, 8, 1, &returned_size);
    rom->ram_banks_amount = returned_data[0];

    returned_data = read_bytes_from_rom(filename, 9, 1, &returned_size);
    if(returned_data[0] == 0)
    {
        //pass
    }else
    {
        printf("reserved future usage bits are not set to 0!\n");
        free(returned_data);
        exit(EXIT_FAILURE);
    }

    ////// HEADER END //////

    
}