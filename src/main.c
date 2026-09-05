/*
 * binconv
 * Main Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "binconv/application.h"
#include "binconv/colors.h"
#include "binconv/convert.h"
#include "binconv/help.h"
#include "binconv/input.h"
#include "binconv/menu.h"
#include "binconv/signal.h"

/**
 * @brief Entry point of the application.
 *
 * Controls the main program loop, delegating user interaction
 * to the appropriate modules and handling the selected option.
 *
 * @return int 0 on successful execution.
 */
int main(int argc, char *argv[]) {
    const char *options[] = {"Decimal → Binary", "Binary → Decimal", "Exit"};
    size_t n = sizeof(options) / sizeof(options[0]);

    if (argc == 1) {
        binconv_setup_signals();

        size_t menu_option;
        bool running = true;
        long decimal_value = 0;
        char binary_buffer[65];
        char binary_value[65];
        size_t binary_length;
        int decimal_result;

        while (running) {
            binconv_print_menu();

            binconv_read_menu_option(&menu_option, options, n);

            if (binconv_was_interrupted()) {
                binconv_print_cancel();
                break;
            }

            switch (menu_option) {
                case 0:
                    binconv_read_decimal(&decimal_value);

                    if (binconv_was_interrupted()) {
                        binconv_print_cancel();
                        running = false;
                        break;
                    }

                    binconv_decimal_to_binary(binary_buffer, decimal_value, sizeof(binary_buffer));

                    printf("\n==========================\n");
                    printf(COLOR_BOLD_WHITE "Conversion Result" COLOR_RESET "\n\n");
                    printf("Decimal: %ld\nBinary: %s\n", decimal_value, binary_buffer);
                    printf("==========================\n");

                    binconv_wait_for_enter();
                    break;

                case 1:
                    binconv_read_binary(binary_value, &binary_length);

                    if (binconv_was_interrupted()) {
                        binconv_print_cancel();
                        running = false;
                        break;
                    }

                    binconv_binary_to_decimal(binary_value, &decimal_result, binary_length);

                    printf("\n==========================\n");
                    printf(COLOR_BOLD_WHITE "Conversion Result" COLOR_RESET "\n\n");
                    printf("Binary: %s\nDecimal: %d\n", binary_value, decimal_result);
                    printf("==========================\n");

                    binconv_wait_for_enter();
                    break;

                case 2:
                    binconv_print_exit();
                    running = false;
                    break;

                default:
                    break;
            }

            if (running) {
                printf("\n----------------------------------------------------------------\n");
            }
        }

        return 0;
    } else if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            binconv_print_help();
            return 0;
        } else {
            printf(COLOR_BOLD_RED "[ERROR] " COLOR_RESET "Invalid command. Use " COLOR_BOLD_WHITE "'binconv -h'" COLOR_RESET " or " COLOR_BOLD_WHITE "'binconv --help'" COLOR_RESET ".\n");
            return 0;
        }
    } else {
        printf(COLOR_BOLD_RED "[ERROR] " COLOR_RESET "Invalid number of arguments. Use " COLOR_BOLD_WHITE "'binconv -h'" COLOR_RESET " or " COLOR_BOLD_WHITE "'binconv --help'" COLOR_RESET ".\n");
        return 0;
    }
}