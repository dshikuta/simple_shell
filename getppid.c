#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 * Return: Always 0.
 */

int main(void)

{

	pid_t my_pid;

	my_pid = getpid();

	printf(" process ID %u\n", my_pid);
	
	my_pid = getppid();

	printf("process ID of the calling parent %u\n", my_pid);

	return (0);

}
