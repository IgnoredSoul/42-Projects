#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char command[MAX_COMMAND_LENGTH];

    // Get the current command line
    printf("Enter command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    
    char *home_dir = getenv("HOME");
    char homedir[1024];

    snprintf(homedir, 1024, "%s/.bash_history", home_dir);
    // Open the .bash_history file for appending
    FILE *history_file = fopen(homedir, "a");
    
    // Write the command and timestamp to the .bash_history file
    fprintf(history_file, "%s", command);
    
    // Close the .bash_history file
    fclose(history_file);

    return 0;
}
