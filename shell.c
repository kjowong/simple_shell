#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;
	char *s;
	list_t *input_head;
	env_var_list_t *env_head;
	char **enviroment_list;
	char **path_array;
	char **input_array;
	size_t num_of_env_nodes, i;
	int j;

	i = 0;
	env_head = NULL;
	input_head = NULL;

	num_of_env_nodes = create_env_list(&env_head);
	enviroment_list = conv_list_to_array(env_head, num_of_env_nodes);
	path_array = path_parserator(env_head);
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
			i++;
		}
		input_array = conv_inputlist_to_array(input_head, i - 1);
		for(j = (i - 1); j >= 0; j--)
		{
			/*printf("%s\n", input_array[j]);*/
		}
		/*cmd_executor(path_array, s);*/
		_write("$ ");
	}
	/*n = print_input_list(input_head);
	printf("\nn is: %lu\n", n);*/
	free_mem(buffer, input_head, env_head, enviroment_list, path_array, input_array);
	exit(EXIT_SUCCESS);
}
