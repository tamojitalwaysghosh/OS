#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
        pid_t pid;
        int pipeP2C[2];
        int pipeC2P[2];
        char buffer[25];
        if(pipe(pipeP2C)==0 && pipe(pipeC2P)==0){
                printf("\nsuccess\n");
        }
        pid=fork();
        if(pid>0){
                close(pipeP2C[0]);
                close(pipeC2P[1]);
                //write
                printf("\nparent writing\n");
                write(pipeP2C[1],"hello,child from parent",25);
                close(pipeP2C[1]);
                //read
                printf("\nparent reading\n");
                read(pipeC2P[0],buffer,25);
                printf("\nparent buffer has: %s\n",buffer);
                close(pipeC2P[0]);
        }
        else if(pid==0){
                close(pipeP2C[1]);
                close(pipeC2P[0]);

                //read
                printf("\nchild is reading\n");
                read(pipeP2C[0],buffer,25);
                printf("child buffer reads: %s",buffer);
