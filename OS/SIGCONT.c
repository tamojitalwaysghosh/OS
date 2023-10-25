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

    // Sleep again to simulate a paused parent process
    sleep(2);
    printf("Child process sending SIGCONT to the parent...\n");

    // Send SIGCONT signal to the parent process to resume it
    if (kill(getppid(), SIGCONT) == -1) {
        perror("kill");
        exit(1);
    }

    //stopping the parent process to prevent infinite loop
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
        printf("Parent process (PID: %d) started.\n",getpid());

        // Parent process will continue running
        while (1) {
            printf("Parent process running...\n");
            sleep(1);
        }
    }

    return 0;
}

==============================OUTPUT=================================
  Parent process (PID: 2360) started.
Parent process running...
Parent process running...
Child process sending SIGSTOP to the parent...
Parent process running...

[5]+  Stopped                 ./a.out
~$ Child process sending SIGCONT to the parent...
Parent process running...
Parent process running...
Child process sending SIGSTOP to the parent...
