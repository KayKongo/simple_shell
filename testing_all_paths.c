#include "shell.h"

/**
 * test_path - Checks whether a command exists in the specified paths.
 * @path: Tokenized paths to search for the command.
 * @command: The user-entered command.
 *
 * Return: A string containing the full path to the command if found, NULL on failure.
 */
char *test_path(char **path, char *command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = append_path(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}

