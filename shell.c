#include "shell.h"
/**
  * main - shell entry block
  * @void: no argument
  * Return: Exit Success
  */
int main(void)
{
	int (*builtin_func)();
	all_variables_t vars;

	struct stat sb;
	int read, pipe = 0;
	int i;

	build_all_variables(&vars);
	vars.n_env_nod = create_env_list(&vars);
	vars.env_ar = conv_list_to_array(vars.env_hd, vars.n_env_nod);
	vars.pth_ar = path_parserator(vars.env_hd);

	signal(SIGINT, SIG_IGN);

	if (fstat(STDIN_FILENO, &sb) == -1)
	{
		perror("Fstat Failed");
		exit(EXIT_FAILURE);
	}
	if ((sb.st_mode & S_IFMT) == S_IFIFO)
		pipe = 1;
	if (pipe == 0)
		_write("BombShell-$ ");
	while ((read = getline(&vars.buf, &vars.len, stdin)) != -1)
	{
		i = 0;
		/*buffer = input_parserator(buffer);*/
		if (_strcmp(vars.buf, "exit") == 0)
			break;
		if (_strcmp(vars.buf, "\n") == 0 || _strcmp(vars.buf, "\t") == 0)
		{
			_write("BombShell-$ ");
			continue;
		}
		vars.n_tok = input_word_counter(vars.buf);
		if (vars.n_tok > 0)
		{
			vars.in_ar = input_to_array(vars.buf, vars.n_tok);
			builtin_func = get_builtin_func(vars.in_ar[0]);
			if (builtin_func != NULL)
			{
				builtin_func(vars.n_env_nod, vars.env_ar, vars.in_ar, vars.env_hd);
				i = 1;
			}
			if (i == 0)
				cmd_executor(vars.pth_ar, vars.in_ar, vars.env_ar);
			free(vars.in_ar);
		}
		if (pipe == 0)
			_write("BombShell-$ ");
	}
	free_mem(vars.buf, vars.in_hd, vars.env_hd, vars.env_ar, vars.pth_ar);
	exit(EXIT_SUCCESS);
}
