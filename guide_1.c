#include "shell.h"

/**
 *_strcmp - Has to compare two strings
 *@first: The first string compared
 *@second: The second string compared
 *
 * Return: The difference between both strings
 */

int _strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	return (first[i] - second[i]);
}

/**
 *_strcat - Actually concatenates two strings
 *@destination: The string to be concatenated to
 *@source:  The string to concatenate
 *
 * Return: address of the new string
 */

char *_strcat(char *destination, char *source)
{
	int len_dest = _strlen(destination);
	int len_source = _strlen(source);
	char *new_string =  NULL;

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}

/**
 *_strspn - Has to get the length of a prefix substring
 *@str1: The string to be searched
 *@str2: The string to be used
 *
 *Return: number of bytes in the initial segment of 5 which are part of accept
 */

int _strspn(char *str1, char *str2)
{
	int i = 0;
	int match = 0;

	while (str1[i] != '\0')
	{
		if (_strchr(str2, str1[i]) == NULL)
			break;
		match++;
		i++;
	}
	return (match);
}

/**
 *_strcspn - computes segment of str1 not in str2
 *@str1: string to be looked for
 *@str2: string to be utilized
 *
 *Return: index at which a char in str1 can be located in str2
 */


int _strcspn(char *str1, char *str2)
{
	int len = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (_strchr(str2, str1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}

/**
 *_strchr - locate character
 *@s: string to be looked for
 *@c: char to be checked (or so)
 *
 *Return: pointer to the first c in s
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

