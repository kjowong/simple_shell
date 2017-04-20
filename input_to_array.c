#include "shell.h"
/**
 * input_to_array - converts inout to a double pointer array
 * @buffer: string input
 * @tokens: number of tokens in string
 * Return: pointer to new input array
 **/

char **input_to_array(char *buffer, int tokens)
{
	int i;
	char **input_array;

	input_array = _grand_malloc(sizeof(char *) * (tokens + 1));
	for (i = 0; i < tokens; i++)
	{
		if (i == 0)
			input_array[i] = strtok(buffer, "\n\t\r\" ");
		else
			input_array[i] = strtok(NULL, "\n\t\r\" ");
	}
	if (input_array[i - 1] != NULL)
		input_array[i] = NULL;

	return (input_array);
}
