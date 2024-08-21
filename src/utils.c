#include "../include/utils.h"

uint8_t rotate_left(uint8_t value, unsigned int shift) {
    return (value << shift) | (value >> (8 - shift));
}

uint8_t rotate_right(uint8_t value, unsigned int shift) {
    return (value >> shift) | (value << (8 - shift));
}

uint8_t get_msb(uint8_t value) {
    return value >> 1;
}

uint8_t get_lsb(uint8_t value) {
    return value & 0x7F; 
}

uint8_t get_bit(uint8_t value, unsigned int bit_position) {
    return (value >> bit_position) & 0x01;
}