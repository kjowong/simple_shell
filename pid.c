#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	my_pid = getpid();
	printf("my_pid is %u\n", my_pid);
	return (0);
}
