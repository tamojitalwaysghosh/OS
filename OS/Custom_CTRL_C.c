#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global flag to track whether Ctrl+C behavior is modified
int customCtrlCBehavior = 0;

// Signal handler function for Ctrl+C (SIGINT)
void customCtrlCHandler(int signum) {
    while(!customCtrlCBehavior){
        printf("\n$$Ctrl+C doing some unknown fubction$$\n");
        printf("Do you want default function:(0/1) ");
        scanf("%d",&customCtrlCBehavior);
    }
    if(customCtrlCBehavior){
        exit(0);
    }
}

int main() {
    // Register the custom Ctrl+C handler
    signal(SIGINT, customCtrlCHandler);

    printf("Press Ctrl+C to see the custom behavior. Press it again to restore default behavior.\n");

    //running an infinite loop to make use of Ctrl+C
    while(1){
        printf("\nHI\n");
        sleep(1);
    }

    return 0;
}

=====================OUTPUT========================
  Press Ctrl+C to see the custom behavior. Press it again to restore default behavior.

HI

HI

HI

HI

HI
^C
$$Ctrl+C doing some unknown fubction$$
Do you want default function:(0/1) 0

$$Ctrl+C doing some unknown fubction$$
Do you want default function:(0/1) 1
                                                                                                                                                34,1          Bot
