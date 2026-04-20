#include "shell.h"

void execute_command(char *command, char **parameters) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Erro ao criar processo (fork)");
    } 
    else if (pid == 0) {
        // PROCESSO FILHO
        if (execvp(command, parameters) == -1) {
            fprintf(stderr, "%sminishell: comando não encontrado: %s%s\n", RED, command, RST);
            exit(EXIT_FAILURE);
        }
    } 
    else {
        // PROCESSO PAI
        int status;
        waitpid(pid, &status, 0);

        // Opcional: Avisar se o processo terminou com erro
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            // Apenas um log silencioso ou tratamento se necessário
        }
    }
}