#include "shell.h"

char ** conv_list_to_array(env_var_list_t * env_head, int n)
{
	char **array;
	env_var_list_t *tmp;
	int i, len, nodes;

	i = len = nodes = 0;
	tmp = env_head;
	i = n;
	while(i > 0)
	{
		tmp = tmp->next;
		nodes++;
		printf("i is %d\n", i--);
	}
	printf("right aftet the secong");
	tmp = env_head;
	array = malloc(sizeof(char *) * (nodes + 1));
	while (tmp != NULL)
	{
		printf("tmp is NOTTTTTT NULL!!!!!!");
		len = _strlen(tmp->key) + _strlen(tmp->value) + 2;
		array[i] = malloc(sizeof(char) * len);
		_memset(array[i], '\0', len);
		_memcopy(array[i], tmp->key, sizeof(tmp->key));
/*		_memcopy(array[i][(char *)sizeof(tmp->key)], '=', 1);
		_memcopy(array[i][sizeof(tmp->key) + 1], tmp->value, sizeof(tmp->value));*/
		tmp = tmp->next;
		i++;
		printf("%s\n", array[i]);
	}
	array[i] = NULL;
	return(array);
}
