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
 * struct list_s - singly linked list
 * @str: points to the string
 * @len: points to the length
 * @next: points to the next node
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
/**
 * struct env_var_list_s - singly linked list
 * @key: points to the key
 * @value: points to the value
 * @next: points to the next node
 */
typedef struct env_var_list_s
{
	char *key;
	char *value;
	struct env_var_list_s *next;
} env_t;
/**
  * struct builtin_s - function pointer
  * @cmd: takes in a command from user
  * @func: pointer to a function
 */
typedef struct builtin_s
{
	char *cmd;
	int (*func)();
} builtin;
/**
  * struct all_variables - struct that holds all variables for functions
  * @buffer: buffer for user input
  * @num_of_env_nodes: number of nodes in environment linked list
  * @len: length
  * @input_head: user input in a linked list
  * @env_head: environment variable linked list
  * @env_array: environment variables in double pointer array
  * @path_array: the path in a double pointer array
  * @input_array: user input in double pointer array
  * @num_of_tokens: the number of tokens
  * builtin_func: function pointer
  */
typedef struct all_variables
{
	char *buffer;
	size_t num_of_env_nodes;
	size_t len;
	list_t *input_head;
	env_t *env_head;
	char **env_array;
	char **path_array;
	char **input_array;
	int num_of_tokens;
	int (*builtin_func)();

} all_variables_t;

/* string functions */
int _putchar(char);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int len);
int _strcmp_env(const char *s1, const char *s2);
char *_strdup(const char *str);
int _write(char *s);

/* Environment Functions */
size_t print_env_list(const env_t *h);
const char *_getenv(const char *name);
env_t *add_env_node(env_t **head, char *env_var);
int create_env_list(all_variables_t *all_var_s);
char **conv_list_to_array(env_t *env_head, int n);
int print_env(size_t num_of_env_nodes, char **env_list, char **input_array, env_t *env_head);
int _setenv(size_t num_of_env_nodes, char **env_list, char **input_array, env_t **env_head);
char **path_parserator(env_t *env_head);

/* Free Functions */
void free_env_array(char **array);
void free_mem(char *buffer, list_t *input_head, env_t *env_head, char **env_list, char **path_array);
void free_path_array(char **array);
void free_input_list(list_t *input_head);
void free_env_list(env_t *env_head);

/* Input Functions */
size_t print_input_list(const list_t *h);
int input_word_counter(char *buffer);
char **input_to_array(char *buffer, int num_of_tokens);
char *input_parserator(char *input_buffer);
char **conv_inputlist_to_array(list_t *input_list_head, size_t i);
list_t *add_node_end(list_t **head, const char *s);

/* Memory Functions */
void *_grand_malloc(size_t mem_needed);
char *_memset(char *s, char b, unsigned int n);
char *_memcopy(char *dest, char *src, unsigned int n);

/* Struct Function */
all_variables_t *build_all_variables(all_variables_t *var_s);
int (*get_builtin_func(char *cmd))();

/* Execution Functions */
unsigned int path_folder_counter(char *paths);
int cmd_executor(char **path_array, char **input_array, char **env_array);
#endif
