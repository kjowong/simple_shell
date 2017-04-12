#include "shell.h"
/**
 * _strcmp - a function that compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: an integer result of the comparison
 *
 */
int _strcmp(char *s1, char *s2)
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
/**
 * _strdup - returns a pointer to a new string which is a duplicate
 * of the string str
 * @str: input string
 *
 * Return: a pointer to a newly allocated space in memory
 */
char *_strdup(const char *str)
{
	unsigned int i;
	char *string;

	if (str == NULL)
		return (NULL);

	string = (char *) malloc(sizeof(char) * (_strlen(str) + 1));
	if (string == NULL)
	{
		free(string);
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
			break;
		string[i] = str[i];
	}
	string[i] = '\0';
	return (string);
}
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
