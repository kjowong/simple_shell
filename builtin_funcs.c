#include "shell.h"

int print_env(size_t num_of_env_nodes, char **enviroment_list, char **input_array, env_var_list_t *env_head)
{
	unsigned int i;

	(void)input_array;
	(void)env_head;
	(void)num_of_env_nodes;

	i = 0;
	while (enviroment_list[i] != NULL)
	{
		_write(enviroment_list[i]);
		_write("\n");
		i++;
	}
	return (0);
}

int _setenv(size_t num_of_env_nodes, char **enviroment_list, char **input_array, env_var_list_t **env_head)
{
	(void) enviroment_list;
	add_env_node(env_head, input_array[1]);
	free_env_array(enviroment_list);

	conv_list_to_array(*env_head, num_of_env_nodes + 1);

	return(0);
}
