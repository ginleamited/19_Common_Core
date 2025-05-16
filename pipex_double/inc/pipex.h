#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include "../lib/inc/libft.h"

/* Error Messages */
# define ERR_CMD "command not found"
# define ERR_INFILE "no such file or directory"
# define ERR_OUTFILE "output file error"
# define ERR_PIPE "pipe failed"
# define ERR_FORK "fork failed"
# define ERR_DUP2 "dup2 failed"
# define ERR_EXECVE "execve failed"

/* Struct Definition */
typedef struct s_pipex
{
    int     fd_in;
    int     fd_out;
    pid_t   pid1;
    pid_t   pid2;
    int     pipefd[2];
    char    **env;
}   t_pipex;

/* Core Functions */
void    pipex(t_pipex *px, char **av);
void    execute_cmd(char *cmd, char **env);
void    redirect_io(int in, int out);
void	ft_run_cmd(char **args, char *cmd, char **env);

/* Utility Functions */
char    **ft_find_path(char **env);
void    ft_free_split(char **arr);
void    ft_error(char *msg, int exit_code);

#endif