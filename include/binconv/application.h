/*
 * binconv
 * Application Public API
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_APPLICATION_H
#define BINCONV_APPLICATION_H

/**
 * @brief Displays the exit message.
 *
 * Displays the application's termination message before exiting.
 */
void binconv_print_exit(void);

/**
 * @brief Displays the cancellation (interruption) message.
 *
 * Displays the application's cancellation message before exiting.
 */
void binconv_print_cancel(void);

#endif