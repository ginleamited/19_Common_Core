/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:24:29 by jilin             #+#    #+#             */
/*   Updated: 2025/04/11 22:39:23 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	int		file1;
	int		file2;
	int		fd[2];
	pid_t	id[2];
	int		status;

	if (argc != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	file1 = open(argv[1], O_RDONLY);
	if (pipe(fd) < 0)
		ft_error("Setup failed\n", 1);
	id[0] = fork();
	if (id[0] == 0)
		ft_first_child(fd, file1, argv[2], env);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
		perror("file2");
	id[1] = fork();
	if (id[1] == 0)
		ft_second_child(fd, file2, argv[3], env);
	close_pipes(fd);
	waitpid(id[0], &status, 0);
	waitpid(id[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
