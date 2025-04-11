/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:38:43 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:21:35 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_executable(char **path, char *cmd)
{
    char	*temp;
    char	*cmd_path;
    int		i;

    i = 0;
    while (path[i])
    {
        temp = ft_strjoin(path[i], "/");
        if (!temp)
            return (NULL);
        cmd_path = ft_strjoin(temp, cmd);
        free(temp);
        if (!cmd_path)
            return (NULL);
        if (access(cmd_path, X_OK) == 0)
            return (cmd_path);
        free(cmd_path);
        i++;
    }
    return (NULL);
}

void ft_run(char **args, char *cmd, char **env)
{
    char **path;
    char *cmd_path;

    if (!cmd || !args || !args[0])
    {
        ft_free(args);
        exit(127);
    }

    path = ft_find_path(env);
    if (!path)
    {
        ft_putstr_fd("PATH not found\n", 2);
        ft_free(args);
        exit(127);
    }

    cmd_path = find_executable(path, cmd);
    ft_free(path);

    if (cmd_path)
    {
        execve(cmd_path, args, env);
        free(cmd_path);
    }

    ft_putstr_fd("Failed to execute: ", 2);
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd("\n", 2);
    ft_free(args);
    exit(127);
}

static void setup_io_first(int fd[2], int file1)
{
    int devnull;

    close(fd[0]);
    if (file1 >= 0)
    {
        if (dup2(file1, STDIN_FILENO) < 0)
        {
            perror("dup2");
            close(fd[1]);
            exit(1);
        }
        close(file1);
    }
    else
    {
        devnull = open("/dev/null", O_RDONLY);
        if (devnull >= 0)
        {
            dup2(devnull, STDIN_FILENO);
            close(devnull);
        }
    }
    if (dup2(fd[1], STDOUT_FILENO) < 0)
    {
        perror("dup2");
        close(fd[1]);
        exit(1);
    }
    close(fd[1]);
}

static void setup_io_second(int fd[2], int file2)
{
    close(fd[1]);
    if (dup2(fd[0], STDIN_FILENO) < 0)
    {
        perror("dup2");
        exit(1);
    }
    if (dup2(file2, STDOUT_FILENO) < 0)
    {
        perror("dup2");
        exit(1);
    }
    close(fd[0]);
    close(file2);
}

void execute_command(char *cmd, char **env)
{
    char **args;

    if (!cmd || cmd[0] == '\0')
        exit(0);
    args = ft_split(cmd, ' ');
    if (!args)
        exit(1);
    if (args[0] && args[0][0] == '/')
    {
        execve(args[0], args, env);
        perror("execve");
        ft_free(args);
        exit(127);
    }
    ft_run(args, args[0], env);
    ft_free(args);
    exit(127);
}

void ft_first_child(int fd[2], int file1, char *cmd, char **env)
{
    setup_io_first(fd, file1);
    execute_command(cmd, env);
}

void ft_second_child(int fd[2], int file2, char *cmd, char **env)
{
    setup_io_second(fd, file2);
    execute_command(cmd, env);
}
