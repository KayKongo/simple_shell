#include "shell.h"

/**
 * initializer - starts executing everything (This is where the fun begins)
 * @current_command: check current token (I beg... no errors here lol)
 * @type_command: parse token for me
 *
 * Return: void function
 */

void initializer(char **current_command, int type_command)
{
	pid_t PID;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(current_command, type_command);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(current_command, type_command);
}

