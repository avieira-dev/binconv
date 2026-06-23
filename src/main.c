#include "binconv/menu.h"

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

    while (running) {
        print_menu();

        read_menu_option(&option);

        switch (option) {
            case 0:
                printf("\n\033[0;34mBye, see you later!\033[0m\n\n");
                running = false;
                break;
            case 1: 
                printf("\nConversion: Decimal → Binary\n\n");
                break;
            case 2:
                printf("\nConversion: Binary → Decimal\n\n");
                break;
            default:
                break;
        }
    }

    return 0;
}