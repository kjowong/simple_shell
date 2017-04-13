#include "shell.h"
char **path_parserator(env_var_list_t *env_head, size_t n)
{
	char **array;
	unsigned int j, i, semicols;
	env_var_list_t *temp;
	char *paths, *paths_cp;
	char *delim = ":";
	char *p = "PATH";

	semicols = 0;
	temp = env_head;
	array = malloc(sizeof(char *) * (n));
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
			while(paths[j] != '\0')
			{
				if(paths[j] == ':')
					semicols++;
				j++;
			}
			paths_cp = _strdup(paths);
			if (paths_cp == NULL)
			{
				free(array);
				return (NULL);
			}
			array[0] = strtok(paths_cp, delim);
			printf("array[0]: %s\n", array[0]);

			for (j = 1; j < (semicols + 2); j++)
			{
				array[j] = strtok(NULL, delim);
				printf("array[%u]: %s\n", j, array[j]);
			}
		}
		temp = temp->next;
	}
	return(array);
}
