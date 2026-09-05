/*
 * binconv
 * Menu Public API
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
 * showing available conversion options and the exit option.
 */
void binconv_print_menu(void);

/**
 * @brief Displays and reads the interactive menu selection.
 *
 * Enables raw terminal input, allows the user to navigate through
 * the available options using the arrow keys, and stores the
 * selected option when Enter is pressed.
 *
 * @param[out] out Pointer where the selected option index will be stored.
 * @param[in] options Array containing the available option labels.
 * @param[in] n Number of available options.
 */
void binconv_read_menu_option(size_t *out, const char **options, size_t n);

#endif