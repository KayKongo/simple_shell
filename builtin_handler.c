#include "shell.h"

/**
 * handle_builtin - Executes built-in commands.
 * @command: Tokenized command arguments.
 * @line: Input line read from standard input.
 *
 * Return: 1 if a built-in command was executed, 0 otherwise.
 */
int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}

	return (0);
}

