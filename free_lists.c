#include "shell.h"
/**
 * free_list - frees a list_t list
 * @head: pointer to the list head
 * Return: void
 */
void free_input_list(list_t *input_head)
{
	if (input_head == NULL)
		return;
	if (input_head->next)
		free_input_list(input_head->next);
	free(input_head->str);
	free(input_head);
}

/**
 * free_list - frees a list_t list
 * @head: pointer to the list head
 * Return: void NEEDS TO BE FIXED!!!!!!
 */
void free_env_list(env_var_list_t *env_head)
{
	env_var_list_t *tmp;
	tmp = env_head;

	if (tmp == NULL)
		return;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
}
