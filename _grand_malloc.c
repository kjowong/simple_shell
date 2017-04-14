#include "shell.h"

void *_grand_malloc(size_t mem_needed)
{
	unsigned int i;
	char *allocated_head;

	i = 0;
	allocated_head = malloc(mem_needed);
	if (allocated_head == NULL)
		exit(EXIT_FAILURE);
	while(i < mem_needed)
	{
		allocated_head[i] = '\0';
		i++;
	}
	printf("in _grand_malloc i is %u\n", i);
	return(allocated_head);
}
