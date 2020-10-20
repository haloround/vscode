#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  int w;
  pid_t pid_1 = fork();
  if(pid_1 < 0){
    perror("error in fork\n");
    exit(1);
  }
  else if (pid_1 == 0){
    pid_1 = wait(NULL);
    printf("child says %d\n", pid_1);
    exit(0);
  }
  else
  {
    pid_1 = wait(NULL);
    printf("parents says %d\n", pid_1);
    exit(0);
  }
  return 0;
}