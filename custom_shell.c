#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

/**
 * parseCommand - takes user input, parses the command and
 * arguments, and prints them out. The loop continues until
 * the user enters "exit".
 * @input: this takes thr user input.
 */
void parseCommand(char *input)
{
	char *token = strtok(input, " ");

	/* Extracting command */
	char *command = token;

	printf("Command: %s\n", command);

	/* Extracting arguments */
	printf("Arguments: ");
	while ((token = strtok(NULL, " ")) != NULL)
	{
		printf("%s ", token);
	}
	printf("\n");
}

/**
 * main - entry point
 *
 * Return: Eachtime (Success) 0,
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("Shell > ");
		fgets(input, MAX_INPUT_LENGTH, stdin);

		/* Remove trailing newline character */
		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		parseCommand(input);
	}

	return (0);
}
