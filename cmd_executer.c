#include "shell.h"

int cmd_executor(char **path_folders, char **cmd)
{
	char *folder;
	int i, j, k, l, status;
	pid_t pid;

	for(i = 0; cmd[0][i] != '\0'; i++)
	{
		if(cmd[0][i] == '/')
		{
			if (access(cmd[0], X_OK) == 0)
			{
				pid = fork();
				if (pid < 0)
					perror("Error\n");
				if (pid == 0)
				{
					execve(cmd[0], cmd, NULL);
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
			if (pid < 0)
				perror("Error\n");
			if(pid == 0)
			{
				execve(folder, cmd, NULL);
				free(folder);
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
