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

char *_strcpy(char *dest, char *src);
void start_check(int ac);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int check_exit(char *s,int *exit_code, char *prg, unsigned int ncmd);
int check_env(char *s);
unsigned int _strcspn(char *s, char *reject);
void white_check(char *s);
extern char **environ;
char *_strtok(char *str, const char *delim);
unsigned int _strspn_token(char *s, const char *accept);
char *_strpbrk_token(char *s, const char *accept);
char *_strcat(char *dest, char *src);

#endif
