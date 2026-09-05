/*
 * binconv
 * Application Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <stdio.h>

#include "binconv/application.h"
#include "binconv/colors.h"

/**
 * @brief Displays the exit message.
 *
 * Displays the application's termination message before exiting.
 */
void binconv_print_exit(void) {
    printf("\n" COLOR_DIM "Bye, see you later!" COLOR_RESET "\n\n");
}

/**
 * @brief Displays the cancellation (interruption) message.
 *
 * Displays the application's cancellation message before exiting.
 */
void binconv_print_cancel(void) {
    printf("\n\n" COLOR_BOLD_YELLOW "ℹ " COLOR_RESET "Operation cancelled. " COLOR_DIM "Bye, see you later!" COLOR_RESET "\n\n");
}