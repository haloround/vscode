#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork();
  if (pid < 0) {
    perror("error in fork\n");
    exit(1);
  }
  else if (pid == 0)
  {
    printf("hello ");
    exit(0);
  }
  else
  {
    sleep(1);
    printf("goodbye\n");
    exit(0);
  }
  return 0;
}