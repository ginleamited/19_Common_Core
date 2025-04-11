/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:37:29 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:37:31 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_child(int fd[2], int file1, char *cmd, char **env)
{
    setup_io_first(fd, file1);
    execute_command(cmd, env);
}

void	ft_second_child(int fd[2], int file2, char *cmd, char **env)
{
    setup_io_second(fd, file2);
    execute_command(cmd, env);
}