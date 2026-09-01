/*
 * binconv
 * Signal Implementation
 *
 * Copyright (c) 2026 Alexandre Vieira
 * Licensed under the MIT License.
 */

#include <signal.h>

#include "binconv/signal.h"

static volatile sig_atomic_t interrupted = 0;

static void handle_sigint(int signal) {
    (void)signal;
    interrupted = 1;
}

void binconv_setup_signals(void) {
    signal(SIGINT, handle_sigint);
}

bool binconv_was_interrupted(void) {
    return interrupted != 0;
}