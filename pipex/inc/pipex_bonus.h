#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

# define READ_END 0
# define WRITE_END 1
# define HDOC_WRITE 1
# define HDOC_READ 0

// Function prototypes
void	handle_multiple_pipes(int argc, char **argv, char **env);
void	here_doc(char *limiter, int argc, char **argv, char **env);
int		open_file_bonus(char *file, int flags, mode_t mode);
void	exec_pipe(char *cmd, char **env);

#endif