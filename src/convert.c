/*
 * binconv
 * Numeric Converter Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <binconv/convert.h>

/**
 * Finds the position of the Most Significant Bit (MSB) of an integer.
 *
 * Returns -1 if the value is 0 or negative.
 */
static int find_msb_position(int value) {

    if (value <= 0) {
        return -1;
    }

    int pos = 0;

    while (value > 1) {
        value >>= 1;
        pos++;
    }

    return pos;
}

/**
 * Converts a decimal integer to its binary representation string.
 *
 * Validates the input buffers and sizes, handles the base case for zero,
 * and dynamically shifts bits to write '1' or '0' characters into the buffer.
 */
int binconv_decimal_to_binary(char *out, int value, size_t size) {

    if (!out || value < 0 || size == 0) {
        return -1;
    }

    if (value == 0) {
        if (size < 2) {
            return -1;
        }

        out[0] = '0';
        out[1] = '\0';
        
        return 0;
    }

    int msb = find_msb_position(value);

    if (size < (size_t)(msb + 2)) {
        return -1;
    }

    for (int i = msb; i >= 0; i--) {
        out[msb - i] = (value >> i) & 1 ? '1' : '0';
    }

    out[msb + 1] = '\0';

    return 0;
}