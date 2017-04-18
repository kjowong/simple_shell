#include "shell.h"

int main(void)
{
	int (*builtin_func)();
	all_variables_t bs_vars;

	struct stat sb;
	int read, pipe = 0;
	int i;

	build_all_variables(&bs_vars);
	bs_vars.num_of_env_nodes = create_env_list(&bs_vars);
	bs_vars.enviroment_array = conv_list_to_array(bs_vars.env_head, bs_vars.num_of_env_nodes);
	bs_vars.path_array = path_parserator(bs_vars.env_head);

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
	while ((read = getline(&bs_vars.buffer, &bs_vars.len, stdin)) != -1)
	{
		i = 0;
		/*buffer = input_parserator(buffer);*/
		if(_strcmp(bs_vars.buffer, "exit") == 0)
			break;
		if (_strcmp(bs_vars.buffer, "\n") == 0 || _strcmp(bs_vars.buffer, "\t") == 0)
		{
			_write("BombShell-$ ");
			continue;
		}
		bs_vars.num_of_tokens = input_word_counter(bs_vars.buffer);
		if (bs_vars.num_of_tokens > 0)
		{
			bs_vars.input_array = input_to_array(bs_vars.buffer, bs_vars.num_of_tokens);
			builtin_func = get_builtin_func(bs_vars.input_array[0]);
			if(builtin_func != NULL)
			{
				builtin_func(bs_vars.num_of_env_nodes, bs_vars.enviroment_array, bs_vars.input_array, bs_vars.env_head);
				i = 1;
			}
			if (i == 0)
				cmd_executor(bs_vars.path_array, bs_vars.input_array, bs_vars.enviroment_array);
			free(bs_vars.input_array);
		}
		if (pipe == 0)
			_write("BombShell-$ ");
	}
	free_mem(bs_vars.buffer, bs_vars.input_head, bs_vars.env_head, bs_vars.enviroment_array, bs_vars.path_array);
	exit(EXIT_SUCCESS);
}
