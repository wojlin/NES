#include "../include/rom_file.h"


size_t get_rom_size(const char *filename) {
    FILE *file = fopen(filename, "rb"); // Open the file in binary mode
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);  // Move the file pointer to the end of the file
    size_t size = ftell(file);   // Get the current file pointer position (this is the file size)
    fclose(file);              // Close the file

    return size;
}

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

    rom->vertical_mirror =                 ((returned_data[0] >> 0) & 1) == 1 ? true : false;
    rom->battery_ram_presence =            ((returned_data[0] >> 1) & 1) == 1 ? true : false;
    rom->trainer_presence =                ((returned_data[0] >> 2) & 1) == 1 ? true : false;
    rom->alternative_nametable_layout =    ((returned_data[0] >> 3) & 1) == 1 ? true : false;
    lower_bits = (returned_data[0] & (0x0F));

    returned_data = read_bytes_from_rom(filename, 7, 1, &returned_size);

    rom->vs_unisystem = ((returned_data[0] >> 0) & 1) == 1 ? true : false;
    rom->play_choice_presence = ((returned_data[0] >> 1) & 1) == 1 ? true : false;
    
    if( ((returned_data[0] >> 3) & 1) == 1 && ((returned_data[0] >> 2) & 1) == 0 )
    {
        rom->nes_2_0_format = true;
    }else
    {
        rom->nes_2_0_format = false;
    }

    upper_bits = (returned_data[0] & (0x0F));

    
    value = (upper_bits << 4) | (lower_bits & 0x0F);
    rom->mapper_number = value;

    returned_data = read_bytes_from_rom(filename, 8, 1, &returned_size);
    rom->ram_banks_amount = returned_data[0];
    if(rom->ram_banks_amount == 0)
    {
        rom->ram_banks_amount = 1;
    }

    returned_data = read_bytes_from_rom(filename, 9, 1, &returned_size);
    rom->graphic_system = ((returned_data[0] >> 0) & 1) == 1 ? true : false;
    returned_data[0] = returned_data[0] & 0xFE;
    if(returned_data[0] == 0)
    {
        //pass
    }else
    {
        printf("reserved bits are not set to 0!\n");
        free(returned_data);
        exit(EXIT_FAILURE);
    }

    returned_data = read_bytes_from_rom(filename, 10, 1, &returned_size);
    if(((returned_data[0] >> 1) & 1) == 1 && ((returned_data[0] >> 0) & 1) == 0)
    {
        rom->tv_system = 2; // PAL
    }else if(((returned_data[0] >> 1) & 1) == 0 && ((returned_data[0] >> 0) & 1) == 0)
    {
        rom->tv_system = 0; // ntsc
    }else
    {
        rom->tv_system = 1; // dual
    }

    rom->prg_ram_present = ((returned_data[0] >> 4) & 1) == 1 ? true : false;
    rom->bus_conflicts = ((returned_data[0] >> 5) & 1) == 1 ? true : false;

    returned_data = read_bytes_from_rom(filename, 11, 5, &returned_size);
    memcpy(rom->author, returned_data, 5);

    ////// HEADER END //////
    


    int memory_read_start = 16;

    if(rom->trainer_presence)
    {
        returned_data = read_bytes_from_rom(filename, 10, TRAINER_SIZE, &returned_size);
        memcpy(rom->trainer, returned_data, TRAINER_SIZE);
        memory_read_start += TRAINER_SIZE;
    }
    else
    {
        rom->prg_banks = (uint8_t **)malloc(rom->prg_banks_amount * sizeof(uint8_t *));
        rom->chr_banks = (uint8_t **)malloc(rom->chr_banks_amount * sizeof(uint8_t *));

        for(size_t i = 0; i < rom->prg_banks_amount; i++)
        {
            returned_data = read_bytes_from_rom(filename, memory_read_start, PRG_ROM_SIZE, &returned_size);
            
            if (returned_data == NULL || returned_size != PRG_ROM_SIZE) {
                printf("Error reading PRG data from ROM\n");
                exit(EXIT_FAILURE);
            }
            
            rom->prg_banks[i] = (uint8_t *)malloc(PRG_ROM_SIZE * sizeof(uint8_t));

            if(rom->prg_banks[i] == NULL)
            {
                printf("Memory allocation failed for PRG bank %ld\n", i);
                exit(EXIT_FAILURE);
            }

            memcpy(rom->prg_banks[i], returned_data, PRG_ROM_SIZE);
            memory_read_start += PRG_ROM_SIZE;
        } 

        
        for(size_t i = 0; i < rom->chr_banks_amount; i++)
        {
            returned_data = read_bytes_from_rom(filename, memory_read_start, CHR_ROM_SIZE, &returned_size);
            
            if (returned_data == NULL || returned_size != CHR_ROM_SIZE) {
                printf("Error reading PRG data from ROM\n");
                exit(EXIT_FAILURE);
            }
            
            rom->chr_banks[i] = (uint8_t *)malloc(CHR_ROM_SIZE * sizeof(uint8_t));

            if(rom->chr_banks[i] == NULL) 
            {
                printf("Memory allocation failed for CHR bank %ld\n", i);
                exit(EXIT_FAILURE);
            }

            memcpy(rom->chr_banks[i], returned_data, CHR_ROM_SIZE);
            memory_read_start += CHR_ROM_SIZE;
        }    
        
    }

    
    if(rom->play_choice_presence)
    {
        returned_data = read_bytes_from_rom(filename, memory_read_start, INST_ROM_SIZE, &returned_size);

        if (returned_data == NULL || returned_size != INST_ROM_SIZE) 
        {
            printf("Error reading inst rom from ROM\n");
            exit(EXIT_FAILURE);
        }

        memcpy(rom->playchoice_inst_rom, returned_data, INST_ROM_SIZE);
        memory_read_start += INST_ROM_SIZE;

        returned_data = read_bytes_from_rom(filename, memory_read_start, PROM_SIZE, &returned_size);
        if (returned_data == NULL || returned_size != PROM_SIZE) 
        {
            printf("Error reading prom from ROM\n");
            exit(EXIT_FAILURE);
        }

        memcpy(rom->playchoice_prom, returned_data, PROM_SIZE);
        memory_read_start += PROM_SIZE;
    }
    

    
    size_t file_size = get_rom_size(filename);
    rom->file_size = file_size;
    long size_left = file_size - memory_read_start;
    if(size_left >= TITLE_SIZE)
    {
        rom->title_present = true;
        returned_data = read_bytes_from_rom(filename, memory_read_start, size_left, &returned_size);
        memcpy(rom->title, returned_data, TITLE_SIZE);
    }else
    {
        rom->title_present = false;
    }
    
}

