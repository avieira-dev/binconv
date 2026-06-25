/*
 * binconv
 * Numeric Converter Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include "binconv/menu.h"
#include "binconv/convert.h"
#include "binconv/input.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * Entry point of the application.
 *
 * Controls the main program loop, delegating all user interaction
 * to the menu module and handling the selected option.
 */
int main(void) {

    long option;
    bool running = true;
    long value = 0;
    char buffer[32];

    while (running) {
        binconv_print_menu();

        binconv_read_menu_option(&option);

        switch (option) {
            case 0:
                printf("\n\033[0;34mBye, see you later!\033[0m\n");
                running = false;
                break;
            case 1: 
                binconv_read_decimal(&value);
                binconv_decimal_to_binary(buffer, value, sizeof(buffer));
                printf("\n==========================\n");
                printf("\033[1;37mConversion Result\033[0m\n\n");
                printf("Decimal: %ld\nBinary: %s\n", value, buffer);
                printf("==========================\n");
                binconv_wait_for_enter();
                break;
            case 2:
                printf("\nConversion: Binary → Decimal\n\n");
                break;
            default:
                break;
        }

        printf("\n----------------------------------------------------------------\n");
    }

    return 0;
}