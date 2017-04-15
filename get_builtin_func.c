#include "shell.h"

int get_builtin_func(char * cmd)
{
	int i;
	builtin format [] = {
		{"cd", change_dir},
		{"env", get_env},
		{"exit", diffuse}
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"help", _help},
		{"history", _history},
		{"\0", NULL}
	};
	for (i = 0; format[i].cmd; i++)
	{
		if(_strcmp(cmd, format[i].cmd) == 0)
			return(format[i].f);
	}
	return (NULL);
}
