#include "shell.h"

/**
 * handle_signal - Handles signals and maintains interactive mode.
 * @m: The signal number.
 *
 * Return: No return value.
 */
void handle_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

