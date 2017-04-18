#include "shell.h"

all_variables_t *build_all_variables(all_variables_t *var_s)
{
	var_s->buffer = NULL;
	var_s->num_of_env_nodes = 0;
	var_s->len = 0;
	var_s->input_head = NULL;
	var_s->env_head = NULL;
	var_s->enviroment_array = NULL;
	var_s->path_array = NULL;
	var_s->input_array = NULL;
	var_s->num_of_tokens = 0;
	return (var_s);
}
