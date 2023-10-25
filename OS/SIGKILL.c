#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void childProcess() {
    // Sleep for a moment to ensure the parent is running
    sleep(2);
    printf("Child process sending SIGSTOP to the parent...\n");
    
    // Send SIGSTOP signal to the parent process (getppid() returns the parent's PID)
    if (kill(getppid(), SIGSTOP) == -1) {
        perror("kill");
        exit(1);
    }
}

int main() {
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        childProcess();
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID: %d) started.\n", getpid());

        // Parent process will continue running
        while (1) {
            printf("Parent process running...\n");
            sleep(1);
        }
    }

    return 0;
}

============================================OUTPUT=============================================
Parent process (PID: 725) started.

Parent process running...

Parent process running...

Parent process running...

Child process sending SIGSTOP to the parent...
