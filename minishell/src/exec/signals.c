#include "../../inc/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void handle_sigint(__attribute__((unused)) int sig) {
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void setup_signals(void) {
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);
}