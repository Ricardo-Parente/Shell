#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

void read_command(char *command, char **parameters) {
    static char buffer[MAX_INPUT]; 
    int  i = 0;

    if (fgets(buffer, MAX_INPUT, stdin) == NULL) {
        printf("\n");
        exit(0);
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    char *token = strtok(buffer, " ");
    while (token != NULL && i < MAX_ARGS - 1) {
        parameters[i++] = token;
        token = strtok(NULL, " ");
    }
    parameters[i] = NULL; 

    if (i > 0)
        strcpy(command, parameters[0]);
    else
        command[0] = '\0'; 
}