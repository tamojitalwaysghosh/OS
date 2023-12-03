#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

void *fun1();
void *fun2();

int shared=1;

sem_t s;

void main(){
        sem_init(&s,0,1);

        pthread_t thread1,thread2;

        pthread_create(&thread1,NULL,fun1,NULL);
        pthread_create(&thread2,NULL,fun2,NULL);

        pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);

        printf("\nFinal shared value of the variable is: %d\n",shared);
}

void *fun1(){
        int x;
        sem_wait(&s);
        x=shared;
        printf("\nThread1 reads the shared value as: %d\n",shared);
        x++;
        printf("\nLocal updation\n");
        sleep(1);
        shared=x;
        printf("\nThread1 updates it to: %d\n",shared);
        sem_post(&s);
}

void *fun2(){
        int y;
        sem_wait(&s);
        printf("\nThread2 reads the shared as: %d\n",shared);
        y=shared;
        y--;
        printf("\nLocal updation\n");
        sleep(1);
        shared=y;
        printf("\nThread2 update the shared as: %d\n",shared);
        sem_post(&s);
}
          
