#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	int (*f)();
} builtin;


list_t *add_node_end(list_t **head, const char * s);
int _putchar(char);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strcmp_env(const char *s1, const char *s2);
size_t print_input_list(const list_t *h);
size_t print_env_list(const env_var_list_t *h);
char *_strdup(const char *str);
const char * _getenv(const char *name);
env_var_list_t *add_env_node(env_var_list_t **head, char *env_var);
int _setenv(const char *name, const char *value, int overwrite);
int _write(char *s);
int create_env_list(env_var_list_t **env);
void free_input_list(list_t *input_head);
void free_env_list(env_var_list_t *env_head);
char *_memset(char *s, char b, unsigned int n);
char *_memcopy(char *dest, char *src, unsigned int n);
char ** conv_list_to_array(env_var_list_t * env_head, int n);
#endif
