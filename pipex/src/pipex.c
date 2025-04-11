/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:36:15 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 01:00:23 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_first_process(int fd[2], int file1, 
                                char *cmd, char **env, pid_t *id)
{
    *id = fork();
    if (*id < 0)
        ft_error("fork failed\n", 1);
    if (*id == 0)
        ft_first_child(fd, file1, cmd, env);
}

static void	create_second_process(int fd[2], int file2,
                                char *cmd, char **env, pid_t *id)
{
    *id = fork();
    if (*id < 0)
        ft_error("fork failed\n", 1);
    if (*id == 0)
        ft_second_child(fd, file2, cmd, env);
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
    int		file1;
    int		file2;
    int		fd[2];
    pid_t	id[2];
    int		exit_code;

    if (argc != 5)
        ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
    file1 = open(argv[1], O_RDONLY);
    if (file1 < 0)
        perror(argv[1]);
    file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file2 < 0)
        perror(argv[4]);
    if (pipe(fd) < 0)
        ft_error("Setup failed\n", 1);
    create_first_process(fd, file1, argv[2], env, &id[0]);
    create_second_process(fd, file2, argv[3], env, &id[1]);
    exit_code = cleanup_and_wait(fd, file1, file2, id);
    return (exit_code);
}
