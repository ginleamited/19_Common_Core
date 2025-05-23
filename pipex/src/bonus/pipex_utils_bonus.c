#include "pipex_bonus.h"

void	exec_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("pipe failed\n", 1);
	pid = fork();
	if (pid == -1)
		ft_error("fork failed\n", 1);
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		execute_command(cmd, env);
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
	}
}