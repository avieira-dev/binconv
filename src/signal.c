/*
 * binconv
 * Signal Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <signal.h>
#include <stdbool.h>

#include "binconv/signal.h"

static volatile sig_atomic_t interrupted = 0;

/**
 * @brief Handles the SIGINT signal.
 *
 * Sets the internal interrupted flag when SIGINT is received.
 *
 * @param sig The signal number received.
 */
static void handle_sigint(int sig) {
    (void)sig;
    interrupted = 1;
}

/**
 * @brief Registers the application's signal handlers.
 *
 * Configures the signals handled by the application.
 */
void binconv_setup_signals(void) {
    signal(SIGINT, handle_sigint);
}

/**
 * @brief Checks whether the application received SIGINT.
 *
 * @return true if SIGINT was received, false otherwise.
 */
bool binconv_was_interrupted(void) {
    return interrupted != 0;
}