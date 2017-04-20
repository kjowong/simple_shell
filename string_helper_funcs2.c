#include "shell.h"
/**
 * _strncat_env - a function that concatenates two strings
 * @dest: string to copy to
 * @src: string to copy
 * @n: bytes from src to append
 * Return: a pointer to the resulting string dest
 *
 */
char *_strncat_env(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[j] != '\0')
		j++;

	while (i < n && src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}

	return (dest);
}
