/*
 * binconv
 * Help Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <stdio.h>

#include "binconv/banner.h"
#include "binconv/colors.h"
#include "binconv/help.h"

/**
 * @brief Displays the application's help information.
 *
 * Renders the application banner and provides usage information,
 * available commands, examples, and project authorship.
 */
void binconv_print_help(void) {
    binconv_print_banner();

    printf(COLOR_BOLD_WHITE "Usage: " COLOR_RESET "binconv <command>\n\n");

    printf(COLOR_BOLD_WHITE "Available Commands:" COLOR_RESET "\n");
    printf(COLOR_BOLD_CYAN " --help or -h" COLOR_RESET " Shows this help message\n");

    printf("\n" COLOR_BOLD_WHITE "Examples:" COLOR_RESET "\n");
    printf(" $ binconv\n");
    printf(" $ binconv -h\n");
    printf(" $ binconv --help\n");

    printf("\n" COLOR_DIM "Created by Alexandre Vieira (https://github.com/avieira-dev)" COLOR_RESET "\n\n");
}