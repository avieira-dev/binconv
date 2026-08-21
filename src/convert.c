/*
 * binconv
 * Numeric Converter Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include "binconv/convert.h"

/**
 * @brief Finds the position of the Most Significant Bit (MSB) of an integer.
 *
 * Returns -1 if the value is 0 or negative.
 *
 * @param value The non-negative integer to inspect.
 * @return int The zero-based position of the most significant bit,
 * or -1 if the value is not positive.
 */
static int find_msb_position(long value) {
    if (value <= 0) {
        return -1;
    }

    int position = 0;

    while (value > 1) {
        value >>= 1;
        position++;
    }

    return position;
}

/**
 * @brief Converts a decimal integer to its binary representation string.
 *
 * Validates the output buffer and size, handles zero as a special case,
 * and extracts each bit from the most significant bit to the least
 * significant bit.
 *
 * @param[out] out Pointer to the buffer where the binary string will be stored.
 * @param[in] value The non-negative decimal integer to convert.
 * @param[in] size The total size of the output buffer.
 * @return int 0 on success, -1 on failure.
 */
int binconv_decimal_to_binary(char *out, long value, size_t size) {
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

/**
 * @brief Converts a binary string to its decimal integer representation.
 *
 * Processes each binary digit from left to right, shifting the accumulated
 * result one bit to the left and adding the current bit.
 *
 * @param[in] binary The binary string to convert.
 * @param[out] decimal Pointer where the converted decimal value will be stored.
 * @param[in] length The number of binary digits in the input string.
 * @return int 0 on success, -1 on failure.
 */
int binconv_binary_to_decimal(const char *binary, int *decimal, size_t length) {
    if (!binary || !decimal || length == 0) {
        return -1;
    }

    int result = 0;

    for (size_t i = 0; i < length; i++) {
        int bit = binary[i] - '0';
        result = result * 2 + bit;
    }

    *decimal = result;

    return 0;
}