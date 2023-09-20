#include "shell.h"

/**
 * find_path - Finds the PATH environment variable.
 *
 * Return: Pointer to the PATH value if found, NULL if not found.
 */
char *find_path(void)
{
	int x = 0;
	char **env = environ;
	char *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

