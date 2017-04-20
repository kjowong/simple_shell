#include "shell.h"
/**
 * main - shell entry block
 * @void: no argument
 * Return: Exit Success
 */
int main(void)
{
	all_variables_t vars;
	struct stat sb;
	int i = 0, pipe = 0;

	build_all_variables(&vars);
	vars.n_env_nod = create_env_list(&vars);
	vars.env_ar = conv_list_to_array(vars.env_hd, vars.n_env_nod);
	vars.pth_ar = path_parserator(vars.env_hd);

	signal(SIGINT, signal_handler);
	if (fstat(STDIN_FILENO, &sb) == -1)
	{ perror("Fstat Failed"); exit(EXIT_FAILURE); }
	if ((sb.st_mode & S_IFMT) == S_IFIFO)
		pipe = 1;
	if (pipe == 0)
		_write("$ ");
	while (getline(&vars.buf, &vars.len, stdin) != -1)
	{	i = 0;
		if (_strcmp(vars.buf, "exit") == 0)
			break;
		if (_strcmp(vars.buf, "\n") == 0 || _strcmp(vars.buf, "\t") == 0)
		{ _write("$ "); continue; }
		vars.n_tok = input_token_count(vars.buf);
		if (vars.n_tok > 0)
		{	vars.in_ar = input_to_array(vars.buf, vars.n_tok);
			vars.builtin_func = get_builtin_func(vars.in_ar[0]);
			if (vars.builtin_func != NULL)
			{	vars.builtin_func(&vars);
				i = 1;
			}
			if (i == 0)
				i = full_path_executor(vars.in_ar, vars.env_ar);
			if (i == 2)
				path_cmd_executor(vars.pth_ar, vars.in_ar, vars.env_ar);
			free(vars.in_ar);
		}
		if (pipe == 0)
			_write("$ ");
	}
	free_mem(&vars); exit(EXIT_SUCCESS);
}
/**
 * signal_handler - handles ^C input
 * @sig: signal value
 * Return: void
 */
void signal_handler(int sig)
{
	(void) sig;
	_write("\n$ ");
}
