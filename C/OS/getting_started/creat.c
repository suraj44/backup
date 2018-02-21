#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd = creat("a.txt", S_IRWXU|S_IWUSR|S_IRGRP|S_IROTH);
	printf("fd = %d\n", fd);
	return 0;
}