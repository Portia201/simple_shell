#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char custom_buffer[BUFFER_SIZE];
static size_t custom_buffer_index = 0;
static ssize_t custom_bytes_read = 0;

/**
 * custom_getline - reads input from the user
 * using a custom getline function
 *
 * Return: returns new line
 */
char* custom_getline(void)
{
	/* Check if buffer is empty, read more characters if needed */
	if (custom_buffer_index == 0)
	{
		custom_bytes_read = read(STDIN_FILENO, custom_buffer, BUFFER_SIZE);
		if (custom_bytes_read <= 0)
		{
			/* End of file or error */
			return (NULL);
		}
	}

	/* Find the newline character or end or end of buffer */
	size_t i;

	for (i = 0; i < custom_bytes_read; ++i)
	{
		if (custom_buffer[custom_buffer_index + i] == '\n')
		{
			custom_buffer_index += i + 1; /* Move buffer_index to newline after the character */
			custom_buffer[i] = '\0'; /* Replace newline with null terminator */
			return (custom_buffer);
		}
	}
	/* No new line found, return return current line */
	char *line = &custom_buffer[custom_buffer_index];

	custom_buffer_index = 0;
	return (line);
}

/**
 * main - entry point
 *
 * Return: Eachtime 0
 */
int main(void)
{
	char custom_buffer[BUFFER_SIZE];
	size_t custom_buffer_index = 0;
	ssize_t custom_bytes_read = 0;

	while (1)
	{
		printf("Unique Shell> ");
		fflush(stdout);

		char *line = custom_getline();

		if (line == NULL)
		{
			/* End of file or error */
			break;
		}

		printf("You wanted: %s\n", line);
	}

	return (0);
}
