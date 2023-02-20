#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;

char **env;

int handle_args(char *command, char **arr);
int check_builtins(char *command);
void execute_builtin(char **arr);
void execute_command(char **arr);
void print_env(void);

#endif
