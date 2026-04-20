#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

#define CYN "\x1B[1;36m"
#define RED "\x1B[1;31m"
#define RST "\x1B[0m"

void type_prompt(void);
void read_command(char *command, char **parameters);
void execute_command(char *command, char **parameters);
void shell_loop(void);

#endif