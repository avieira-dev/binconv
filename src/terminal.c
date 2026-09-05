/*
 * binconv
 * Terminal Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "binconv/terminal.h"

#define ESC "\x1b"

static struct termios canonical_mode;
static int raw_mode_enabled = 0;
static int exit_handler_registered = 0;

/**
 * @brief Enables raw mode for terminal input.
 *
 * Saves the current terminal configuration and disables canonical
 * input processing and input echoing. Registers the terminal
 * restoration handler for normal program termination.
 */
void binconv_enable_raw_mode(void) {
    if (raw_mode_enabled) {
        return;
    }

    if (tcgetattr(STDIN_FILENO, &canonical_mode) == -1) {
        return;
    }

    struct termios raw_mode = canonical_mode;

    raw_mode.c_lflag &= ~(ECHO | ICANON);
    raw_mode.c_cc[VMIN] = 1;
    raw_mode.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_mode) == -1) {
        return;
    }

    raw_mode_enabled = 1;

    if (!exit_handler_registered) {
        if (atexit(binconv_disable_raw_mode) == 0) {
            exit_handler_registered = 1;
        }
    }
}

/**
 * @brief Restores the terminal's canonical input mode.
 *
 * Restores the terminal configuration saved before raw mode was
 * enabled and makes the cursor visible again.
 */
void binconv_disable_raw_mode(void) {
    if (!raw_mode_enabled) {
        return;
    }

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &canonical_mode);

    raw_mode_enabled = 0;

    printf(ESC "[?25h");
    fflush(stdout);
}