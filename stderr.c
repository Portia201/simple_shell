#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENV_VARS 100

/**
 * my_setenv - Function to set or modify an environment variable
 * @variable: name of the variable
 * @value: value to set
 */
void my_setenv(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "Error setting environment variable\n");
	}
}

/**
 * my_unsetenv - function to unset enviroment variable
 * @variable: name of the variable
 */
void my_unsetenv(char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Error unsetting environment variable\n");
	}
}

/**
 * main - entry poin
 * @argv: argument vector
 * @argc: argument value
 *
 * Return: success 0
 */
int main(int argc, char *argv[])
{
	if (argc == 3 && strcmp(argv[1], "setenv") == 0)
	{
		/* Use setenv command */
		my_setenv(argv[2], getenv(argv[2]) ? getenv(argv[2]) : "");
	} else if (argc == 2 && strcmp(argv[1], "unsetenv") == 0)
	{
		/* Use unsetenv command */
		if (argc != 3)
		{
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			return (1);
		}
		my_unsetenv(argv[2]);
	} else
	{
		fprintf(stderr, "Invalid command or arguments\n");
		return (1);
	}

	return (0);
}

