#include <stdio.h>
#include <unistd.h>

/**
 * main - this is the entry point
 *
 * Return: Eachtime 0
 */
int main(void)
{
	pid_t child_pid;
	child_pid = getpid();
	printf("%u\n", child_pid);
	return (0);
}
