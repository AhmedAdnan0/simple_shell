#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* print_functions.c */
int _putchar(char c);
void print_str(char *str);
void print_int(int x);
void print_env(char **env);
void print_err(char *sh, char *cmd, int is_tty);

/* string_functions.c */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *getcmd(void);

/* getenv.c */
char *_getenv(const char *var, char **env);

#endif /* _FUNC_H_ */
