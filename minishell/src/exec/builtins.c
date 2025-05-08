#include "../../inc/minishell.h"

int is_builtin(char *cmd) {
    return (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "exit") == 0 ||
            ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "export") == 0 ||
            ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "pwd") == 0 ||
            ft_strcmp(cmd, "echo") == 0);
}

int execute_builtin(t_command *cmd, char ***env) {
    if (ft_strcmp(cmd->cmd, "cd") == 0)
        return builtin_cd(cmd->args, env);
    if (ft_strcmp(cmd->cmd, "exit") == 0)
        return builtin_exit(cmd->args);
    if (ft_strcmp(cmd->cmd, "env") == 0)
        return builtin_env(*env);
    if (ft_strcmp(cmd->cmd, "export") == 0)
        return builtin_export(cmd->args, env);
    if (ft_strcmp(cmd->cmd, "unset") == 0)
        return builtin_unset(cmd->args, env);
    if (ft_strcmp(cmd->cmd, "pwd") == 0)
        return builtin_pwd();
    if (ft_strcmp(cmd->cmd, "echo") == 0)
        return builtin_echo(cmd->args);
    return 0;
}

int builtin_cd(char **args, char ***env) {
    char *path = args[1] ? args[1] : get_env("HOME", *env);
    if (!path) {
        write(STDERR_FILENO, "cd: HOME not set\n", 17);
        return 1;
    }
    // Store current directory for OLDPWD
    char *oldpwd = getcwd(NULL, 0);
    if (chdir(path) != 0) {
        perror("cd");
        free(oldpwd);
        return 1;
    }
    // Update OLDPWD
    if (oldpwd) {
        char *oldpwd_env = ft_strjoin("OLDPWD=", oldpwd);
        if (!oldpwd_env) {
            free(oldpwd);
            return 1;
        }
        set_env(oldpwd_env, env);
        free(oldpwd_env);
        free(oldpwd);
    }
    // Update PWD
    char *pwd = getcwd(NULL, 0);
    if (!pwd) {
        perror("getcwd");
        return 1;
    }
    char *pwd_env = ft_strjoin("PWD=", pwd);
    if (!pwd_env) {
        free(pwd);
        return 1;
    }
    set_env(pwd_env, env);
    free(pwd_env);
    free(pwd);
    return 0;
}

int builtin_exit(char **args) {
    if (args[1] && args[2]) {
        write(STDERR_FILENO, "exit: too many arguments\n", 25);
        return 1;
    }
    int status = 0;
    if (args[1]) {
        // Validate numeric argument
        for (int i = 0; args[1][i]; i++) {
            if (!ft_isdigit(args[1][i]) && !(i == 0 && args[1][i] == '-')) {
                write(STDERR_FILENO, "exit: numeric argument required\n", 31);
                exit(255);
            }
        }
        status = ft_atoi(args[1]);
    }
    exit(status);
}

int builtin_env(char **env) {
    for (int i = 0; env[i]; i++)
        printf("%s\n", env[i]);
    return 0;
}

int builtin_export(char **args, char ***env) {
    if (!args[1]) {
        return builtin_env(*env);
    }
    for (int i = 1; args[i]; i++) {
        // Validate variable name (must start with letter or underscore)
        if (ft_strchr(args[i], '=')) {
            char *key = ft_substr(args[i], 0, ft_strchr(args[i], '=') - args[i]);
            if (!key || !key[0] || (!ft_isalpha(key[0]) && key[0] != '_')) {
                write(STDERR_FILENO, "export: invalid identifier\n", 27);
                free(key);
                continue;
            }
            free(key);
            set_env(args[i], env);
        }
    }
    return 0;
}

int builtin_unset(char **args, char ***env) {
    for (int i = 1; args[i]; i++) {
        int key_len = ft_strlen(args[i]);
        int j = 0;
        while ((*env)[j]) {
            if (ft_strncmp((*env)[j], args[i], key_len) == 0 && (*env)[j][key_len] == '=') {
                free((*env)[j]);
                while ((*env)[j]) {
                    (*env)[j] = (*env)[j + 1];
                    j++;
                }
            } else {
                j++;
            }
        }
    }
    return 0;
}

int builtin_pwd(void) {
    char *pwd = getcwd(NULL, 0);
    if (!pwd) {
        perror("pwd");
        return 1;
    }
    printf("%s\n", pwd);
    free(pwd);
    return 0;
}

int builtin_echo(char **args) {
    int no_newline = 0;
    int i = 1;
    if (args[1] && ft_strcmp(args[1], "-n") == 0) {
        no_newline = 1;
        i++;
    }
    while (args[i]) {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" ");
        i++;
    }
    if (!no_newline)
        printf("\n");
    return 0;
}

void set_env(char *keyval, char ***env) {
    int i = 0;
    size_t key_len = ft_strchr(keyval, '=') - keyval;
    char *key = ft_substr(keyval, 0, key_len);
    if (!key)
        return;
    while ((*env)[i]) {
        if (ft_strncmp((*env)[i], key, key_len) == 0 && (*env)[i][key_len] == '=') {
            free((*env)[i]);
            (*env)[i] = ft_strdup(keyval);
            free(key);
            return;
        }
        i++;
    }
    char **new_env = malloc(sizeof(char *) * (i + 2));
    if (!new_env) {
        free(key);
        return;
    }
    for (int j = 0; j < i; j++)
        new_env[j] = (*env)[j];
    new_env[i] = ft_strdup(keyval);
    if (!new_env[i]) {
        free(new_env);
        free(key);
        return;
    }
    new_env[i + 1] = NULL;
    free(*env);
    *env = new_env;
    free(key);
}