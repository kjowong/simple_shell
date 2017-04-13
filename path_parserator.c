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
	/*char *token;*/
	temp = env_head;
/*n below is wrong*/
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
			paths_cp = _strdup(paths);
			printf("paths_cp: %s\n", paths_cp);
			if (paths_cp == NULL)
			{
				free(array);
				return (NULL);
			}
			array[0] = strtok(paths_cp, delim);
			for (j = 1; j < 9; j++)
			{
				array[j] = strtok(NULL, delim);
				printf("array[%d]: %s\n", j, array[j]);
			}
			printf("array[0]: %s\n", array[0]);
		}
		temp = temp->next;
	}
	/*free(paths_cp);
	free(array);*/
	return(array);
}
