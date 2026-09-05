/*
 * binconv
 * Input Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "binconv/colors.h"
#include "binconv/input.h"
#include "binconv/signal.h"

#define ESC '\x1b'

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
    char *end_pointer;
    long decimal_value;
    bool reading_input = true;

    while (reading_input) {
        printf("\nEnter a number greater than or equal to 0: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (binconv_was_interrupted()) {
                return;
            }

            printf(COLOR_RED "[Error] " COLOR_RESET "Failed to read input.\n");
            continue;
        }

        errno = 0;
        decimal_value = strtol(buffer, &end_pointer, 10);

        if (end_pointer == buffer || (*end_pointer != '\n' && *end_pointer != '\0') || errno == ERANGE) {
            printf(COLOR_RED "[Error] " COLOR_RESET "Invalid input, trailing characters, or out of range.\n");
            continue;
        }

        if (decimal_value >= 0) {
            *out = decimal_value;
            reading_input = false;
        } else {
            printf(COLOR_RED "[Error] " COLOR_RESET "The number must be greater than or equal to 0.\n");
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
    bool reading_input = true;

    while (reading_input) {
        printf("\nEnter a binary number (up to 64 bits): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (binconv_was_interrupted()) {
                return;
            }

            printf(COLOR_RED "[Error] " COLOR_RESET "Failed to read input.\n");
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
            printf(COLOR_RED "[Error] " COLOR_RESET "Invalid input, only '0' and '1' are allowed.\n");
            continue;
        }

        strcpy(out, buffer);

        *length = binary_length;
        reading_input = false;
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

/**
 * @brief Reads a single key from standard input.
 *
 * Reads individual keystrokes and translates supported terminal
 * escape sequences for the up and down arrow keys.
 *
 * @return int The key code read from input, or -1 on failure.
 */
int binconv_read_key(void) {
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) {
        return -1;
    }

    if (c == ESC) {
        char buf[2];
        if (read(STDIN_FILENO, &buf[0], 1) != 1) {
            return -1;
        }

        if (read(STDIN_FILENO, &buf[1], 1) != 1) {
            return -1;
        }

        if (buf[0] == '[') {
            switch (buf[1]) {
                case 'A':
                    return 1000;
                case 'B':
                    return 1001;
            }
        }
        return -1;
    }

    return (unsigned char)c;
}