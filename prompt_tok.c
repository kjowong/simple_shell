#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;
	char * s;
	list_t *head;
	size_t n;

	head = NULL;
	write(1, "$ ", 2);

	while ((read = getline(&buffer, &len, stdin)) != -1)
	{
		if (_strcmp(buffer, "end-of-file") == 0 || _strcmp(buffer, "EOF") == 0)
			break;
		s = strtok(buffer, " ");
		while (s != NULL)
		{
			add_node_end(&head, s);
			/*write(1, s, _strlen(s));
			  write(1, " ", 1);*/
			s = strtok(NULL, " ");
		}
		write(1, "$ ", 2);
	}
	n = print_list(head);
	printf("n is: %lu\n", n);
	free(buffer);
	free_list(head);
	exit(EXIT_SUCCESS);
}
