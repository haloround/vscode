#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
  int n;
  int status;
  int fd[2];
  char buffer[99];
  
  if(pipe(fd) < 0){
    perror("pipe failed");
    exit(1);
  }
  int pid_1 = fork();
  if(pid_1 < 0){
    perror("error in fork\n");
    exit(1);
  }
  else if (pid_1 == 0)
  {
    close(fd[0]);
    write(fd[1], "i am lkx", 99);
    close(fd[1]);
    exit(0);
  }
  else
  {
    wait(NULL);
  }
  int pid_2 = fork();
  if (pid_2 < 0){
    printf("error in fork\n");
  }
  else if(pid_2 == 0){
    close(fd[1]);
    read(fd[0], buffer, 99);
    close(fd[0]);
    printf("pid_1 tell pid_2:%s\n",buffer);
    exit(0);
  }
  else
  {
    wait(NULL);
  }
  exit(1);
  return 0;
}