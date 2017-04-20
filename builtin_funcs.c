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
 * @vars: pointer to a sturct that holds all the needed variables
 * Return: 0 on success
 **/
int _setenv(all_variables_t *vars)
{
	int i = 0;

	while (vars->in_ar[1][i] != '\0')
	{
		if (vars->in_ar[1][i] == '=' && vars->in_ar[1][i + 1] != '\0')
		{
			add_env_node(&vars->env_hd, vars->in_ar[1]);
			free_env_array(vars->env_ar);
			vars->env_ar = conv_list_to_array(vars->env_hd, vars->n_env_nod + 1);
			vars->n_env_nod = vars->n_env_nod + 1;
			break;
		}
		i++;
	}
	if (vars->in_ar[1][i] == '\0')
	{
		perror("usage: PATH=value");
		return (1);
	}
	return (0);
}
