/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:36:15 by jilin             #+#    #+#             */
/*   Updated: 2025/05/16 19:31:56 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(t_pipex *px, char **av)
{
	if (pipe(px->pipefd) < 0)
		ft_error(ERR_PIPE, 1);
	
	px->pid1 = fork();
	if (px->pid1 < 0)
		ft_error("fork failed", 1);
	if (px->pid1 == 0)
	{
		close(px->pipefd[0]);
		redirect_io(px->fd_in, px->pipefd[1]);
		execute_cmd(av[2], px->env);
	}
	px->pid2 = fork();
	if (px->pid2 < 0)
		ft_error("fork failed", 1);
	if (px->pid2 == 0)
	{
		close(px->pipefd[1]);
		redirect_io(px->pipefd[0], px->fd_out);
		execute_cmd(av[3], px->env);
	}
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	waitpid(px->pid1, NULL, 0);
	waitpid(px->pid2, NULL, 0);
}

int main(int ac, char **av, char **env)
{
    t_pipex px;

    if (ac != 5) {
        write(STDERR_FILENO, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 39);
        exit(1);
    }
    
    px.fd_in = open(av[1], O_RDONLY);
    if (px.fd_in < 0) {
        perror("pipex: input file");
        exit(1);
    }
    
    px.fd_out = open(av[4], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (px.fd_out < 0) {
        perror("pipex: output file");
        close(px.fd_in);
        exit(1);
    }
    
    px.env = env;
    pipex(&px, av);
    return (0);
}
