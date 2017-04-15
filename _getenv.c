#include "shell.h"
/**
 *
 *
 */
extern char **environ;
const char * _getenv(const char *name)
{
	unsigned int i;
	int j;
	char *str, *value;
	char *not_found = "BOMBSHELL: command not found\n";
	i = 0;
	while (environ[i] != NULL)
	{
		str = strtok(environ[i], "=");
		j = _strcmp_env(name, str);
		if (j == 0)
		{
			value = strtok(NULL, "\0");
			return(value);
		}
		i++;
	}
	return(not_found);
}
/*int main ()
{
	const char * value;
	const char * key = "PATH";
	value = _getenv(key);
	printf("%s: %s\n",value, key);
	return (0);
}*/
