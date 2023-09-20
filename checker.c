#include "shell.h"

/**
 * checker - Check whether a command is a built-in or an external function.
 * @cmd: Tokenized user input.
 * @buf: Line obtained from the getline function.
 *
 * Return: 1 if the command was executed, 0 if it was not executed.
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
