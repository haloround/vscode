#include <stdio.h>
#include <fcntl.h>
#include<assert.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  int buffer = open("./1.txt", O_CREAT | O_CREAT | O_WRONLY, S_IRWXU);
  assert(buffer > -1);

  int counter = 0;
  pid_t pid_1 = fork();

  if(pid_1 < 0) {
    perror("error in fork\n");
    exit(1);
  }
  else if (pid_1 == 0){
    counter = write(buffer, "child print :\n",14);
    assert(counter == 14);
    close(buffer);
    exit(0);
  }
  else
  {
    counter = write(buffer, "father print :\n", 15);
    assert(counter == 15);
    close(buffer);
    exit(0);
  }
  return 0;
}