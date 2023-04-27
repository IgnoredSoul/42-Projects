#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

char dirname[256];

void GetDir() {
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current directory: %s\n", cwd);

        // Find the last occurrence of the path separator character
        char *last_sep = strrchr(cwd, '/');
        if (last_sep != NULL) {
            // Extract the substring starting from the next character
            char *name = last_sep + 1;
            strcpy(dirname, name);

            // Check if the first letter is lowercase
            if (strlen(dirname) > 0 && islower(dirname[0])) {
                dirname[0] = toupper(dirname[0]);
            }

            printf("Current directory name: %s\n", dirname);
        }
    } else {
        perror("getcwd() error");
    }
}

int main()
{
    GetDir();
    printf("%s ", dirname);
}

