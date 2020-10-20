#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 50

int main(){
	char buf[SIZE] = {0};
	int ret = 0;
	int ret_open = 0;

	ret_open = open("hello.txt", O_RDONLY);
	if (ret_open < 0)
	{
		perror("open hello.txt error");
		return -1;
	}
	while(1){
		ret = read(ret_open, buf, SIZE - 1);
		if(0 == ret)
		{
			printf("-----finished-----\n");
			break;
		}
		else if (ret < 0)
		{
			perror("?");
			break;
		}
		printf("读取到%d个字节\n", ret);
		write(STDOUT_FILENO, buf, ret);
	}
	close(ret_open);
	return 0;
}
	