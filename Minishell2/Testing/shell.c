#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_DISPLAYED_LINES 10

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int len, last_line = 0, arrow, row = 1, total_lines = 0;
    struct termios orig_termios, new_termios;

    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Save original terminal settings
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Turn off canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    // Count total number of lines in file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        total_lines++;
    }
    rewind(fp);

    // Display last few lines of file and handle arrow keys
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            // Found a complete line
            last_line = 1;
        }

        if (total_lines - row < MAX_DISPLAYED_LINES) {
            printf("\r%s", line);
            fflush(stdout);
        }
        row++;

        // Check for arrow keys
        arrow = getchar();
        if (arrow == 27) {
            // Arrow key was pressed
            arrow = getchar();
            if (arrow == 91) {
                // Arrow key sequence continued
                arrow = getchar();
                if (arrow == 65) {
                    // Up arrow was pressed
                    continue; // Do nothing
                }
                else if (arrow == 66) {
                    // Down arrow was pressed
                    if (last_line == 0 || !feof(fp)) {
                        fgets(line, MAX_LINE_LENGTH, fp);
                        printf("\r%s", line);
                        fflush(stdout);
                    }
                }
            }
        }
    }

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);

    fclose(fp);
    return 0;
}
