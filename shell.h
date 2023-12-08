#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMANDS 10

/**
 * struct CommandCounter - Structure to store the command count
 * @count: count of commands
 */
typedef struct CommandCounter
{
	int count;
} CommandCounter;

void displayPrompt(char **arguments, char **environment, bool flag);
int compareStrings(char *str1, char *str2);
char *concatenateStrings(char *destination, char *source);
int getStringLength(char *str);
void handleExit(char *command);
void runCommand(char **arguments, char **programArguments, char **enviroment);
char *trimWhitespace(char *command);
char *copyNCharacters(char *destination, char *source, int n);
char *getExecutablePath(char *command);
char *getEnvironmentVariable(char *name);
char **tokenizeEnvironmentPath(char *path);

extern char **environ;

void displayError(commandCounter *counter, char **programArguments, char *command);

#endif
