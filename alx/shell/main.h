#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct list_t
{
	char *p;
	struct list_t *next;
} list_t;

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
void *_realloc(void *ptr, unsigned int new_size);
ssize_t _getline(char **line, size_t *size, FILE *source);
void error_exec(char *err_msg, char *prg, unsigned int ncmd, char *cmd);
void error_ret(char *err_msg, char *prg, unsigned int ncmd,
		char *cmd, char *tmp);
int _strncmp(char *s1, char *s2, size_t n);
char **line_tokenizing(char *line, char *delim);
char *_getenv(char *s, char **env);
char **_getPATH(char *str, char **env);
size_t print_list(const list_t *h);
list_t *add_node_end(list_t **head, char *p);
size_t pathTolist(list_t **head, char *path);
void free_list(list_t **head);

#endif
