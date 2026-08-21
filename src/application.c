/*
 * binconv
 * Application Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include "binconv/application.h"

#include <stdio.h>

/**
 * @brief Displays the exit message.
 *
 * Displays the application's termination message before exiting.
 */
void binconv_exit(void) {
    printf("\n\033[0;34mBye, see you later!\033[0m\n");
}