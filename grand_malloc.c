#include "shell.h"

void *_grand_malloc(size_t mem_needed)
{
	unsigned int i;
	char *malloced_head;

	i = 0;
	malloced_head  = malloc(mem_needed);
	if (malloced_head == NULL)
		exit(EXIT_FAILURE);
	while(i < mem_needed)
	{
		malloced_head[i] = '\0';
		i++;
	}
	return(malloced_head);
}
