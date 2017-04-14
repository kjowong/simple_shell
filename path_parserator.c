#include "shell.h"
char **path_parserator(env_var_list_t *env_head)
{
	char **array;
	unsigned int j, i, num_of_path_folders;
	env_var_list_t *temp;
	char *paths, *paths_cp;
	char *delim = ":";
	char *p = "PATH";

	temp = env_head;
	if (!temp)
		perror("Error\n");

	for(i = 0; temp != NULL; i++)
	{
		if (_strcmp(temp->key, p) == 0)
		{
			paths = temp->value;
			num_of_path_folders = path_folder_counter(paths);
			array = _grand_malloc(sizeof(char *) * (num_of_path_folders));
			paths_cp = _strdup(paths);
			if (paths_cp == NULL)
			{
				free(array);
				return (NULL);
			}
			array[0] = strtok(paths_cp, delim);
			for (j = 1; j < num_of_path_folders; j++)
			{
				array[j] = strtok(NULL, delim);
			}
		}
		temp = temp->next;
	}
	return(array);
}
