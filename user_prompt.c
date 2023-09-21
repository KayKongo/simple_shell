#include "shell.h"

/**
 * prompt_user - Displays a shell prompt to indicate it's ready to accept user input.
 * Prints the prompt if the shell is in interactive mode.
 *
 * Return: No return value.
 */
void prompt_user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;

	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}

