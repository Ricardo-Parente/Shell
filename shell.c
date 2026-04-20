#include "shell.h"

void shell_loop(void) {
    char command[MAX_INPUT];
    char *parameters[MAX_ARGS];

    while (1) {
        type_prompt();
        read_command(command, parameters);

        if (command[0] == '\0') continue;
        
        if (strcmp(command, "exit") == 0) {
            break;
        }

        if (strcmp(command, "cd") == 0) {
            char *path = parameters[1] ? parameters[1] : getenv("HOME");
            if (chdir(path) != 0) {
                perror("minishell: cd");
            }
            continue; 
        }

        // Comandos Externos
        execute_command(command, parameters);
    }
}