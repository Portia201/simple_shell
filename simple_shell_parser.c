#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

/**
 * parseUserInput - finds the first space, and separates the command
 * arguments accordingly.
 * @userInput: thisis arguments passed
 */
void parseUserInput(char *userInput)
{
	char *argumentToken;
	char commandBuffer[MAX_INPUT_SIZE];

	/* Finds space in user input */
	char *spacePosition = strchr(userInput, ' ');

	/* copy the command part if theres space found */
	if (spacePosition != NULL)
	{
		/* Extract the command */
		strncpy(commandBuffer, userInput, spacePosition - userInput);
		commandBuffer[spacePosition - userInput] = '\0';

		/* Print the extracted command */
		printf("Command: %s\n", commandBuffer);

		/* Pointer move to next character after space */
		argumentToken = spacePosition + 1;

		/* Print the arguments */
		printf("Arguments: %s\n", argumentToken);
	}
	else
	{
		/* The entore output is command if theres no space found */
		printf("Command: %s\n", userInput);
		printf("Arguments: (none)\n");
	}
}

/**
 * main - entry point
 *
 * Return: Eachtime 0 success
 */
int main(void)
{
	char userInput[MAX_INPUT_SIZE];

	/* Ask a user to enter prompt */
	printf("Enter a command: ");
	fgets(userInput, sizeof(userInput), stdin);

	/* Remove the newline character at the end of the input */
	userInput[strcspn(userInput, "\n")] = '\0';

	/* Parse and display the user input */
	parseUserInput(userInput);

	return (0);
}
