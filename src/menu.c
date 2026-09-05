/*
 * binconv
 * Menu Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "binconv/colors.h"
#include "binconv/input.h"
#include "binconv/menu.h"
#include "binconv/signal.h"
#include "binconv/terminal.h"

#define ESC "\x1b"

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
}

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
void binconv_read_menu_option(size_t *out, const char **options, size_t n) {
    size_t selected = 0;
    bool selecting = true;

    binconv_enable_raw_mode();
    printf(ESC "[?25l");

    while (selecting) {
        printf(COLOR_BOLD_WHITE COLOR_DIM "\rSelect Strategy: " COLOR_RESET COLOR_DIM "(Use ↑/↓ arrows and Enter)" COLOR_RESET "\n\n");
        for (size_t i = 0; i < n; i++) {
            if (i == selected) {
                printf(COLOR_BOLD_CYAN "❯ %s" COLOR_RESET "\n", options[i]);
            } else {
                printf("  %s\n", options[i]);
            }
        }

        int key = binconv_read_key();

        if (binconv_was_interrupted()) {
            selecting = false;
            continue;
        }

        if (key == 1000) {
            if (selected == 0) {
                selected = n - 1;
            } else {
                selected--;
            }
        } else if (key == 1001) {
            if (selected == n - 1) {
                selected = 0;
            } else {
                selected++;
            }
        } else if (key == '\r' || key == '\n') {
            selecting = false;
            continue;
        }

        printf(ESC "[%dA", (int)(n + 2));
        printf(ESC "[J");
    }

    printf(ESC "[?25h");
    binconv_disable_raw_mode();

    *out = selected;
}