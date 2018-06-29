/**
 *                Universidade Tecnológica Federal do Paraná
 *
 * Copyright (c) 2017 Rafael Nunes <rafaelnunes@engineer.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include "utils.h"
#include "macros.h"

#include <stdio.h>

void error(char *msg, char *file, size_t line) {

    char err_buf[512];

    snprintf(err_buf, sizeof err_buf, "%sERR: %s. [%s:%zu] %s\n",
             ANSI_COLOR_RED,  msg, file, line, ANSI_COLOR_RESET);

    fprintf(stderr, err_buf);
}

void warn(char *msg, char *file, size_t line) {

    char err_buf[512];

    snprintf(err_buf, sizeof err_buf, "%sWARN: %s. [%s:%zu] %s\n",
             ANSI_COLOR_YELLOW,  msg, file, line, ANSI_COLOR_RESET);

    fprintf(stdout, err_buf);
}
