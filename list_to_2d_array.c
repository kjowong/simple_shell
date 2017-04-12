#include "shell.h"

char ** conv_list_to_array(env_var_list_t * env_head, int n)
{
	char **array;
	env_var_list_t *tmp;
	int i, len, nodes, j;
	char * val;

	i = len = nodes = 0;
	tmp = env_head;
	i = n;
	while(i > 0)
	{
		tmp = tmp->next;
		nodes++;
		printf("i is %d\n", i--);
	}
	tmp = env_head;
	array = malloc(sizeof(char *) * (nodes + 1));
	i = 0;
	while (tmp != NULL)
	{
		len = _strlen(tmp->key) + _strlen(tmp->value) + 2;
		array[i] = malloc(sizeof(char) * len);
		_memset(array[i], '\0', len);
		_memcopy(array[i], tmp->key, _strlen(tmp->key));
		array[i][_strlen(tmp->key)] = '=';
		val = tmp->value;
		for (j = 0; j < _strlen(tmp->value); j++)
		{
			array[i][_strlen(tmp->key) + 1 + j] = val[j];
		}
		printf("%s\n", array[i]);
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	return(array);
}
