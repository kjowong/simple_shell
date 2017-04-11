#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: the length of the string
 *
 */
int _strlen(const char *s)
{
	unsigned int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
