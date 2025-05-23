#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

# define ERR_HEREDOC "here_doc error"

typedef struct s_pipex_bonus
{
    int     fd_in;
    int     fd_out;
    int     here_doc;
    char    *limiter;
    pid_t   *pids;
    int     cmd_count;
    int     pipefd[2];
    int     prev_pipe;
    char    **env;
}   t_pipex_bonus;

/* Bonus Functions */
void    handle_heredoc(char *limiter, t_pipex_bonus *px);
void    create_process(t_pipex_bonus *px, char *cmd, char **env);
void    execute_last_cmd(t_pipex_bonus *px, char *cmd, char *outfile, char **env);
void    close_pipes(t_pipex_bonus *px);
void    wait_for_children(t_pipex_bonus *px);

#endif