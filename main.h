#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>

extern char **environ;

#define PROMPT "$ "
#define UNUSED __attribute__((unused))
#define UINT unsigned int
#define RESTR restrict
#define _WEXITSTATUS(status) (((status) & 0xff00) >> 8)

/* Printing char, string and uint*/
int _putchar(char c);
int _putchar2(char c, int fd);
int _puts(char *str);
int _puts2(char *str, int fd);
int print_uint(unsigned int n, int fd);
void print_err(UINT iter, char *cmd, char *message);


/* String operations */
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_substr(char *str, int index);
int _strsearch(char *hay, char *needle, int index);
int _strcmp(char *s1, char *s2);
char *_strtok(char *src, char *delim);
int _strncmp(char *s1, char *s2, size_t n);

/* Memory allocation */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* Numbers */
int _isdigit(int c);
int _isnumber(char *str);
int _pow(int a, int b);
int _atoi(char *str);


/* functions for handling arrays */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **tokenizer(char *buffer, char *delim);
int ctokens(char **tokens);
void free_grid(char **grid, int height);


/* Miscelleanous */
void exit_exec(char **tokens, int n_tok, char *buffer, char *path, UINT iter);
void not_found(char **tokens, int n_tok, UINT iter);
void handle_signal(int sig);
char *_getenv(const char *name);
int _getenvi(const char *name);
char *_which(char *cmd);
int is_path(char *str);


/* Builtins */
void builtins(char **tokens, int n_tok, char *buffer, UINT iter);
void builtin_exit(char **tokens, int n_tok, char *buffer, UINT iter);
void builtin_env(void);
int isbuiltin(char *cmd);
void builtin_setenv(char *var, char *value);
void builtin_setenv_old(char *var, char *value);
void builtin_unsetenv(char *var);
void builtin_cd(char **tokens, UINT iter);

#endif /* MAIN_H */
