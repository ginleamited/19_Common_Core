#include "../../inc/minishell.h"

int execute_pipeline(t_command *cmd, char **env) {
    int fd[2];
    int prev_fd = -1;
    pid_t pid;
    int last_status = 0;

    while (cmd) {
        if (cmd->next) {
            if (pipe(fd) == -1) {
                perror("pipe");
                return 1;
            }
        }
        pid = fork();
        if (pid == -1) {
            perror("fork");
            if (cmd->next) {
                close(fd[0]);
                close(fd[1]);
            }
            return 1;
        }
        if (pid == 0) { // Child
            signal(SIGINT, SIG_DFL); // Reset signals
            signal(SIGQUIT, SIG_DFL);
            if (prev_fd != -1) {
                dup2(prev_fd, STDIN_FILENO);
                if (close(prev_fd) == -1)
                    perror("close");
            }
            if (cmd->next) {
                dup2(fd[1], STDOUT_FILENO);
                if (close(fd[0]) == -1 || close(fd[1]) == -1)
                    perror("close");
            }
            setup_redirections(cmd);
            if (is_builtin(cmd->cmd))
                exit(execute_builtin(cmd, &env));
            else
                exit(execute_external(cmd, env));
        } else { // Parent
            if (prev_fd != -1 && close(prev_fd) == -1)
                perror("close");
            if (cmd->next) {
                if (close(fd[1]) == -1)
                    perror("close");
                prev_fd = fd[0];
            }
            cmd = cmd->next;
        }
    }
    while (waitpid(-1, &last_status, 0) > 0);
    return WEXITSTATUS(last_status); // Return last command's exit status
}