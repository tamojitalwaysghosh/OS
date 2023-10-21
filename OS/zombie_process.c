//Zombie processes in C are created when a child process finishes its execution, 
// but its parent process does not call the wait or waitpid system call to collect 
// the exit status of the child. As a result, the terminated child process remains 
// in the process table, consuming system resources, until it is 
// reaped by the parent or by the system.

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
        printf("Child process (PID %d) is running.\n", getpid());
        // Child process exits immediately
        exit(0);
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID %d) is running.\n", getpid());
        // The parent does not wait for the child
        sleep(10); // Sleep for a while
        //call wait(NULL) to collect the exit status of the child process
        printf("Parent process (PID %d) is done.\n", getpid());
    }

    return 0;
}
