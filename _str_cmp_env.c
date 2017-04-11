#include "shell.h"
/**
 * _strcmp - a function that compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: an integer result of the comparison
 *
 */
int _strcmp_env(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((int) (s1[i] - s2[i]));
		i++;
	}
	return (0);
}
