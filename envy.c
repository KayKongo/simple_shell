#include "shell.h"

/**
 * print_env - Prints the environment variables to the standard output.
 *
 * Return: No return value.
 */
void print_env(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
