#include "shell.h"

char **input_to_array(char *buffer, int words)
{
	int i;
	char **input_array;
	input_array = _grand_malloc(sizeof(char *) * (words + 1));
	for(i = 0; i < words; i++)
	{
		if (i == 0)
			input_array[i] = strtok(buffer, " \n\t");
		else
			input_array[i] = strtok(NULL, " \n\t");

	}
	if (input_array[i - 1] != NULL)
		input_array[i] = NULL;
	for (i = 0; i < words; i++)
		printf("array[%d]: %s\n", i, input_array[i]);

	return(input_array);
}
