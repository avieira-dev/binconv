/*
 * binconv
 * Numeric Converter Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <binconv/input.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

/**
 * Reads and validates a non-negative decimal number from the user.
 *
 * Employs fgets and strtol to clear buffer overflow vectors and
 * explicitly ensures no trailing garbage characters or out-of-range values exist.
 */
void binconv_read_decimal(long *out) {

    char buffer[65];
    char *end;
    long value;
    bool capture = true;

    while (capture) {
        printf("Enter a number greater than or equal to 0: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\033[0;31m[Error]\033[0m Failed to read input.\n");
            continue;
        }

        errno = 0;
        value = strtol(buffer, &end, 10);

        if (end == buffer || (*end != '\n' && *end != '\0') || errno == ERANGE) {
            printf("\033[0;31m[Error]\033[0m Invalid input, trailing characters, or out of range.\n");
            continue;
        }

        if (value >= 0) {
            *out = value;
            capture = false;
        } else {
            printf("\033[0;31m[Error]\033[0m The number must be greater than or equal to 0.\n");
        }
    }
}

/**
 * Waits for the user to acknowledge the current screen.
 *
 * Continuously reads characters from stdin until a newline character
 * or EOF is encountered, ensuring the application resumes only after
 * the user presses Enter.
 */
void binconv_wait_for_enter(void) {

    int ch;

    printf("\nPress Enter to continue...");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
    }
}