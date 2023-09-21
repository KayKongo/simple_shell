#include "shell.h"

/**
 * tokenizer - Actually tokenizes input into an array
 *@input_string: input that has to be  parsed
 *@delim: delimiter used, has to be a string character
 *
 *Return: token arrays
 */

char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char *save_ptr = NULL;
	char *token = NULL;
	char **av = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 *print - Has to print a string to stdout
 *@string: The actual string to be printed
 *@stream: The stream to print out to
 *
 *Return: void, return absolutely nothing
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 *remove_newline - Has remove a new line from a string
 *@str: Actual string to be used
 *
 *
 *Return: void
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *_strcpy - Has to copy a string into a buffer... I think
 *@source: source obviously
 *@dest: destination (very self-explanatory)
 *
 * Return: void
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 *_strlen - how long is the string,huh
 *@string: string count
 *
 * Return: string length
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}

