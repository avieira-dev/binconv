/*
 * binconv
 * Numeric Converter Public API
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_INPUT_H
#define BINCONV_INPUT_H

#include <stddef.h>

/**
 * @brief Safely reads a non-negative decimal integer from standard input.
 *
 * Prompts the user until a valid non-negative integer is provided,
 * preventing buffer overflows and handling parsing errors.
 *
 * @param[out] out Pointer where the validated decimal value will be stored.
 */
void binconv_read_decimal(long *out);

/**
 * @brief Safely reads a binary number from standard input.
 *
 * Prompts the user until a valid binary number containing only '0' and
 * '1' characters is provided.
 *
 * @param[out] out Buffer where the binary string will be stored.
 * @param[out] length Pointer where the binary string length will be stored.
 */
void binconv_read_binary(char *out, size_t *length);

/**
 * @brief Waits for the user to press Enter before continuing.
 *
 * Displays a prompt and blocks program execution until the user
 * presses the Enter key. This function is intended to give the
 * user time to read information before the interface is refreshed.
 */
void binconv_wait_for_enter(void);

#endif