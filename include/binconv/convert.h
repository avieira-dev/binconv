/*
 * binconv
 * Numeric Converter Public API
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_CONVERT_H
#define BINCONV_CONVERT_H

#include <stddef.h>

/**
 * @brief Converts a decimal integer to its binary string representation.
 *
 * @param[out] out Pointer to the buffer where the binary string will be stored.
 * @param[in] value The non-negative decimal integer to convert.
 * @param[in] size The total size of the output buffer.
 * @return int 0 on success, -1 on failure.
 */
int binconv_decimal_to_binary(char *out, long value, size_t size);

/**
 * @brief Converts a binary string to its decimal integer representation.
 *
 * @param[in] binary The binary string to convert.
 * @param[out] decimal Pointer where the converted decimal value will be stored.
 * @param[in] length The number of binary digits in the input string.
 * @return int 0 on success, -1 on failure.
 */
int binconv_binary_to_decimal(const char *binary, int *decimal, size_t length);

#endif