#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;

#define BUFFER_SIZE 1024

int handle_args(char *command, char **arr);
int check_builtins(char *command);
void execute_builtin(char **arr);
int execute_command(char **arr, char **env);
void print_env(void);
char *get_path(char *command, char **env);
void exit_shell(char *arg);
char *my_getline(void);

#endif
