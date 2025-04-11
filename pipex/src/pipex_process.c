/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:38:43 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:07:58 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_run(char **args, char *cmd, char **env)
{
	char	**path;
	char	*temp;
	char	*newcmd;
	int		i;

	path = ft_find_path(env);
	if (!path)
		ft_error("PATH not found\n", 127);
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		newcmd = ft_strjoin(temp, cmd);
		free(temp);
		execve(newcmd, args, env);
		free(newcmd);
		i++;
	}
	ft_free(path);
	ft_putstr_fd("Failed to execute: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

void ft_first_child(int fd[2], int file1, char *cmd, char **env)
{
    char **args;
    
    // Close read end of pipe
    close(fd[0]);
    
    // If file1 is valid, redirect stdin to file1
    if (file1 >= 0)
    {
        if (dup2(file1, STDIN_FILENO) < 0)
            exit(1);
        close(file1);
    }
    // If file1 is invalid, stdin remains /dev/null
    
    // Redirect stdout to pipe write end
    if (dup2(fd[1], STDOUT_FILENO) < 0)
        exit(1);
    close(fd[1]);
    
    // Execute command (if empty, exit with status 0)
    if (!cmd || cmd[0] == '\0')
        exit(0);
    
    // Use your existing command execution logic
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
    
    // This line will only be reached if ft_run fails
    ft_free(args);
    exit(127);
}

void ft_second_child(int fd[2], int file2, char *cmd2, char **env)
{
    char **args;

    close(fd[1]);
    
    // Execute command (if empty, exit with status 0)
    if (!cmd2 || cmd2[0] == '\0')
        exit(0);
    
    if (dup2(fd[0], 0) == -1 || dup2(file2, 1) == -1)
    {
        perror("dup2");
        exit(1);
    }
    close(fd[0]);
    close(file2);
    
    args = ft_split(cmd2, ' ');
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
    
    // This line will only be reached if ft_run fails
    ft_free(args);
    exit(127);
}
