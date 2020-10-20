//exec()
//https://www.cnblogs.com/memset/p/linux_exec_function_family.html

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//
int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("error in fork\n");
    exit(1);
  }
  else if (pid == 0)
  {
    /* code */
    execl("/bin/ls","ls",NULL);
    //execlp("/bin/ls",NULL);
    //execle("/bin/ls", "ls");

    //ececv("/bin/ls", NULL);
    //execvp("ls",NULL);
    //execve("binl/ls",NULL, NULL);
    exit(0);
  }
  else
  {
    /* code */
    printf("i am father\n");
    exit(0);
  }
  return 0;
}