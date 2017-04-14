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
	printf("in free_env_array i is %d\n", i);
	free(array);
}
void free_path_array(char **array)
{
	if (array == NULL)
		return;
	free(array[0]);
	free(array);
}
void free_mem(char *buffer, list_t *input_head, env_var_list_t *env_head, char **enviroment_list, char **path_array)
{
	free(buffer);
	free_input_list(input_head);
	free_env_list(env_head);
	free_env_array(enviroment_list);
	free_path_array(path_array);
}
