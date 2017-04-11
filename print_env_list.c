#include "shell.h"
/**
 * print_listint - prints the contents of a linked list
 * @h: pointer to linked list
 * Return: number of nodes
 */
size_t print_env_list(const env_var_list_t *h)
{
	size_t nodes = 0;
	const env_var_list_t * traverser = h;

	while (traverser != NULL)
	{
		write(1, traverser->key, _strlen(traverser->key));
		write(1, traverser->value, _strlen(traverser->value));
		traverser = traverser->next;
		nodes++;
	}
	return (nodes);
}
