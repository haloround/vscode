#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
  char buffer[6] = "iamlkx";
  pid_t pid_1 = fork();
  if (pid_1 < 0){
    perror("error in fork\n");
    exit(1);
  }
  else if (pid_1 == 0){
    printf("before STDOUT_FILENO\n");
    printf("but my name won't be output\n");
    close(STDOUT_FILENO);
    printf("%s", buffer);
  }
  else
  {
    pid_t pid = wait(NULL);
    printf("Wait: %d\n", pid);
  }
  return 0;
}