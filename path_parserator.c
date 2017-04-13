#include "shell.h"
char **path_parserator(env_var_list_t *env_head, size_t n)
{
	char **array;
	int j;
	unsigned int i;
	env_var_list_t *temp;
	char *paths, *paths_cp;
	char *delim = ":";
	char *p = "PATH";
	char *token;
	temp = env_head;
	array = malloc(sizeof(char *) * n);
	if (array == NULL)
		return (NULL);
	if (!temp)
	{
		perror("Error\n");
	}
	for(i = 0; i < n; i++)
	{
		if (_strcmp(temp->key, p) == 0)
		{
			paths = temp->value;
			paths_cp = _strdup(paths);
			if (paths_cp == NULL)
			{
				free(array);
				return (NULL);
			}
			token = strtok(paths_cp, delim);
			array[0] = token;
			for (j = 1; token != NULL; j++)
			{
				token = array[j] = strtok(NULL, delim);
			}
		}
		temp = temp->next;
	}
	free(paths_cp);
	free(array);
	return(array);
}
