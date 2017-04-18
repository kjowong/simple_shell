#include "shell.h"
/**
  * print_env - prints the environment
  * @num_of_env_nodes: takes in the number of nodes in envlist
  * @enviro
  */
int print_env(size_t num_of_env_nodes, char **env_list, char **input_array, env_t *env_head)
{
	unsigned int i;

	(void)input_array;
	(void)env_head;
	(void)num_of_env_nodes;

	i = 0;
	while (env_list[i] != NULL)
	{
		_write(env_list[i]);
		_write("\n");
		i++;
	}
	return (0);
}

int _setenv(size_t num_of_env_nodes, char **env_list, char **input_array, env_t **env_head)
{
	(void) env_list;
	add_env_node(env_head, input_array[1]);
	free_env_array(env_list);

	conv_list_to_array(*env_head, num_of_env_nodes + 1);

	return(0);
}
