#include "shell.h"

/**
 *_eputs - print input strinstrg
 * @str: str to print
 *
 * Return: empty
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - write the charac c to stderr (and return the way I tell it to)
 * @c: The charac that need to be printed
 *
 * Return: When successfull... 1.
 * When crappy, -1 is returned, errno is set correctly (I hope).
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - write the charac c to provided fd
 * @c: The charac to be printed
 * @fd: filedescriptor take that write
 *
 * Return: When successful, 1.
 * When full of crap, -1 is passed, while errno is set properly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - print input str
 * @str: str to print
 * @fd: filedescriptor to take write
 *
 * Return: number of characs put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

