/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:24:29 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:05:05 by jilin            ###   ########.fr       */
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

    if (argc != 5)
        ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
    
    // Open input file but don't exit on failure
    file1 = open(argv[1], O_RDONLY);
    // Only print error message, but continue execution
    if (file1 < 0)
        perror(argv[1]);
    
    if (pipe(fd) < 0)
        ft_error("Setup failed\n", 1);
    id[0] = fork();
    if (id[0] < 0)
        ft_error("fork failed\n", 1);
    if (id[0] == 0)
        ft_first_child(fd, file1, argv[2], env);
    
    file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file2 < 0)
    {
        perror(argv[4]);
        exit(1);
    }
    id[1] = fork();
    if (id[1] < 0)
        ft_error("fork failed\n", 1);
    if (id[1] == 0)
        ft_second_child(fd, file2, argv[3], env);
    
    close_pipes(fd);
    // Close input file if it was opened successfully
    if (file1 >= 0)
        close(file1);
    close(file2);
    
    int status1, status2;
    waitpid(id[0], &status1, 0);
    waitpid(id[1], &status2, 0);
    
    // The exit status should come from the last command in the pipeline
    if (WIFEXITED(status2))
        return (WEXITSTATUS(status2));
    return (1);
}
