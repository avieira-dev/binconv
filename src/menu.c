#include "binconv/menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

/**
 * Renders the CLI menu interface.
 *
 * This function is responsible only for outputting the visual
 * representation of the menu. It does not handle any input logic.
 */
void print_menu() {

    printf("\033[1;34m");

    printf(" _     _                            \n"
            "| |__ (_)_ __   ___ ___  _ ____   __\n"
            "| '_ \\| | '_ \\ / __/ _ \\| '_ \\ \\ / /\n"
            "| |_) | | | | | (_| (_) | | | \\ V / \n"
            "|_.__/|_|_| |_|\\___\\___/|_| |_|\\_/\n");

    printf("\033[0m\nNUMERIC CONVERTER\n");
    printf("------------------------------------------\n\n");

    printf("\033[1;32m[1]\033[0m Decimal → Binary\n");
    printf("\033[1;32m[2]\033[0m Binary → Decimal\n\n");
    printf("\033[1;32m[0]\033[0m Exit\n\n");

    printf("------------------------------------------\n\n");
}

/**
 * Reads and validates the user's menu selection.
 *
 * Uses fgets + strtol to safely parse input and avoid undefined behavior
 * caused by scanf. Ensures full validation of input format, including
 * range checking and detection of invalid trailing characters.
 *
 * @param[out] out Pointer where the validated option will be stored.
 */
void read_menu_option(long *out) {

    char buf[65];
    char *end;
    long value;
    bool capture = true;

    while (capture) {
        printf("Select an option (0 - 2): ");

        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            printf("\033[0;31m[Error]\033[0m Failed to read input.\n");
            continue;
        }

        errno = 0;
        value = strtol(buf, &end, 10);

        if (end == buf || (*end != '\n' && *end != '\0') || errno == ERANGE) {
            printf("\033[0;31m[Error]\033[0m Invalid input, trailing characters, or out of range.\n");
            continue;
        }

        if (value >= 0 && value <= 2) {
            *out = value;
            capture = false;
        } else {
            printf("\033[0;31m[Error]\033[0m Number must be between 0 and 2.\n");
        }
    }
}