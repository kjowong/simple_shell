#include "shell.h"

char **path_parserator(env_var_list_t *env_head, size_t n)
{
	char **array = NULL;
	int j, semicols;
	unsigned int i;
	env_var_list_t *temp;
	char * paths, *paths_cp;
	char *delim = ":";
	char * p = "PATH";
	semicols = 0;
	temp = env_head;
	if(temp)
		for(i = 0; i < n; i++)
		{
			j = _strcmp(temp->key, p);
			if (j == 0)
			{
				paths = temp->value;
				while(paths[j] != '\0')
				{
					if(paths[j] == ':')
						semicols++;
					j++;
				}
				semicols++;
				paths_cp = _strdup(paths);
				array[0] = strtok(paths_cp, delim);
				getchar();
				for(j = 1; j < semicols - 1; j++)
				{
					printf("%s\n", array[j]);
					array[j] = strtok(NULL, delim);
				}
				/*array[j] = strtok(NULL, '\0');
				  array[++j] = NULL;*/
			}
			temp = temp->next;
		}
	return(array);
}
