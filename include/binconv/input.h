/*
 * binconv
 * Numeric Converter Public API
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_INPUT_H
#define BINCONV_INPUT_H

/**
 * @brief Safely reads a decimal integer from standard input.
 *
 * Prompts the user until a valid non-negative integer is provided,
 * preventing buffer overflows and handling parsing errors.
 *
 * @param[out] out Pointer where the validated decimal value will be stored.
 */
void binconv_read_decimal(long *out);

/**
 * @brief Waits for the user to press Enter before continuing.
 *
 * Displays a prompt and blocks program execution until the user
 * presses the Enter key. This function is intended to give the
 * user time to read information before the interface is refreshed.
 */
void binconv_wait_for_enter(void);

#endif