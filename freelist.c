#include "shell.h"
/**
 * free_list - frees a list_t list
 * @head: pointer to the list head
 * Return: void
 */
void free_input_list(list_t *head)
{
	if (head == NULL)
		return;
	if (head->next)
		free_input_list(head->next);
	free(head->str);
	free(head);
}

void free_env_list(env_var_list_t *head)
{
	if (head == NULL)
		return;
	if(head->next)
		free_env_list(head->next);
	free(head->key);
	free(head);

}

void free_env_array(char **array)
{
	int i = 0;
	if (array == NULL)
		return;
	while(array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
