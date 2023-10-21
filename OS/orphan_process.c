#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID %d) is running with parent(PID %d).\n", getpid(),getppid());
        sleep(5); // Simulate some work
        printf("Child process (PID %d) is done with parent(PID %d).\n", getpid(),getppid());
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID %d) is running with parent(PID %d).\n", getpid(),getppid());
        // The parent process exits immediately, creating an orphan child process
        exit(0);
    }

    return 0;
}

================OUTPUT=======================
Parent process (PID 1826) is running with parent(PID 1604).
Child process (PID 1827) is running with parent(PID 1826).
~$ Child process (PID 1827) is done with parent(PID 1).
