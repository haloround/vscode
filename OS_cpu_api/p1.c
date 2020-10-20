#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int x = 100;
	printf("before fork(),x = %d\n", x);

	pid = fork();
	if(pid < 0)
	{
		printf("fork failed\n");
		exit(1);
	}
	else if (pid == 0)
	{
		x = x + 100;
		printf("x + 100 = %d\n", x);
	}
	else
	{
		x = x + 200;
		printf("x + 200 = %d\n", x);
	}
	return 0;
}