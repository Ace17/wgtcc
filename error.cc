#include "error.h"

#include "token.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <string>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void Error(const Coordinate& coord, const char* format, ...)
{
    fprintf(stderr,  "%s:%d:%d: " ANSI_COLOR_RED "error: " ANSI_COLOR_RESET,
            coord.fileName, coord.line, coord.column);
    
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    
    fprintf(stderr, "\n    ");

    bool sawNoSpace = false;
    int nspaces = 0;
    for (auto p = coord.lineBegin; *p != '\n' && *p != 0; p++) {
        if (!sawNoSpace && (*p == ' ' || *p == '\t'))
            nspaces++;
        else {
            sawNoSpace = true;
            fputc(*p, stderr);
        }
    }
    
    fprintf(stderr, "\n    ");

    for (int i = 1; i + nspaces < coord.column; i++)
        fputc(' ', stderr);
    
    fprintf(stderr, ANSI_COLOR_GREEN "^\n");

    exit(0);
}