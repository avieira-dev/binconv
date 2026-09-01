/*
 * binconv
 * Numeric Converter Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binconv/colors.h"
#include "binconv/menu.h"
#include "binconv/signal.h"

/**
 * @brief Renders the CLI menu interface.
 *
 * This function is responsible only for outputting the visual
 * representation of the menu. It does not handle any input logic.
 */
void binconv_print_menu(void) {
    printf(COLOR_BOLD_BLUE "\n");

    printf("1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0\n"
           "0                                     1\n"
           "1              BINCONV                0\n"
           "0                                     1\n"
           "1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0\n"
    );

    printf(COLOR_RESET);

    printf("\n" COLOR_BOLD_WHITE "NUMERIC CONVERTER" COLOR_RESET "\n\n");

    printf(COLOR_CYAN "[1] " COLOR_RESET "Decimal → Binary\n");
    printf(COLOR_CYAN "[2] " COLOR_RESET "Binary → Decimal\n\n");

    printf(COLOR_CYAN "[0] " COLOR_RESET "Exit\n\n");

    printf("----------------------------------------------------------------\n\n");
}

/**
 * @brief Reads and validates the user's menu selection.
 *
 * Uses fgets and strtol to safely parse input and avoid undefined
 * behavior caused by scanf. Ensures full validation of input format,
 * including range checking and detection of invalid trailing characters.
 *
 * @param[out] out Pointer where the validated option will be stored.
 */
void binconv_read_menu_option(long *out) {
    char buffer[65];
    char *end_pointer;
    long menu_option;
    bool reading_input = true;

    while (reading_input) {
        printf("Select an option (0 - 2): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (binconv_was_interrupted()) {
                return;
            }

            printf(COLOR_RED "[ERROR] " COLOR_RESET "Failed to read input.\n");
            continue;
        }       

        errno = 0;
        menu_option = strtol(buffer, &end_pointer, 10);

        if (end_pointer == buffer || (*end_pointer != '\n' && *end_pointer != '\0') || errno == ERANGE) {
            printf(COLOR_RED "[ERROR] " COLOR_RESET "Invalid input, trailing characters, or out of range.\n");
            continue;
        }

        if (menu_option >= 0 && menu_option <= 2) {
            *out = menu_option;
            reading_input = false;
        } else {
            printf(COLOR_RED "[ERROR] " COLOR_RESET "Number must be between 0 and 2.\n");
        }
    }
}