#include "shell.h"

int (*get_builtin_func(char *cmd))()
{
	int i;
	builtin format [] = {
		{"env", print_env},
		{"setenv", _setenv},
/*		{"cd", change_dir},
		{"exit", diffuse},
		{"unsetenv", _unsetenv},
		{"help", _help},
		{"history", _history},*/
		{NULL, NULL}
	};
	for (i = 0; format[i].cmd; i++)
	{
		if(_strcmp(cmd, format[i].cmd) == 0)
			return(format[i].func);
	}
	return (NULL);
}
