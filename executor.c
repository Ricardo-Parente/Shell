#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

void execute_command(char *command, char **parameters) {
    if (command[0] == '\0')  
        return;

    pid_t pid = fork(); 

    if (pid < 0) {
        perror("fork");

    } else if (pid != 0) {
        int status;
        waitpid(pid, &status, 0); 

    } else {
        execve(command, parameters, NULL);

        execvp(command, parameters);

        perror(command);
        exit(1); 
    }
}
