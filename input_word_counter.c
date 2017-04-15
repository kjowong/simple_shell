#include "shell.h"
/**
  * input_word_counter - counts the amount of words the user inputs in getline
  * @buffer: what the user inputs
  * Return: the amount of words the user has inputted
  */
int input_word_counter(char *buffer)
{
	int i, counter;

	i = counter = 0;
	if (buffer == NULL)
		return (0);
	while(buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
		i++;
	if (buffer[i] == '\0')
		return(0);
	while (buffer[i] != '\0')
	{
		if((buffer[i] != ' ' && (buffer[i + 1] == ' ' || buffer[i + 1] == '\n')))
			counter++;
		i++;
	}
	return(counter);
}
