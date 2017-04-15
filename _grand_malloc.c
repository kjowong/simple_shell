#include "shell.h"
/**
  * _grand_malloc - allocates memory, checks for NULL and sets to \0
  * @mem_needed: takes in the amount of memory needed
  * Returns: the allocated memory
  */
void *_grand_malloc(size_t mem_needed)
{
	unsigned int i;
	char *allocated_head;

	i = 0;
	allocated_head = malloc(mem_needed);
	if (allocated_head == NULL)
		return (NULL);
	while (i < mem_needed)
	{
		allocated_head[i] = '\0';
		i++;
	}
	return (allocated_head);
}
