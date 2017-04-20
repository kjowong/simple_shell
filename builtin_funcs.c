#include "shell.h"
/**
  * print_env - prints the environment
  * @num_of_env_nodes: takes in the number of nodes in envlist
  * @enviro
  */
int print_env(size_t n_env_nod, char **env_ar, char **in_ar, env_t *env_hd)
{
	unsigned int i;

	(void)in_ar;
	(void)env_hd;
	(void)n_env_nod;

	i = 0;
	while (env_ar[i] != NULL)
	{
		_write(env_ar[i]);
		_write("\n");
		i++;
	}
	return (0);
}
/**
 * _setenv - sets new environmental variable
 * @num_of_env_nodes: takes in the number of nodes in envlist
 * @enviro
 
int _setenv(size_t n_env_nod, char **env_ar, char **in_ar, env_t *env_hd)
{
	(void) env_ar;
	add_env_node(env_hd, in_ar[1]);
	free_env_array(env_ar);

	conv_list_to_array(*env_hd, n_env_nod + 1);

	return(0);
}
*/
