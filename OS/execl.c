#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // This code is executed by the child process

        // Replace the child process with a new program (e.g., /bin/ls)
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl fails, this part will be executed
        perror("exec failed");
        exit(1);
    } else {
        // This code is executed by the parent process
        printf("Parent process continues running...\n");

        // You can add more code for the parent process here if needed
        sleep(2); // Sleep for a moment
    }

    return 0;
}
==========Output same as ls -l============
