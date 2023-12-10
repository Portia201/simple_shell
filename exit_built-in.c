#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * exit_shell_custom - Implement the exit built-in,
 * that exits the shell
 */
void exit_shell_custom(void)
{
	printf("Exiting the custom shell. Goodbye!\n");
	exit(0);
}

/**
 * main - entty point
 *
 * Return: Eachtime 0
 */
int main(void)
{
	char userInput[100]; /* Adjust the size as needed */

	while (1)
	{
		printf("MyUniqueShell> ");
		fgets(userInput, sizeof(userInput), stdin);
		userInput[strcspn(userInput, "\n")] = '\0';
		/* Remove the trailing newline character */

		/* Check if the command is "exit" */
		if (strcmp(userInput, "exit") == 0)
		{
			exit_shell_custom();
		} else
		{
			/* Add your own logic for handling other commands or executing the input */
			/* ... */
		}
	}

	return (0);
}
