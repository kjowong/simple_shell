#include "shell.h"

int main(void)
{
	char *buffer, *s;
	size_t num_of_env_nodes, i, len;
	ssize_t read;
	list_t *input_head;
	env_var_list_t *env_head;
	char **enviroment_list, **path_array, **input_array;
	int words = 0;

	len = i = num_of_env_nodes = 0;
	enviroment_list = path_array = input_array = NULL;
	env_head = NULL;
	input_head = NULL;
	s = buffer = NULL;
	num_of_env_nodes = create_env_list(&env_head);
	enviroment_list = conv_list_to_array(env_head, num_of_env_nodes);
	path_array = path_parserator(env_head);
	_write("$ ");
	while ((read = getline(&buffer, &len, stdin)) != -1)
	{
		words = input_word_counter(buffer);
		if(_strcmp(buffer, "exit") == 0)
			break;
		s = strtok(buffer, " ");
		while (s != NULL)
		{
			add_node_end(&input_head, s);
			s = strtok(NULL, " ");
			i++;
		}
		input_array = conv_inputlist_to_array(input_head, i);
		/*cmd_executor(input_array, s);*/
		free_env_array(input_array);
		_write("$ ");
	}
	free_mem(buffer, input_head, env_head, enviroment_list, path_array);
	exit(EXIT_SUCCESS);
}
