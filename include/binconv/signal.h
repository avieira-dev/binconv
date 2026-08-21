/*
 * binconv
 * Signal Public API
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#ifndef BINCONV_SIGNAL_H
#define BINCONV_SIGNAL_H

#include <stdbool.h>

/**
 * @brief Registers the application's signal handlers.
 *
 * Configures the signals handled by the application.
 */
void binconv_setup_signals(void);

/**
 * @brief Checks whether the application received SIGINT.
 *
 * @return true if SIGINT was received, false otherwise.
 */
bool binconv_was_interrupted(void);

#endif