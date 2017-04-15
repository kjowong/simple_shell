#include "shell.h"

char *input_parserator(char *input_buffer)
{
	char *parsed_input;
	int i;
	parsed_input = _strdup(input_buffer);
	for(i = 0; parsed_input[i] != '\0'; i++)
	{
		while(input_buffer[i] == ' ')
			i++;
		parsed_input = &input_buffer[i];
	}
	printf("parsed_input: %s\n", parsed_input);
	free(input_buffer);
	return(parsed_input);

}
