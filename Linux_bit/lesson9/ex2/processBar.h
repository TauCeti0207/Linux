#pragma once
#include <stdio.h>

extern void processbar(int rate);
extern void initbar();
#define NUM 102
#define STYLE '='
#define LOOPNUM 100
#define RIGHT '>'

#define GREEN "\033[0;32;32m"
#define NONE "\033[m"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
