#include "shell.h"

int main(void)
{
	char *buffer;
	size_t num_of_env_nodes, i, len;
	list_t *input_head;
	env_var_list_t *env_head;
	char **enviroment_array, **path_array, **input_array;
	int words = 0;
	struct stat sb;
	int read, pipe = 0;
	int (*builtin_func)();

	len = i = num_of_env_nodes = 0;
	enviroment_array = path_array = input_array = NULL;
	env_head = NULL;
	input_head = NULL;
	buffer = NULL;

	num_of_env_nodes = create_env_list(&env_head);
	enviroment_array = conv_list_to_array(env_head, num_of_env_nodes);
	path_array = path_parserator(env_head);
	signal(SIGINT, SIG_IGN);

	if (fstat(STDIN_FILENO, &sb) == -1)
	{
		perror("fstat error\n");
		exit(EXIT_FAILURE);
	}
	if ((sb.st_mode & S_IFMT) == S_IFIFO)
	{
		pipe = 1;
	}
	if (pipe == 0)
		_write("BombShell-$ ");
	while ((read = getline(&buffer, &len, stdin)) != -1)
	{
		/*buffer = input_parserator(buffer);*/
		if(_strcmp(buffer, "exit") == 0)
			break;
		if (_strcmp(buffer, "\n") == 0 || _strcmp(buffer, "\t") == 0)
		{
			_write("BombShell-$ ");
			continue;
		}
		words = input_word_counter(buffer);
		if (words > 0)
		{
			input_array = input_to_array(buffer, words);
			builtin_func = get_builtin_func(input_array[0]);
			if(builtin_func != NULL)
			{
				builtin_func(num_of_env_nodes, enviroment_array, input_array, env_head);
				_write("BombShell-$ ");
				continue;
			}
			cmd_executor(path_array, input_array, enviroment_array);
			free(input_array);
		}
		if (pipe == 0)
			_write("BombShell-$ ");
	}
	free_mem(buffer, input_head, env_head, enviroment_array, path_array);
	exit(EXIT_SUCCESS);
}
