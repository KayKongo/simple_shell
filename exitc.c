#include "shell.h"

/**
 * exitc - Handles the 'exit' command.
 * @command: Tokenized command arguments.
 * @line: Input line read from standard input.
 *
 * Return: No return value.
 */
void exitc(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}

