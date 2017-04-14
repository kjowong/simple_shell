#include "shell.h"

char **conv_inputlist_to_array(list_t *input_list_head, size_t i)
{
	char **input_array;
	list_t *tmp;
	size_t j = 0;
	int len = 0;

	tmp = input_list_head;
	input_array = malloc(sizeof(char *) * (i + 2));
	while(tmp != NULL)
	{
		len = _strlen(tmp->str);
		input_array[j] = malloc(sizeof(char) * (len + 1));
		_memcopy(input_array[j], tmp->str, len);
		tmp = tmp->next;
		j++;
	}
	input_array[j] = '\0';

	return(input_array);
}
