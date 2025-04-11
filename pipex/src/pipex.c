/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:36:15 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 01:30:37 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_first_process(t_process p, pid_t *id)
{
	*id = fork();
	if (*id < 0)
		ft_error("fork failed\n", 1);
	if (*id == 0)
	{
		setup_first_io(p.fd, p.file);
		execute_command(p.cmd, p.env);
	}
}

static void	create_second_process(t_process p, pid_t *id)
{
	*id = fork();
	if (*id < 0)
		ft_error("fork failed\n", 1);
	if (*id == 0)
	{
		setup_second_io(p.fd, p.file);
		execute_command(p.cmd, p.env);
	}
}

static int	cleanup_and_wait(int fd[2], int file1, int file2, pid_t id[2])
{
	int	status1;
	int	status2;

	close(fd[0]);
	close(fd[1]);
	if (file1 >= 0)
		close(file1);
	if (file2 >= 0)
		close(file2);
	waitpid(id[0], &status1, 0);
	waitpid(id[1], &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	int			files[2];
	int			fd[2];
	pid_t		id[2];
	int			exit_code;
	t_process	p;

	if (argc != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	files[0] = open(argv[1], O_RDONLY);
	if (files[0] < 0)
		perror(argv[1]);
	files[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (files[1] < 0)
		perror(argv[4]);
	if (pipe(fd) < 0)
		ft_error("Setup failed\n", 1);
	p = (t_process){.fd = {fd[0], fd[1]}, .file = files[0],
		.cmd = argv[2], .env = env};
	create_first_process(p, &id[0]);
	p.file = files[1];
	p.cmd = argv[3];
	create_second_process(p, &id[1]);
	exit_code = cleanup_and_wait(fd, files[0], files[1], id);
	return (exit_code);
}
