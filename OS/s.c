#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define two semaphores
sem_t semaphore1, semaphore2;

//These functions modify the semaphore's internal state, so you need to pass pointers to the semaphore variables.
void* thread1_function(void* arg) {
    printf("Thread 1 is waiting...\n");
    sem_wait(&semaphore1);
    printf("Thread 1 is doing some work...\n");
    sem_post(&semaphore2);
    return NULL;
}

void* thread2_function(void* arg) {
    printf("Thread 2 is doing some work...\n");
    sem_post(&semaphore1);
    sem_wait(&semaphore2);
    printf("Thread 2 finished its work...\n");
    return NULL;
}


//Overall, void* is a common practice in multithreading to keep functions flexible and allow them to work with various types of data, which is particularly useful in the context of thread functions where the data type might not be known in advance.
//void* is a data type. It signifies that the function can accept a pointer to any type of data as an argument (arg), and it returns a pointer to data (in this case, it returns NULL). The * in void* indicates that it's a pointer to data, but the specific data type is not specified. This allows flexibility in the type of data that can be passed.

int main() {
    pthread_t thread1, thread2;

    // Initialize semaphores
    sem_init(&semaphore1, 0, 0);
    sem_init(&semaphore2, 0, 0);

    // Create two threads
    if (pthread_create(&thread1, NULL, thread1_function, NULL) != 0) {
        //In the pthread_create function, you need to pass the address of the function to execute (hence, a function pointer) as an argument.
        perror("pthread_create");
        exit(1);
    }
    if (pthread_create(&thread2, NULL, thread2_function, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    // Wait for the threads to finish
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join");
        exit(1);
    }
    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join");
        exit(1);
    }

    // Destroy the semaphores
    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);

    printf("Both threads have finished.\n");
    return 0;
}

==================OUTPUT======================
Thread 1 is waiting...
Thread 2 is doing some work...
Thread 1 is doing some work...
Thread 2 finished its work...
Both threads have finished.

/*
Semaphores:

Semaphores are a synchronization mechanism used to control access to shared resources in a multi-threaded or multi-process environment.
In this code, two semaphores, semaphore1 and semaphore2, are used to control the order of execution between two threads.


Thread Functions:

The code defines two functions, thread1_function and `thread2_function. These are the functions that will be executed by two threads.
thread1_function waits on semaphore1, does some work, and then posts to semaphore2.
thread2_function does some work, posts to semaphore1, and then waits on semaphore2.


Main Function:

In the main function, two threads, thread1 and thread2, are created using pthread_create. These threads run the functions thread1_function and thread2_function concurrently.
Two semaphores, semaphore1 and semaphore2, are initialized with an initial value of 0. This means that when threads try to wait on these semaphores, they will block initially until another thread posts to the semaphore.
The program then waits for both threads to finish their work using pthread_join. This ensures that the main program waits for the threads to complete before proceeding.
After the threads have finished, the semaphores are destroyed using sem_destroy.
A message is printed to indicate that both threads have finished.


Synchronization:

The semaphores are used to ensure that thread1 completes its work before thread2 starts and vice versa. They act as "gates" that control the order of execution between the two threads.
For example, thread1 waits on semaphore1, so it will block until another thread (in this case, thread2) posts to semaphore1.
thread2 waits on semaphore2, so it will block until thread1 posts to semaphore2.
This arrangement ensures that thread1 does some work first, followed by thread2, and vice versa.
Overall, this code demonstrates how semaphores can be used to synchronize the execution of threads, allowing you to control the order in which they perform tasks. It's a fundamental concept in operating systems and concurrent programming for managing shared resources and coordinating the activities of multiple threads or processes.
*/
