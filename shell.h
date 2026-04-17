#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT  256
#define MAX_ARGS    32

void type_prompt(void);

void read_command(char *command, char **parameters);

void execute_command(char *command, char **parameters);

void shell_loop(void);

#endif
