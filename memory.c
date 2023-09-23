#include "shell.h"

/**
 * bfree - liberate pointer, nullify addy
 * @ptr: addy of the pointer to liberate
 *
 * Return: 1 ? freed : 0.
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

