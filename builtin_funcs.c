#include "shell.h"
/**
  * print_env - prints the environment
  * @vars: pointer to a sturct that holds all the needed variables
  * Return: 0 on success
  **/
int print_env(all_variables_t *vars)
{
	unsigned int i;

	i = 0;
	while (vars->env_ar[i] != NULL)
	{
		_write(vars->env_ar[i]);
		_write("\n");
		i++;
	}
	return (0);
}
/**
 * _setenv - sets new environmental variable
 * @num_of_env_nodes: takes in the number of nodes in envlist
 * @enviro
 **/
int _setenv(all_variables_t *vars)
{
	printf("vars->buf: %s\n", vars->buf);
/*	add_env_node(vars->env_hd, var->in_ar[1]);
	free_env_array(vars->env_ar);

	conv_list_to_array(*vars->env_hd, vars->n_tok + 1);
*/
	return(0);
}
