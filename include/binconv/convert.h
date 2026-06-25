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
 * @param[in] value The decimal integer to convert.
 * @param[in] size The total size of the output buffer.
 * @return int 0 on success, -1 on failure.
 */
int binconv_decimal_to_binary(char *out, int value, size_t size);

#endif