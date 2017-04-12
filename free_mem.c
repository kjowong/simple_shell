#include "shell.h"

void free_mem(char *buffer, list_t *input_head, env_var_list_t *env_head, char **enviroment_list)
{
	free(buffer);
	free_input_list(input_head);
	free_env_list(env_head);
	free_env_array(enviroment_list);
}
