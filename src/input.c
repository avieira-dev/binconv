/*
 * binconv
 * Numeric Converter Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include "binconv/signal.h"
#include "binconv/input.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Reads and validates a non-negative decimal number from the user.
 *
 * Employs fgets and strtol to safely parse the input and explicitly
 * ensures that no trailing garbage characters or out-of-range values exist.
 *
 * @param[out] out Pointer where the validated decimal value will be stored.
 */
void binconv_read_decimal(long *out) {
    char buffer[65];
    char *end;
    long value;
    bool capture = true;

    while (capture) {
        printf("Enter a number greater than or equal to 0: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (binconv_was_interrupted()) {
                return;
            }

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
 * @brief Reads and validates a binary number from the user.
 *
 * Prompts the user until a valid binary number containing only '0' and
 * '1' characters is provided. The input is limited to 64 binary digits.
 *
 * @param[out] out Buffer where the binary string will be stored.
 * @param[out] length Pointer where the binary string length will be stored.
 */
void binconv_read_binary(char *out, size_t *length) {
    char buffer[65];
    size_t binary_length;
    bool capture = true;

    while (capture) {
        printf("Enter a binary number (up to 64 bits): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (binconv_was_interrupted()) {
                return;
            }

            printf("\033[0;31m[Error]\033[0m Failed to read input.\n");
            continue;
        }

        binary_length = strlen(buffer);

        if (buffer[binary_length - 1] == '\n') {
            buffer[binary_length - 1] = '\0';
            binary_length--;
        }

        bool valid = true;

        for (size_t i = 0; i < binary_length; i++) {
            if (buffer[i] != '0' && buffer[i] != '1') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            printf("\033[0;31m[Error]\033[0m Invalid input, only '0' and '1' are allowed.\n");
            continue;
        }

        strcpy(out, buffer);

        *length = binary_length;
        capture = false;
    }
}

/**
 * @brief Waits for the user to acknowledge the current screen.
 *
 * Continuously reads characters from stdin until a newline character
 * or EOF is encountered, ensuring the application resumes only after
 * the user presses Enter.
 */
void binconv_wait_for_enter(void) {
    int character;

    printf("\nPress Enter to continue...");

    while ((character = getchar()) != '\n' && character != EOF) {
        ;
    }
}