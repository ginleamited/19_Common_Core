/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:30:11 by jilin             #+#    #+#             */
/*   Updated: 2025/05/07 16:31:21 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char **duplicate_env(char **envp) {
    int i = 0;
    while (envp[i])
        i++;
    char **new_env = malloc(sizeof(char *) * (i + 1));
    for (i = 0; envp[i]; i++)
        new_env[i] = strdup(envp[i]);
    new_env[i] = NULL;
    return new_env;
}

void handle_sigint(int sig) {
    printf("\n");
    rl_on_new_line(); // Reset readline prompt
    rl_replace_line("", 0);
    rl_redisplay();
}

void setup_signals(void) {
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN); // Ignore Ctrl+\
}

int is_builtin(char *cmd) {
    return (strcmp(cmd, "cd") == 0 || strcmp(cmd, "exit") == 0 ||
            strcmp(cmd, "env") == 0 || strcmp(cmd, "export") == 0 ||
            strcmp(cmd, "unset") == 0 || strcmp(cmd, "pwd") == 0 ||
            strcmp(cmd, "echo") == 0);
}

int execute_builtin(t_command *cmd, char ***env) {
    if (strcmp(cmd->cmd, "cd") == 0)
        return builtin_cd(cmd->args, env);
    if (strcmp(cmd->cmd, "exit") == 0)
        return builtin_exit(cmd->args);
    // Add other built-ins
    return 0;
}