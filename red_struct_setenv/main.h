#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct list_t - singly linked list
 * @path: a path variable value
 * @next: points to the next node
 *
 * Description: PATH structure list
 *
 */
typedef struct list_t
{
	char *path;
	struct list_t *next;
} list_t;

/**
 * struct env - singly linked list
 * @env: an env variable value
 *
 * Description: custom Environ structure
 *
 */

typedef struct env
{
	char **env;
} Env;


char *_strchr(char *s, char c);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
void start_check(int ac);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int check_exit(char *s, int *exit_code, char *prg, unsigned int ncmd);
int check_env(char *s);
unsigned int _strcspn(char *s, char *reject);
void white_check(char *s);
extern char **environ;
char *_strtok(char *str, const char *delim);
unsigned int _strspn_token(char *s, const char *accept);
char *_strpbrk_token(char *s, const char *accept);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **line, size_t *size, FILE *source);
void error_exec(char *err_msg, char *prg, unsigned int ncmd, char *cmd);
void error_ret(char *err_msg, char *prg, unsigned int ncmd,
		char *cmd, char *tmp);
char **line_tokens(char *line, char *delim);
char *get_cmd(list_t *head, char *str, int *exit_code,
		char *exec_err, char *name, unsigned int ncmd);
int check_space(char *str);

void free_list(list_t **head);
size_t print_list(const list_t *h);
list_t *add_node_end(list_t **head, const char *p);
char *_getenv(char *s, char **env);
char *cmd_to_path(list_t *head, char *command);
int PathToList(list_t **head, char *path);
char *_liner(char *str);
void free_grid(char **grid);
int _built(char *token_0);
void _exec_built(char **token_0, int *exit_code, unsigned int ncmd, char *prg, Env *env);
/*void _printenv(char **tokens, int *exit_code, Env *env);*/
int _set_env(char *var_name, char *var_value, int condition, Env *env);
int _unset_env(char *var_name, Env *env);
char **cp_env(char **environ);
Env *create_env(char **environ);

int _is_built(char *token_0);
int change_dir(char **token, char *prg, unsigned int ncmd, Env *env);
void error_cd(char *BUF, char *prg, unsigned int ncmd, char *dir);

void free_char1(const unsigned int n, ...);

void _printenv(Env *env);

int _strncmp(char *s1, char *s2, int num);
#endif
