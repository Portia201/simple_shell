#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

/**
 * print_environment - prints the current environment
 */
void print_environment(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}

/**
 * main - entry point
 *
 * Return: Eachtime 0
 */
int main(void)
{
	char userInput[100];
	size_t len;

	/* Get user input, for example using fgets */
	fgets(userInput, sizeof(userInput), stdin);

	/* Remove newline character from user input if present */
	len = strlen(userInput);
	if (len > 0 && userInput[len - 1] == '\n')
	{
		userInput[len - 1] = '\0';
	}

	/* Check if the user input is the "env" command */
	if (strcmp(userInput, "env") == 0)
	{
		print_environment();
	}
	else if (strcmp(userInput, "another_command") == 0)
	{ /* Handle another command */
	}
	else
	{ 
		/* Default case: command not recognized */
		printf("Command not recognized: %s\n", userInput);
	}
	/* Rest of my code shell */
	return (0);
}
