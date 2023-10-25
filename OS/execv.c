#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *new_program = "/bin/ls"; // Path to the new program
    char *const new_program_args[] = {new_program, "-l", NULL};

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // This code is executed by the child process

        // Replace the child process with the new program
        execv(new_program, new_program_args);

        // If execv fails, this part will be executed
        perror("execv failed");
        exit(1);
    } else {
        // This code is executed by the parent process
        printf("Parent process continues running...\n");

        // You can add more code for the parent process here if needed
        sleep(2); // Sleep for a moment
    }

    return 0;
}
===========OUTPUT Same as ls -l===========
