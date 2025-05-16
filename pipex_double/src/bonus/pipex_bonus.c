/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:10 by jilin             #+#    #+#             */
/*   Updated: 2025/05/16 19:39:13 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void init_pipex(t_pipex_bonus *px, int ac, char **av, char **env)
{
    px->here_doc = !ft_strcmp(av[1], "here_doc");
    if (px->here_doc)
    {
        px->limiter = av[2];
        handle_heredoc(px->limiter, px);
    }
    else
        px->fd_in = open(av[1], O_RDONLY);
    px->env = env;
    px->cmd_count = ac - 3 - px->here_doc;
    px->pids = malloc(sizeof(pid_t) * px->cmd_count);
    px->prev_pipe = -1;
}

int main(int ac, char **av, char **env)
{
    t_pipex_bonus px;
    int     i;

    if (ac < 5)
        ft_error("Usage: ./pipex <infile> <cmd1> <cmd2> ... <cmdn> <outfile>\n", 1);
    
    init_pipex(&px, ac, av, env);
    
    i = 2 + px.here_doc;
    while (i < ac - 2)
    {
        if (pipe(px.pipefd) < 0)
            ft_error("Pipe error", 1);
        create_process(&px, av[i++], env);
    }
    execute_last_cmd(&px, av[ac - 2], av[ac - 1], env);
    close_pipes(&px);
    wait_for_children(&px);
    return (0);
}
