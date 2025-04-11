/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:29:49 by jilin             #+#    #+#             */
/*   Updated: 2025/04/11 18:41:35 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/inc/libft.h"

void	ft_run(char **args, char *cmd, char **env);
void	ft_first_child(int fd[2], int file1, char *cmd1, char **env);
void	ft_second_child(int fd[2], int file2, char *cmd2, char **env);
char	**ft_find_path(char **env);
void	ft_free(char **str);
void	ft_error(char *message, int exitcode);

#endif