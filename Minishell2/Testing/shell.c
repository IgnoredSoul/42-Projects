#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "ansi-color.h"

char *get_relative_path(char *cwd, size_t size) {
    if (getcwd(cwd, size) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }

    char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "HOME environment variable not set\n");
        exit(EXIT_FAILURE);
    }

    size_t home_dir_len = strlen(home_dir);
    if (strncmp(cwd, home_dir, home_dir_len) == 0) {
        cwd[0] = '~';
        memmove(&cwd[1], &cwd[home_dir_len], strlen(&cwd[home_dir_len]) + 1);
    }

    return cwd;
}

void handle_error(char *msg){
    printf("Phantom: %s\n", msg);
}

void sigint_handler(int sig) {
    printf("Ctrl+C detected\n");
    // Add code to handle the signal here
}

int main() {
    char command[100];
    char *args[10];
    char *token;
    int num_args;
    int cyan = 96;

    while (1) {
        char cwd[FILENAME_MAX];
        char *relpath = get_relative_path(cwd, sizeof(cwd));
        printf("%s┌──(%sPhantom ✝ Console%s)-[%s%s%s%s]", ANSI_COLOR_BCYAN, ANSI_COLOR_BMAGENTA, ANSI_COLOR_BCYAN, ANSI_COLOR_WHITE, ANSI_BOLD, relpath, ANSI_COLOR_BCYAN);
        printf("\n└─%s$%s ", ANSI_COLOR_BMAGENTA, ANSI_RESET);
        fgets(command, sizeof(command), stdin);

        // Remove newline character from the end of the command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strncmp(command, "cd ", 3) == 0) {
            // Change directory using chdir()
            if (chdir(command + 3) != 0) {
                handle_error("No such directory\n");
            }
        } else {
            // Parse command line arguments
            num_args = 0;
            token = strtok(command, " ");
            while (token != NULL) {
                args[num_args] = token;
                num_args++;
                token = strtok(NULL, " ");
            }
            args[num_args] = NULL;

            // Execute command using execvp()
            if (fork() == 0) {
                for(int i = 0; i < num_args; i++)
                {
                    printf("(%s) ", args[i]);
                }
                
                printf("(%d)\n", num_args);


                execvp(args[0], args);
                handle_error("Could not execute command\n");
                exit(1);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}
