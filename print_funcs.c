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
		_write(traverser->key);
		_write("=");
		_write(traverser->value);
		_write("\n");
		traverser = traverser->next;
		nodes++;
	}
	return (nodes);
}
/**
 * print_listint - prints the contents of a linked list
 * @h: pointer to linked list
 * Return: number of nodes
 */
size_t print_input_list(const list_t *h)
{
	size_t nodes = 0;
	const list_t * traverser = h;

	while (traverser != NULL)
	{
		_write(traverser->str);
		traverser = traverser->next;
		nodes++;
	}
	return (nodes);
}
