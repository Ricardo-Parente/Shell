#include <string.h>
#include <stdlib.h>
#include "shell.h"

void shell_loop(void) {
    char  command[MAX_INPUT];
    char *parameters[MAX_ARGS];

    while (1) {
        type_prompt();                      
        read_command(command, parameters);  

        if (strcmp(command, "exit") == 0)
            break;

        execute_command(command, parameters); 
    }
}
