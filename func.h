#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* print_functions.c */
int _putchar(char c);
void print_str(char *str);
void print_int(int x);
void print_env(char **env);

/* print_errors.c */
int _putchar_err(char c);
void print_str_err(char *str);
void print_int_err(int x);
void print_err(char *sh, char *cmd, int counter, int errno);

/* string_functions.c */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_memset(char *str, char c, unsigned int n);
int _atoi(char *str);

/* string2_functions.c */
int _strlen(char *s);

/* mem-functions.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* getenv.c */
char *_getenv(const char *var, char **env);

/* strtok.c */			/* Not working yet */
int check_delim(char c, char *delim);

/* getline.c */

/* helper.c */
char *_strtok(char *ptr, char *delim);
void comment_handler(char **str);
void echo(char **arg);

#endif /* _FUNC_H_ */
