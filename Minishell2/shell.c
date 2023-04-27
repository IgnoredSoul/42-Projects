#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

char dirname[256];
void Get_Dir() {
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        char *last_sep = strrchr(cwd, '/');
        if (last_sep != NULL) {
            char *name = last_sep + 1;
            strcpy(dirname, name);

            if (strlen(dirname) > 0 && islower(dirname[0])) {
                dirname[0] = toupper(dirname[0]);
            }
        }
    }
}

char hostname[10];
void Get_Hostname() {
    char htnm[1024];
    if (gethostname(htnm, 1024) == 0) {
        strncpy(hostname, htnm, 6);
        hostname[strlen(hostname)] = '\0';
    } else {
        perror("gethostname");
    }
}

char username[256];
void Get_Username(){
    char *usrnm = getenv("USER");
    strcpy(username, usrnm);
}


#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// Function to split the command string into tokens
int tokenize(char *cmd, char **tokens) {
    int num_tokens = 0;
    char *token = strtok(cmd, " \n");
    while (token != NULL && num_tokens < MAX_NUM_TOKENS - 1) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " \n");
    }
    tokens[num_tokens] = NULL;
    return num_tokens;
}

// Function to search for and load a command from the commands directory
int load_command(char *command_name) {
    char path[256];
    DIR *dirp;
    struct dirent *entry;

    // Open the commands directory
    dirp = opendir("commands");
    if (dirp == NULL) {
        perror("opendir");
        return -1;
    }

    // Loop through all entries in the directory
    while ((entry = readdir(dirp)) != NULL) {
        // Ignore directories and hidden files
        if (entry->d_type != DT_REG || entry->d_name[0] == '.') {
            continue;
        }

        // Build the path to the command
        sprintf(path, "commands/%s", entry->d_name);

        // If the command matches the specified command name, load and execute it
        if (strcmp(entry->d_name, command_name) == 0) {
            printf("Loading command: %s\n", path);
            execl(path, entry->d_name, NULL);
            closedir(dirp);
            return 0;
        }
    }

    closedir(dirp);
    printf("Command not found: %s\n", command_name);
    return -1;
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_TOKENS];
    int num_tokens;

    while (1) {
        // Print the prompt
        printf("$ ");

        // Read the input from the user
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Tokenize the input
        num_tokens = tokenize(input, tokens);

        // If there are no tokens, continue to the next loop iteration
        if (num_tokens == 0) {
            continue;
        }

        // If the token is "exit", break out of the loop and exit the program
        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        // Load and execute the command from the commands directory
        load_command(tokens[0]);
    }

    return 0;
}
