#include "shell.h"
/**
 * _memcpy -  a function that copies memory area
 * @src: pointer to be copied
 * @dest: pointer to copy to
 * @n: the number of bytes to be copied
 * Return: a pointer to dest
 *
 */
char *_memcopy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
