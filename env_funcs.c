#include "shell.h"
extern char **environ;
env_t * add_env_node(env_t **head, char *env_var)
{
	env_t *new_node, *tmp;
	char *env_variable;

	new_node = _grand_malloc(sizeof(env_t));
	env_variable = _strdup(env_var);
	if (env_variable == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->key = strtok(env_variable, "=");
	new_node->value = strtok(NULL, "\0");
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	return (new_node);
}
int create_env_list(all_variables_t *all_var_s)
{
	unsigned int i;
	i = 0;
	while (environ[i] != NULL)
	{
		add_env_node(&all_var_s->env_head, environ[i]);
		i++;
	}
	return (i);
}
