#include <stdio.h>

#include "../include/nes.h"
#include "../include/status_register.h"
#include "../include/rom_file.h"
#include "../include/tileset.h"

nes_t nes;
rom_t rom;





int main()
{
    
    read_rom(&rom, "../roms/Super_mario_brothers.nes");
    print_rom_file(&rom);
    tileset_t tileset = create_tileset(&rom, 0);

    //uint8_t new = 0b00000011;
    //update_status_register_by_value(&nes.status_register, new);
    //print_status_register(&nes.status_register);
    //update_status_register_by_field(&nes.status_register, NEGATIVE_FLAG, true);
    //print_status_register(&nes.status_register);

    
    
    return 0;
}