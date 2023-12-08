#include "shell.h"

/**
 * entry_point - this is the main function for the simple shell project
 * @argc: argument count
 * @argv: argument vector
 * @envp: enviroment variables
 * Return: Eachtime Success (0)
 */
int entry_point(int argc, char **argv, char **envp)
{
	bool isInteractive = (argc == 1 && isatty(STDIN_FILENO));

	displayPrompt(argv, envp, isInteractive);
	return (0);
}
