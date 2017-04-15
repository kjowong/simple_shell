#include "shell.h"
/**
  * input_to_array - takes in user input and converts to a double ptr array
  * @words: the amount of words user inputs
  * Return: returns the double ptr array
  */
char **input_to_array(char *buffer, int words)
{
	int i;
	char **input_array;
	input_array = _grand_malloc(sizeof(char *) * (words + 1));
	for (i = 0; i < words; i++)
	{
		if (i == 0)
			input_array[i] = strtok(buffer, " \n\t");
		else
			input_array[i] = strtok(NULL, " \n\t");
	}
	if (input_array[i - 1] != NULL)
		input_array[i] = NULL;
	return (input_array);
}
