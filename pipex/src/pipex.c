/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:24:29 by jilin             #+#    #+#             */
/*   Updated: 2025/03/27 20:38:53 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		file1;
	int		file2;
	int		fd[2];
	pid_t	id1;
	pid_t	id2;

	if (argc != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file1 < 0 || file2 < 0 || pipe(fd) < 0)
		ft_error("Setup failed\n", 1);
	id1 = fork();
	if (id1 == 0)
		ft_first_child(fd, file1, argv[2], env);
	id2 = fork();
	if (id2 == 0)
		ft_second_child(fd, file2, argv[3], env);
	close(fd[0]);
	close(fd[1]);
	close(file1);
	close(file2);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
