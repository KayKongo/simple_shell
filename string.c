#include "shell.h"

/**
 * _strlen - returns length
 * @s: str length for knowledge
 *
 * Return: int len of str
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compare two strs
 * @s1: str one
 * @s2: str two
 *
 * Return: - ? s1 < s2, + ? s1 > s2, zero when s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks again
 * @haystack: str to look for
 * @needle: substr to locate
 *
 * Return: addy of next charac
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strs
 * @dest: destination obviously
 * @src: src buff
 *
 * Return: point me to the destination buff
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

