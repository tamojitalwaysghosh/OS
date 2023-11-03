#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
     int pipefd[2];
     char buffer[25];
     pid_t pid;
     if(pipe(pipefd)==-1){
          //create pipe
          perror("pipe failed");
          return 1;
     }
     pid=fork();
     if(pid<0){
          //create child process
          perror("fork failed");
          return 1;
     }
     if(pid>0){
          //parent process
          close(pipefd[0]);//close read end of the pipe  
          printf("Parent process writing the pipe...\n");
          write(pipefd[1],"Hello, Child Process\n",25);
          close(pipefd[1]);//close the wrie end of the pipe
     }
     else{
          //child process
          close(pipefd[1]);//close the write end of pipe
          printf("Child process reading from pipe....\n");
          read(pipefd[0],buffer,25);
          printf("Child process received....:%s\n",buffer);
          close(pipefd[0]);//close the read end of the pipe
     }
     return 0;
}
                
