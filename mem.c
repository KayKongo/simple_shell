#include "shell.h"

/**
 * bfree - Deallocates memory occupied by a pointer and sets it to NULL.
 * @ptr: A pointer to the memory to be freed.
 *
 * Return: 1 if memory was successfully freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
