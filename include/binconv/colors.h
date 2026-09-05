/*
 * binconv
 * Colors
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_COLORS_H
#define BINCONV_COLORS_H

/*
 * Foreground colors
 */
#define COLOR_BLACK          "\033[30m"
#define COLOR_RED            "\033[31m"
#define COLOR_GREEN          "\033[32m"
#define COLOR_YELLOW         "\033[33m"
#define COLOR_BLUE           "\033[34m"
#define COLOR_MAGENTA        "\033[35m"
#define COLOR_CYAN            "\033[36m"
#define COLOR_WHITE          "\033[37m"

#define COLOR_GRAY           "\033[90m"
#define COLOR_BRIGHT_RED     "\033[91m"
#define COLOR_BRIGHT_GREEN   "\033[92m"
#define COLOR_BRIGHT_YELLOW  "\033[93m"
#define COLOR_BRIGHT_BLUE    "\033[94m"
#define COLOR_BRIGHT_MAGENTA "\033[95m"
#define COLOR_BRIGHT_CYAN    "\033[96m"
#define COLOR_BRIGHT_WHITE   "\033[97m"

/*
 * Background colors
 */
#define COLOR_BG_BLACK          "\033[40m"
#define COLOR_BG_RED            "\033[41m"
#define COLOR_BG_GREEN          "\033[42m"
#define COLOR_BG_YELLOW         "\033[43m"
#define COLOR_BG_BLUE           "\033[44m"
#define COLOR_BG_MAGENTA        "\033[45m"
#define COLOR_BG_CYAN           "\033[46m"
#define COLOR_BG_WHITE          "\033[47m"

#define COLOR_BG_GRAY           "\033[100m"
#define COLOR_BG_BRIGHT_RED     "\033[101m"
#define COLOR_BG_BRIGHT_GREEN   "\033[102m"
#define COLOR_BG_BRIGHT_YELLOW  "\033[103m"
#define COLOR_BG_BRIGHT_BLUE    "\033[104m"
#define COLOR_BG_BRIGHT_MAGENTA "\033[105m"
#define COLOR_BG_BRIGHT_CYAN    "\033[106m"
#define COLOR_BG_BRIGHT_WHITE   "\033[107m"

/*
 * Text styles
 */
#define COLOR_RESET         "\033[0m"
#define COLOR_BOLD          "\033[1m"
#define COLOR_DIM           "\033[2m"
#define COLOR_ITALIC        "\033[3m"
#define COLOR_UNDERLINE     "\033[4m"
#define COLOR_BLINK         "\033[5m"
#define COLOR_REVERSE       "\033[7m"
#define COLOR_HIDDEN        "\033[8m"
#define COLOR_STRIKETHROUGH "\033[9m"

/*
 * Common styled foreground colors
 */
#define COLOR_BOLD_BLACK   "\033[1;30m"
#define COLOR_BOLD_RED     "\033[1;31m"
#define COLOR_BOLD_GREEN   "\033[1;32m"
#define COLOR_BOLD_YELLOW  "\033[1;33m"
#define COLOR_BOLD_BLUE    "\033[1;34m"
#define COLOR_BOLD_MAGENTA "\033[1;35m"
#define COLOR_BOLD_CYAN    "\033[1;36m"
#define COLOR_BOLD_WHITE   "\033[1;37m"

#endif