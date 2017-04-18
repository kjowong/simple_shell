#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
extern char **environ;
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char * str;
	unsigned int len;
	struct list_s *next;
} list_t;
/**
 * struct env_var_list_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct env_var_list_s
{
	char * key;
	char * value;
	struct env_var_list_s *next;
} env_var_list_t;
/**
 */
typedef struct builtin_s
{
	char * cmd;
	int (*func)();
} builtin;

typedef struct all_variables
{
	char *buffer;
	size_t num_of_env_nodes;
	size_t len;
	list_t *input_head;
	env_var_list_t *env_head;
	char **enviroment_array;
	char **path_array;
	char **input_array;
	int num_of_tokens;
	int (*builtin_func)();

} all_variables_t;
all_variables_t *build_all_variables(all_variables_t *var_s);
list_t *add_node_end(list_t **head, const char * s);
int _putchar(char);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int len);
int _strcmp_env(const char *s1, const char *s2);
size_t print_input_list(const list_t *h);
size_t print_env_list(const env_var_list_t *h);
char *_strdup(const char *str);
const char * _getenv(const char *name);
env_var_list_t *add_env_node(env_var_list_t **head, char *env_var);
int _write(char *s);
int create_env_list(all_variables_t *all_var_s);
void free_input_list(list_t *input_head);
void free_env_list(env_var_list_t *env_head);
char *_memset(char *s, char b, unsigned int n);
char *_memcopy(char *dest, char *src, unsigned int n);
char ** conv_list_to_array(env_var_list_t * env_head, int n);
void free_env_array(char **array);
void free_mem(char *buffer, list_t *input_head, env_var_list_t *env_head, char **enviroment_list, char **path_array);
void free_path_array(char **array);
char **path_parserator(env_var_list_t *env_head);
unsigned int path_folder_counter(char *paths);
void *_grand_malloc(size_t mem_needed);
int cmd_executor(char **path_array, char **input_array, char **enviroment_array);
char **conv_inputlist_to_array(list_t *input_list_head, size_t i);
int input_word_counter(char * buffer);
char **input_to_array(char *buffer, int num_of_tokens);
char *input_parserator(char *input_buffer);
int print_env(size_t num_of_env_nodes, char **enviroment_list, char **input_array, env_var_list_t *env_head);
int _setenv(size_t num_of_env_nodes, char **enviroment_list, char **input_array, env_var_list_t **env_head);
int (*get_builtin_func(char * cmd))();
#endif
