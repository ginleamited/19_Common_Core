/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:29:49 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 01:38:10 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/inc/libft.h"

typedef struct s_process
{
    int		fd[2];
    int		file;
    char	*cmd;
    char	**env;
}	t_process;

/* pipex_child.c */
void	ft_first_child(int fd[2], int file1, char *cmd1, char **env);
void	ft_second_child(int fd[2], int file2, char *cmd2, char **env);

/* pipex_process.c */
void	execute_command(char *cmd, char **env);
void	setup_first_io(int fd[2], int file1);
void	setup_second_io(int fd[2], int file2);

/* pipex_utils.c */
char	**ft_find_path(char **env);
void	ft_free(char **str);
void	ft_error(char *message, int exitcode);

/* pipex_cmd.c */
void	ft_run(char **args, char *cmd, char **env);

#endif