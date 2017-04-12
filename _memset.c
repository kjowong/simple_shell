#include "shell.h"
/**
 * _memset - a function that fills memory with a constant byte
 * @s: pointer
 * @b: constant
 * @n: the number of bytes to be filled with b
 * Return: a pointer to the memory area s
 *
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
