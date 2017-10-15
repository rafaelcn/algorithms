#ifndef MACROS_H
#define MACROS_H


// ANSI color escaping sequences
#ifdef __linux__
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#endif // __linux__


// Useful macros

#define newline printf("\n");

#endif // MACROS_H
