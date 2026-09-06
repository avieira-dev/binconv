/*
 * binconv
 * Banner Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <stdio.h>

#include "binconv/banner.h"
#include "binconv/colors.h"

/**
 * @brief Displays the application banner in the terminal.
 *
 * Renders the application's visual banner using terminal colors.
 */
void binconv_print_banner(void) {
    printf(COLOR_BOLD_BLUE);

    printf(" _     _                            \n"
           "| |__ (_)__   ___ ___  _ ____   __\n"
           "| '_ \\| | '_ \\ / __/ _ \\| '_ \\ \\ / /\n"
           "| |_) | | | | | (_| (_) | | | \\ V / \n"
           "|_.__/|_|_| |_|\\___\\___/|_| |_|\\_/\n"
    );

    printf(COLOR_RESET "\n");

    printf(COLOR_BG_GREEN COLOR_BOLD_WHITE " v1.0.0 " COLOR_RESET);
    printf(COLOR_DIM " Number system conversions" COLOR_RESET);

    printf("\n\n");
}