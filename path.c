#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * executeCommand - handle the path
 * @command: checks if command is executable
 * @arguments: arguments used
 */
void executeCommand(char *command, char *arguments[])
{
	char *searchPath = getenv("PATH");
	char *directory = strtok(searchPath, ":");

	while (directory != NULL)
	{
		size_t fullPathLen = strlen(directory) + strlen(command) + 2;
		char *fullPath = (char *)malloc(fullPathLen);

		if (fullPath == NULL)
		{
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}

		sprintf(fullPath, "%s/%s", directory, command);

		if (access(fullPath, X_OK) == 0)
		{
			execv(fullPath, arguments);
			perror("Error executing the command");
			free(fullPath);
			exit(EXIT_FAILURE);
		}

		free(fullPath);
		directory = strtok(NULL, ":");
	}

	fprintf(stderr, "Command '%s' not found\n", command);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point
 * @argv: argument vector
 * @argc: argument counter
 *
 * Return: Eachtime 0
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <command> [args...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	executeCommand(argv[1], &argv[1]);

	return (0);
}
