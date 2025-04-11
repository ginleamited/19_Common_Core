/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:37:11 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:43:43 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	setup_stdin(int file1, int fd[2])
{
    int	devnull;

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
}

void	setup_io_first(int fd[2], int file1)
{
    close(fd[0]);
    setup_stdin(file1, fd);
    if (dup2(fd[1], STDOUT_FILENO) < 0)
    {
        perror("dup2");
        close(fd[1]);
        exit(1);
    }
    close(fd[1]);
}

void	setup_io_second(int fd[2], int file2)
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

void	execute_command(char *cmd, char **env)
{
    char	**args;

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