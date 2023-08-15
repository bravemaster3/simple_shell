#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
extern char **environ;

#define PROMPT "$ "
#define UNUSED __attribute__((unused))

/* Printing char and string */
int _putchar(char c);
int _puts(char *str);

/* String operations */
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_substr(char *str, int index);
int _strsearch(char *hay, char *needle, int index);
int _strcmp(char *s1, char *s2);

/* Numbers */
int _isdigit(int c);
int _isnumber(char *str);
int _pow(int a, int b);
int _atoi(char *str);

/* functions for handling arrays */
char **tokenizer(char *buffer, char *delim);
int ctokens(char **tokens);
void free_grid(char **grid, int height);

/* Miscelleanous */
void exit_exec(char **tokens, int n_tok, char *buffer, char *path);
void not_found(char **tokens, int n_tok);
void handle_signal(int sig);
char *_getenv(const char *name);
char *_which(char *cmd);

/* Builtins */
void builtins(char **tokens, int n_tok, char *buffer);
void builtin_exit(char **tokens, int n_tok, char *buffer);
void builtin_env();

#endif /* MAIN_H */
