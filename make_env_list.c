#include "shell.h"
extern char **environ;
env_var_list_t * add_env_node(env_var_list_t **head, char *env_var)
{
	env_var_list_t *new_node, *tmp;
	if (env_var == NULL)
		return (NULL);
	new_node = malloc(sizeof(env_var_list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->key = strtok(env_var, "=");
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
int main()
{
	unsigned int i;
	size_t n;
	env_var_list_t *head;

	i = 0;
	head = NULL;

	while (environ[i] != NULL)
	{
		add_env_node(&head, environ[i]);
		i++;
	}

	n = print_env_list(head);
	printf("n is: %lu\n", n);
	return (0);
}
