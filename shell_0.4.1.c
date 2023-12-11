#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_exit_command - function for handling exit command
 * @argc: counts the integer
 * @argv: array of strings
 */
void handle_exit_command(int argc, char *argv[])
{
	if (argc > 1 && strcmp(argv[1], "exit") == 0)
	{
		if (argc > 2)
		{
			/* Converts status argument to integer */
			int exit_status = atoi(argv[2]);

			exit(exit_status);
		} else
		{
			/* Exit with status 98, if no status provided */
			exit(98);
		}
	}
}

/**
 * main - This is entry point
 * @argc: counts the integer
 * @argv: array of strings
 *
 * Return: Eachtime 0, Success
 */
int main(int argc, char *argv[])
{
	/* Custom function used to handle the exit command */
	handle_exit_command(argc, argv);

	return (0);
}
