#include "shell.h"

/**
 * _putchar - Writes the character c to the standard output.
 * @c: The character to be printed.
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_s - Prints a string to the standard output.
 * @s: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_s(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
