/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:24:29 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:20:50 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

static void	setup_files(int *file1, int *file2, char **argv)
{
    *file1 = open(argv[1], O_RDONLY);
    if (*file1 < 0)
        perror(argv[1]);
    *file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*file2 < 0)
        perror(argv[4]);
}

static void	create_processes(int fd[2], int file1, int file2, 
                            char **argv, char **env, pid_t id[2])
{
    id[0] = fork();
    if (id[0] < 0)
        ft_error("fork failed\n", 1);
    if (id[0] == 0)
        ft_first_child(fd, file1, argv[2], env);
    id[1] = fork();
    if (id[1] < 0)
        ft_error("fork failed\n", 1);
    if (id[1] == 0)
        ft_second_child(fd, file2, argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
    int		file1;
    int		file2;
    int		fd[2];
    pid_t	id[2];
    int		status1;
    int		status2;

    if (argc != 5)
        ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
    setup_files(&file1, &file2, argv);
    if (pipe(fd) < 0)
        ft_error("Setup failed\n", 1);
    create_processes(fd, file1, file2, argv, env, id);
    close_pipes(fd);
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
