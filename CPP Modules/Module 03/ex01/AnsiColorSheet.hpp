#ifndef ANSI_COLOR_H
#define ANSI_COLOR_H

// ANSI color codes for text color
#define ANSI_COLOR_BLACK     "\x1b[30m"
#define ANSI_COLOR_RED       "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_YELLOW    "\x1b[33m"
#define ANSI_COLOR_BLUE      "\x1b[34m"
#define ANSI_COLOR_MAGENTA   "\x1b[35m"
#define ANSI_COLOR_CYAN      "\x1b[36m"
#define ANSI_COLOR_WHITE     "\x1b[37m"

#define ANSI_COLOR_BBLACK     "\x1b[90m"
#define ANSI_COLOR_BRED       "\x1b[91m"
#define ANSI_COLOR_BGREEN     "\x1b[92m"
#define ANSI_COLOR_BYELLOW    "\x1b[93m"
#define ANSI_COLOR_BBLUE      "\x1b[94m"
#define ANSI_COLOR_BMAGENTA   "\x1b[95m"
#define ANSI_COLOR_BCYAN      "\x1b[96m"
#define ANSI_COLOR_DWHITE     "\x1b[97m"


// ANSI color codes for text formatting
#define ANSI_BOLD            "\x1b[1m"
#define ANSI_UNDERLINE       "\x1b[4m"
#define ANSI_RESET           "\x1b[0m"

// ANSI color codes for logging
#define ANSI_ERROR          "\x1b[91m"
#define ANSI_WARN           "\x1b[93m"
#define ANSI_INFO           "\x1b[96m"

#endif /* ANSI_COLOR_H */