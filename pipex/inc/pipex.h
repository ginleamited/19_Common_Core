/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:29:49 by jilin             #+#    #+#             */
/*   Updated: 2025/05/23 20:44:28 by jilin            ###   ########.fr       */
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

/* pipex_cmd.c */
void	execute_command(char *cmd, char **env);
void	ft_run(char **args, char *cmd, char **env);

/* pipex_io.c */
void	setup_first_io(int fd[2], int file1);
void	setup_second_io(int fd[2], int file2);

/* pipex_utils.c */
char	**ft_find_path(char **env);
void	ft_free(char **str);
void	ft_error(char *message, int exitcode);

#endif