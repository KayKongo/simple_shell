#include "shell.h"

/**
 * free_buffers - Frees memory buffers.
 * @buf: The buffer to be freed.
 *
 * Return: No return value.
 */
void free_buffers(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;

	while (buf[i])
	{
		free(buf[i]);
		i++;
	}

	free(buf);
}

