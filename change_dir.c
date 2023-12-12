#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * changeDirectory - this change the current directory
 * @newPath: location of directory
 */
void changeDirectory(const char *newPath)
{
	 if (chdir(newPath) != 0)
	 {
		 perror("Cd");
	 } else
	 {
		 char cwd[PATH_MAX];

		 if (getcwd(cwd, sizeof(cwd)) != NULL)
		 {
			 setenv("PWD", cwd, 1);
		 } else
		 {
			 perror("getcwd");
		 }
	 }
}

/**
 * main - main function
 * @argc: argument count
 * @argv: command-line arguments
 * Return: Eachtime 0 success
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		/* No argumsnt provided, change to home directory */
		changeDirectory(getenv("HOME"));
	} else if (argc == 2)
	{
		/* Argument provided, change to specified directory */
		changeDirectory(argv[1]);
	} else
	{
		fprintf(stderr, "Usage: cd [DIRECTORY]\n");
	}

	return (0);
}