void deallocate_rom(rom_t *rom)
{
    for (int i = 0; i < rom->prg_banks_amount; i++) {
        free(rom->prg_banks[i]);
    }
    free(rom->prg_banks);

    for (int i = 0; i < rom->chr_banks_amount; i++) {
        free(rom->chr_banks[i]);
    }
    free(rom->chr_banks);
}

void print_rom_file(rom_t *rom) 
{
    printf("### rom file ###\n");
    printf("file size           : %ld bytes\n", rom->file_size);
    printf("title               : %s\n", rom->title_present ? rom->title : "no titile");

    printf("prg rom banks amount: %d\n", rom->prg_banks_amount);
    printf("chr rom banks amount: %d\n", rom->chr_banks_amount);
    printf("flags:\n");
    printf("    vertical mirror             : %s\n", rom->vertical_mirror ? "true" : "false");
    printf("    battery ram                 : %s\n", rom->battery_ram_presence ? "true" : "false");
    printf("    trainer                     : %s\n", rom->trainer_presence ? "true" : "false");
    printf("    alternative nametable       : %s\n", rom->alternative_nametable_layout ? "true" : "false");
    printf("    vs unisystem                : %s\n", rom->vs_unisystem ? "true" : "false");
    printf("    playchoice                  : %s\n", rom->play_choice_presence ? "true" : "false");
    printf("    nes 2.0 format              : %s\n", rom->nes_2_0_format ? "true" : "false");
    printf("    mapper number               : %d\n", rom->mapper_number);
    printf("    prg ram size                : %d\n", rom->prg_ram_size);
    printf("    graphic system              : %s\n", rom->graphic_system == 0 ? "NTSC" : "PAL");
    printf("    tv system                   : %d\n", rom->tv_system);
    printf("    prg ram present             : %s\n", rom->prg_ram_present ? "true" : "false");
    printf("    bus conflicts               : %s\n", rom->bus_conflicts ? "true" : "false");
    printf("    author                      : %s\n", rom->author);
    
    printf("#######################\n");
}
