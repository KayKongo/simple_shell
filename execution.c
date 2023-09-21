#include "shell.h"

/**
 * execution - Execute user-entered commands.
 * @cp: The command path.
 * @cmd: An array of pointers to command arguments.
 *
 * Return: No return value.
 */
void execution(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);

	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}

