#include "shell.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: The difference between the strings.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, diff;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	diff = (*(s1 + i) - *(s2 + i));

	return (diff);
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * _strncmp - Compares two strings up to n bytes.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * @n: The number of bytes to compare.
 *
 * Return: The difference between s1 and s2.
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strdup - Duplicates a string.
 * @s: The string to be duplicated.
 *
 * Return: A pointer to the duplicate string.
 */
char *_strdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be checked.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of the character,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
