#include "shell.h"
int _write(char *s)
{
	int i;
	i = write(1, s, _strlen(s));
	return (i);
}
