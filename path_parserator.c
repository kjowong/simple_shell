#include "shell.h"
/**
  * path_parserator - convernts the env_var linked list to a double ptr and parses by directories
  * @env_head: takes in the environmental variable linked list
  * Return: returns a double ptr array of environmental variables
  */
char **path_parserator(env_var_list_t *env_head)
{
	char **array;
	unsigned int j, i, num_of_path_folders;
	env_var_list_t *temp;
	char *paths, *paths_cp;
	char *delim = ":\n";
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
			array = _grand_malloc(sizeof(char *) * (num_of_path_folders + 1));
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
			array[j] = NULL;
		}
		temp = temp->next;
	}
	return(array);
}
