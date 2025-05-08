#include "../../inc/minishell.h"

void setup_input_redirection(t_command *cmd) {
    if (cmd->input_file) {
        int fd = open(cmd->input_file, O_RDONLY);
        if (fd < 0) {
            perror(cmd->input_file);
            exit(1);
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
}

void setup_output_redirection(t_command *cmd) {
    if (cmd->output_file) {
        int flags = O_WRONLY | O_CREAT | (cmd->append ? O_APPEND : O_TRUNC);
        int fd = open(cmd->output_file, flags, 0644);
        if (fd < 0) {
            perror(cmd->output_file);
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
}

void setup_heredoc(t_command *cmd) {
    if (cmd->is_heredoc && cmd->heredoc_content) {
        int fd[2];
        if (pipe(fd) == -1) {
            perror("pipe");
            exit(1);
        }
        write(fd[1], cmd->heredoc_content, ft_strlen(cmd->heredoc_content));
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
    }
}

void setup_redirections(t_command *cmd) {
    setup_input_redirection(cmd);
    setup_output_redirection(cmd);
    setup_heredoc(cmd);
}