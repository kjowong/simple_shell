#include "shell.h"
/**
 * free_list - frees a list_t list, the input list
 * @head: pointer to the list head
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
/**
 * free_env_list - frees the environmental variable linked list
 * @head: pointer to the list head
 */
void free_env_list(env_var_list_t *head)
{
	if (head == NULL)
		return;
	if(head->next)
		free_env_list(head->next);
	free(head->key);
	free(head);
}
/**
 * free_env_array - frees the double ptr array for the environmental list
 * @array: takes in the double ptr array
 */
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
/**
 * free_path_array - frees the path's array
 * @array: takes in a dobule ptr array
 */
void free_path_array(char **array)
{
	if (array == NULL)
		return;
	free(array[0]);
	free(array);
}
/**
 * free_mem - frees all allocated memmory before shell's exit
 * @buffer: the user's input
 * @env_var_list: the environmental linked list
 * @environmental_list: environmental variable double ptr array
 * @path_array: double ptr array of the path
 */
void free_mem(char *buffer, list_t *input_head, env_var_list_t *env_head, char **enviroment_list, char **path_array)
{
	free(buffer);
	free_input_list(input_head);
	free_env_list(env_head);
	free_env_array(enviroment_list);
	free_path_array(path_array);
}
