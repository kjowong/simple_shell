#include "shell.h"
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
