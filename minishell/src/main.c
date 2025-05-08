#include "../inc/minishell.h"

// Helper function to update $? with the last command's exit status
void update_exit_status(int status, char ***env) {
    char *status_str = ft_itoa(status);
    if (!status_str)
        return; // Handle allocation failure
    char *exit_status = ft_strjoin("?=", status_str);
    free(status_str); // Free ft_itoa result
    if (exit_status) {
        set_env(exit_status, env);
        free(exit_status);
    }
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **envp) {
    char **env = duplicate_env(envp);
    if (!env) {
        write(STDERR_FILENO, "Error: Failed to duplicate environment\n", 38);
        return 1;
    }
    setup_signals();
    char *line;
    while ((line = readline("minishell> "))) {
        if (*line) {
            add_history(line);
            t_command *cmd = parse_input(line);
            if (cmd) {
                int status = execute(cmd, &env);
                update_exit_status(status, &env); // Store exit status in $?
                free_command(cmd);
            }
        }
        free(line);
    }
    write(STDOUT_FILENO, "exit\n", 5);
    ft_free_array(env);
    return 0;
}