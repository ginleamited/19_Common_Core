#include "../../inc/minishell.h"

char *find_executable(char *cmd, char **env) {
    char *path = get_env("PATH", env);
    char **dirs = ft_split(path, ':');
    char *full_path;
    int i = 0;

    if (!dirs)
        return ft_strdup(cmd);
    while (dirs[i]) {
        full_path = ft_strjoin(dirs[i], "/");
        if (!full_path) {
            ft_free_array(dirs);
            return NULL;
        }
        char *temp = full_path;
        full_path = ft_strjoin(full_path, cmd);
        free(temp); // Free the intermediate full_path
        if (!full_path) {
            ft_free_array(dirs);
            return NULL;
        }
        if (access(full_path, X_OK) == 0) {
            ft_free_array(dirs);
            return full_path;
        }
        free(full_path);
        i++;
    }
    ft_free_array(dirs);
    return ft_strdup(cmd);
}

int execute_external(t_command *cmd, char **env) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid == 0) { // Child
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        setup_redirections(cmd);
        char *path = find_executable(cmd->cmd, env);
        if (!path) {
            write(STDERR_FILENO, "Memory allocation failed\n", 25);
            exit(1);
        }
        if (access(path, X_OK) != 0) {
            write(STDERR_FILENO, cmd->cmd, ft_strlen(cmd->cmd));
            write(STDERR_FILENO, ": command not found\n", 20);
            free(path);
            exit(127);
        }
        execve(path, cmd->args, env);
        perror("execve");
        free(path);
        exit(1);
    } else { // Parent
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}