#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() {
    // Process ID of the target process to be killed
    pid_t targetProcessID;

    printf("Enter the Process ID of the target process to kill: ");
    scanf("%d", &targetProcessID);

    // Attempt to kill the process with SIGKILL
    if (kill(targetProcessID, SIGKILL) == 0) {
        printf("Process with PID %d killed successfully.\n", targetProcessID);
    } else {
        perror("Failed to kill the process");
    }

    return 0;
}


=============================OUTPUT====================================
~$ ps
    PID TTY          TIME CMD
   1343 pts/2    00:00:00 bash
   1708 pts/2    00:00:00 a.out
   1884 pts/2    00:00:00 a.out
   2264 pts/2    00:00:00 a.out
   2265 pts/2    00:00:00 a.out <defunct>
   2280 pts/2    00:00:00 a.out
   2281 pts/2    00:00:00 a.out <defunct>
   2360 pts/2    00:00:00 a.out
   2361 pts/2    00:00:00 a.out <defunct>
   2386 pts/2    00:00:00 a.out
   2387 pts/2    00:00:00 a.out <defunct>
   2502 pts/2    00:00:00 ps
~$ cc sigkill.c
~$ ./a.out
Enter the Process ID of the target process to kill: 2264
Process with PID 2264 killed successfully.
[3]   Killed                  ./a.out
