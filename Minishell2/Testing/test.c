#include <stdio.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("Ctrl+C detected\n");
    // Add code to handle the signal here
}

int main() {
    // Register the signal handler
    signal(SIGINT, sigint_handler);

    // Add your main code here
    while (1) {
        // Do some work here
    }

    return 0;
}