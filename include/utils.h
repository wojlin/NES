#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdbool.h> // For bool
#include <stdio.h>   // For printf
#include <stdint.h>  // For uint8_t
#include <stdlib.h>  // For exit and EXIT_FAILURE
#include <string.h>  // For memset

uint8_t rotate_left(uint8_t value, unsigned int shift);

uint8_t rotate_right(uint8_t value, unsigned int shift);

uint8_t get_msb(uint8_t value);

uint8_t get_lsb(uint8_t value);

uint8_t get_bit(uint8_t value, unsigned int bit_position);

#endif //UTILS_H