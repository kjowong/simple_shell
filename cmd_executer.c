#include "shell.h"

int cmd_executor(char **path_folders, char **cmd)
{
/*	char *folder;
	int i, j, k, l;*/
	int i, exec_status;
	pid_t pid;
	int status;
	(void) path_folders;
	for(i = 0; cmd[i] != '\0'; i++)
	{
		if(cmd[0][i] == '/')
		{
			pid = fork();
			if (pid == 0)
			{
				exec_status = execve(cmd[0], cmd, NULL);
				if(exec_status == -1)
					exit(EXIT_FAILURE);
				exit(EXIT_SUCCESS);
			}
			else
				wait(&status);
		}
		return(0);
	}
/*
	for(i = 0; path_folders[i] != '\0'; i++)
	{
		folder = _grand_malloc(_strlen(path_folders[i]) + _strlen(cmd) + 2);
		for(j = 0; path_folders[i][j] != '\0'; j++)
		{
			folder[j] = path_folders[i][j];
		}
		path_folders[i][j] = '/';
		for(k = j + 1, l = 0; cmd[l] != '\0'; k++, l++)
		{
			folder[k] = cmd[l];
		}
		folder[k] = '\0';
	}
	if(access(folder, X_OK) == 0)
	execve(folder, newargv, NULL);*/
	return(0);
}
