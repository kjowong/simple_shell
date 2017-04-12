#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;
	char * s;
	list_t *input_head;
	env_var_list_t *env_head;
	int n;

	env_head = NULL;
	input_head = NULL;

	n = create_env_list(&env_head);
	printf("n is %u\n", n);
	conv_list_to_array(env_head, n);
	_write("$ ");
	while ((read = getline(&buffer, &len, stdin)) != -1)
	{
		if (_strcmp(buffer, "end-of-file") == 0 || _strcmp(buffer, "exit") == 0)
			break;
		s = strtok(buffer, " ");
		while (s != NULL)
		{
			add_node_end(&input_head, s);
			s = strtok(NULL, " ");
		}
		_write("$ ");
	}
	/*n = print_input_list(input_head);
	printf("\nn is: %lu\n", n);
	print_env_list(env_head);*/
	free(buffer);
	free_input_list(input_head);
	/*free_env_list(env_head);*/
	exit(EXIT_SUCCESS);
}
