/*
 * binconv
 * Numeric Converter Public API
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_MENU_H
#define BINCONV_MENU_H

/**
 * @brief Displays the main application menu in the terminal.
 *
 * Responsible only for rendering the textual user interface,
 * showing available conversion options and exit option.
 */
void binconv_print_menu();

/**
 * @brief Reads and validates the user menu selection.
 *
 * Waits for user input from stdin, performs safe parsing,
 * and ensures the value is within the allowed range.
 *
 * @param[out] out Pointer where the validated option will be stored.
 */
void binconv_read_menu_option(long *out);

#endif