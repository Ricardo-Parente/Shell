#include "shell.h"

void type_prompt(void) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s%s%s minishell> ", CYN, cwd, RST);
    } else {
        printf("minishell> ");
    }
    fflush(stdout);
}