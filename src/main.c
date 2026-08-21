/*
 * binconv
 * Numeric Converter Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include "binconv/application.h"
#include "binconv/convert.h"
#include "binconv/input.h"
#include "binconv/menu.h"
#include "binconv/signal.h"

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Entry point of the application.
 *
 * Controls the main program loop, delegating user interaction
 * to the appropriate modules and handling the selected option.
 *
 * @return int 0 on successful execution.
 */
int main(void) {
    binconv_setup_signals();

    long menu_option;
    bool running = true;
    long decimal_value = 0;
    char binary_buffer[65];
    char binary_value[65];
    size_t binary_size;
    int decimal_result;

    while (running) {
        binconv_print_menu();

        binconv_read_menu_option(&menu_option);

        if (binconv_was_interrupted()) {
            binconv_exit();
            break;
        }

        switch (menu_option) {
            case 0:
                binconv_exit();
                running = false;
                break;
                
            case 1:
                binconv_read_decimal(&decimal_value);

                if (binconv_was_interrupted()) {
                    binconv_exit();
                    running = false;
                    break;
                }

                binconv_decimal_to_binary(binary_buffer, decimal_value, sizeof(binary_buffer));

                printf("\n==========================\n");
                printf("\033[1;37mConversion Result\033[0m\n\n");
                printf("Decimal: %ld\nBinary: %s\n", decimal_value, binary_buffer);
                printf("==========================\n");

                binconv_wait_for_enter();
                break;

            case 2:
                binconv_read_binary(binary_value, &binary_size);

                if (binconv_was_interrupted()) {
                    binconv_exit();
                    running = false;
                    break;
                }

                binconv_binary_to_decimal(binary_value, &decimal_result, binary_size);

                printf("\n==========================\n");
                printf("\033[1;37mConversion Result\033[0m\n\n");
                printf("Binary: %s\nDecimal: %d\n", binary_value, decimal_result);
                printf("==========================\n");

                binconv_wait_for_enter();
                break;

            default:
                break;
        }

        if (running) {
            printf("\n----------------------------------------------------------------\n");
        }
    }

    return 0;
}