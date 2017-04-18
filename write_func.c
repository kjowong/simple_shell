#include "shell.h"
/**
  * _write - function that writes to std output
  * @s: takes in a string
  * Return: what is written, including the length
  */
int _write(char *s)
{
	int i;

	i = write(1, s, _strlen(s));
	return (i);
}
