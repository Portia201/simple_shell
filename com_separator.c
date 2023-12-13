#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100

/**
 * execute_command - Handle the commands separator ;
 * @command: instruct the dystem to execute or perfom
 * instruction
 */
void execute_command(char *command)
{
	char *args[100];
	int i = 0;

	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	pid_t pid = fork();
	pid = fork();

	if (pid == 0)
	{
		execvp(args[0], args);
		perror("Execution failed");
		exit(EXIT_FAILURE);
	} else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	else
	{
	perror("Fork failed");
	}
}

/**
 * simple_shell - the shell created
 * @input: the input given tosimple shell
 */
void simple_shell(char *input)
{
	char *commands[MAX_COMMANDS];
	int i = 0;

	char *token = strtok(input, ";");

	while (token != NULL && i < MAX_COMMANDS)
	{
		commands[i++] = token;
		token = strtok(NULL, ";");
	}

	for (int j = 0; j < i; j++)
	{
		execute_command(commands[j]);
	}
}

/**
 * main - this is the entry point
 *
 * Return: Eachtime 0 success
 */
int main(void)
{
	char input[1024];

	printf("Enter commands: ");
	fgets(input, sizeof(input), stdin);

	input[strcspn(input, "\n")] = 0;

	simple_shell(input);

	return (0);
}
