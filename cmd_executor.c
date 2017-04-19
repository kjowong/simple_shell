#include "shell.h"
/**
  * cmd_executor - function to execute the user commands
  * @path_folders: double pointer array to the path
  * @cmd: double pointer to the command inputted
  * @env_array: double pointer to the environment linked list
  * Return: 1
 */
int cmd_executor(char **path_folders, char **cmd, char **env_array)
{
	char *folder;
	int i, j, k, l, status;
	pid_t pid;

	i = j = k = l = status = 0;
	for (i = 0; cmd[0][i] != '\0'; i++)
	{
		if (cmd[0][i] == '/' && cmd[0][i + 1] != '\0' && cmd[0][i + 1] != '/')
		{
			if (access(cmd[0], X_OK) == 0)
			{
				pid = fork();
				if (pid < 0)
				{
					perror("Fork Failed");
					exit(EXIT_FAILURE);
				}
				if (pid == 0)
				{
					execve(cmd[0], cmd, env_array);
					exit(EXIT_SUCCESS);
				}
				else
					wait(&status);
				return (status);
			}
		}
	}
	if (cmd[0][i] == '\0' && cmd[0][0] == '/')
	{
		_write(cmd[0]);
		_write(": No such file or directory\n");
		return (1);
	}
	for (i = 0; path_folders[i] != '\0'; i++)
	{
		folder = _grand_malloc(_strlen(path_folders[i]) + _strlen(cmd[0]) + 2);
		for (j = 0; path_folders[i][j] != '\0'; j++)
			folder[j] = path_folders[i][j];
		folder[j] = '/';
		for (k = j + 1, l = 0; cmd[0][l] != '\0'; k++, l++)
			folder[k] = cmd[0][l];
		folder[k] = '\0';
		if (access(folder, X_OK) == 0)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("Fork Failed");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				execve(folder, cmd, env_array);
				free(folder);
				exit(EXIT_SUCCESS);
			}
			else
				wait(&status);
			free(folder);
			return (status);
		}
		free(folder);
	}
	_write(cmd[0]);
	_write(": command not found\n");
	return (1);
}
