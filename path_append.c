#include "shell.h"

/**
 * path_append - Concatenates a path and a command to form a full path.
 * @path: The path to be appended.
 * @command: The command to be concatenated.
 *
 * Return: A buffer containing the concatenated path and command on success,
 *         NULL on failure.
 */
char *path_append(char *path, char *command)
{
	char *buf;
	size_t i = 0, j = 0;

	if (command == NULL)
		command = "";

	if (path == NULL)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}

	while (command[j])
	{
		buf[i + j] = command[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}

