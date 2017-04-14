#include "shell.h"

int input_word_counter(char * buffer)
{
	int i, counter;

	i = counter = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i] != '\0')
	{
		if(buffer[i] == ' ')
			counter++;
		i++;
	}
	return(++counter);
}
