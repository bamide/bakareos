#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 1024 
#define MAX_LINE_LENGTH 104
#define BUFFSIZE_STD 128
#define DELIM " \t\r\a\n"
#define MAX_TOKENS 100   

typedef struct Alias {
    char *name;
    char *value;
    struct Alias *next;
} Alias;

int prompt(int argc, char **argv, char **env);
char *getLine(char *buffer, int status);
char **parse(char *line, char *delimiter);
void create_process(char *command, char **arrayStr, char **argv, char *env[]);
int accessCommand(char **arrayStr, char **argv, char *env[]);
char *_strcat(char *src, char *dest);
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int is_builtin_command(char *command);
void execute_builtin_command(char *command, char **args, char **argv,
char *env[]);
int shell_exit(char *command, char **args, char **argv);
int isnumber(char *s);
char *get_path(char **env);
void *_realloc(void *ptr, size_t new_size);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);
int handle_path(char **arrayStr, char **argv, char **env);
void command_not_found(char **arrayStr, char **argv);
char *_strdup(const char* str);
void *_memcpy(void *dest, const void *src, size_t size);
void execute_command(char **token_array);
void set_environment_variable(char **token_array);
void unset_environment_variable(char **token_array);
void display_non_interactive(char **av);
void write_output(const char *output);
void print_aliases();
Alias *find_alias(char *name);
void add_alias(char *name, char *value);
void free_aliases();

#endif
