#include "shell.h"
/**
 * print_listint - prints the contents of a linked list
 * @h: pointer to linked list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;
	const list_t * traverser = h;

	while (traverser != NULL)
	{
		write(1, traverser->str, _strlen(traverser->str));
		traverser = traverser->next;
		nodes++;
	}
	return (nodes);
}
