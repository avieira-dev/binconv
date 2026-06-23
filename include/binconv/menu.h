#ifndef BINCONV_MENU_H
#define BINCONV_MENU_H

/**
 * @brief Displays the main application menu in the terminal.
 *
 * Responsible only for rendering the textual user interface,
 * showing available conversion options and exit option.
 */
void print_menu();

/**
 * @brief Reads and validates the user menu selection.
 *
 * Waits for user input from stdin, performs safe parsing,
 * and ensures the value is within the allowed range.
 *
 * @param[out] out Pointer where the validated option will be stored.
 */
void read_menu_option(long *out);

#endif