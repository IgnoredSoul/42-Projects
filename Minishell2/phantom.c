#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "phantom.h"

void handle_error(char *msg){
    printf("Phantom: %s", msg);
}

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

void sigint_handler() {
    char cwd[FILENAME_MAX];
    char *relpath = get_relative_path(cwd, sizeof(cwd));
    printf("\n%s┌──(%sPhantom ✝ Console%s)-[%s%s%s%s]", ANSI_COLOR_BCYAN, ANSI_COLOR_BMAGENTA, ANSI_COLOR_BCYAN, ANSI_COLOR_WHITE, ANSI_BOLD, relpath, ANSI_COLOR_BCYAN);
    printf("\n└─%s$%s ", ANSI_COLOR_BMAGENTA, ANSI_RESET);  
    fflush(stdout);
}

void handle_quit() {
    printf("Catch ya later mate\n");
    sleep(1.5);
    exit(0);
}

int main() {
    while(1)
    {
        signal(SIGINT, sigint_handler);

        char pipeline[100];
        char cwd[FILENAME_MAX];
        char *relpath = get_relative_path(cwd, sizeof(cwd));

        printf("%s┌──(%sPhantom ✝ Console%s)-[%s%s%s%s]", ANSI_COLOR_BCYAN, ANSI_COLOR_BMAGENTA, ANSI_COLOR_BCYAN, ANSI_COLOR_WHITE, ANSI_BOLD, relpath, ANSI_COLOR_BCYAN);
        printf("\n└─%s$%s ", ANSI_COLOR_BMAGENTA, ANSI_RESET);  

        if(fgets(pipeline, sizeof(pipeline), stdin) == NULL){
            handle_quit();
        }else{
            // Remove newline character from the end of the command
            pipeline[strcspn(pipeline, "\n")] = 0;

            if (strcmp(pipeline, "exit") == 0) {
                exit(1);
            } else if (strncmp(pipeline, "cd ", 3) == 0) {
                // Change directory using chdir()
                if (chdir(pipeline + 3) != 0) {
                    handle_error("No such directory\n");
                }
            }else{
                FILE* fp = popen(pipeline, "r");
                if (fp == NULL) {
                    printf("Error executing pipeline\n");
                    return 1;
                }

                char response[1024];
                while (fgets(response, sizeof(response), fp) != NULL) {
                    printf("%s", response);
                }

                pclose(fp);
            }
        }
    }
    return 0;
}
