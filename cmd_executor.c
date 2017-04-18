#include "shell.h"
int cmd_executor(char **path_folders, char **cmd, char **enviroment_array)
{
	char *folder;
	int i, j, k, l, exec_status, status;
	pid_t pid;
	i = j = k = l = exec_status = status = 0;

	for(i = 0; cmd[0][i] != '\0'; i++)
	{
		if(cmd[0][i] == '/' && cmd[0][i + 1] != '\0' && cmd[0][i + 1] != '/')
		{
			if (access(cmd[0], X_OK) == 0)
			{
				pid = fork();
				if (pid == 0)
				{
					exec_status = execve(cmd[0], cmd, enviroment_array);
					if(exec_status == -1)
						exit(EXIT_FAILURE);
					exit(EXIT_SUCCESS);
				}
				else
					wait(&status);
				return(status);
			}
		}
	}
	if(cmd[0][i] == '\0' && cmd[0][0] == '/')
	{
		printf("BombShell: Command not found!\n");
		return(1);
	}
	for(i = 0; path_folders[i] != '\0'; i++)
	{
		folder = _grand_malloc(_strlen(path_folders[i]) + _strlen(cmd[0]) + 2);
		for(j = 0; path_folders[i][j] != '\0'; j++)
			folder[j] = path_folders[i][j];
		folder[j] = '/';
		for(k = j + 1, l = 0; cmd[0][l] != '\0'; k++, l++)
			folder[k] = cmd[0][l];
		folder[k] = '\0';

		if (access(folder, X_OK) == 0)
		{
			pid = fork();
			if(pid == 0)
			{
				exec_status = execve(folder, cmd, enviroment_array);
				free(folder);
				if (exec_status == -1)
					exit(EXIT_FAILURE);
				exit(EXIT_SUCCESS);
			}
			else
				wait(&status);
			free(folder);
			return(status);
		}
		free(folder);
	}
	printf("BombShell: Command not found!\n");
	return(1);
}
