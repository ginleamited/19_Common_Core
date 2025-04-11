/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:38:43 by jilin             #+#    #+#             */
/*   Updated: 2025/04/11 22:35:21 by jilin            ###   ########.fr       */
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

void	ft_first_child(int fd[2], int file1, char *cmd1, char **env)
{
	char	**args;
	int		status;

	close(fd[0]);
	args = ft_split(cmd1, ' ');
	if (dup2(file1, 0) == -1 || dup2(fd[1], 1) == -1)
	{
		perror("cmd1");
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
		return ;
	}
	close(file1);
	close(fd[1]);
	if (args[0][0] == '/')
	{
		execve(args[0], args, env);
		ft_putstr_fd("Failed to execute: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free(args);
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
	}
	ft_run(args, args[0], env);
}

void	ft_second_child(int fd[2], int file2, char *cmd2, char **env)
{
	char	**args;
	int		status;

	close(fd[1]);
	args = ft_split(cmd2, ' ');
	if (dup2(fd[0], 0) == -1 || dup2(file2, 1) == -1)
	{
		perror("cmd2");
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
		return ;
	}
	close(fd[0]);
	close(file2);
	if (args[0][0] == '/')
	{
		execve(args[0], args, env);
		ft_putstr_fd("Failed to execute: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free(args);
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
	}
	ft_run(args, args[0], env);
}
