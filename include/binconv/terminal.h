/*
 * binconv
 * Terminal Public API
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_TERMINAL_H
#define BINCONV_TERMINAL_H

/**
 * @brief Enables raw mode for terminal input.
 *
 * Configures the terminal to disable canonical input processing
 * and input echoing, allowing the application to read individual
 * keystrokes directly from standard input.
 */
void binconv_enable_raw_mode(void);

/**
 * @brief Restores the terminal's canonical input mode.
 *
 * Restores the terminal configuration saved before raw mode was
 * enabled and makes the cursor visible again.
 */
void binconv_disable_raw_mode(void);

#endif