#include "pipex_bonus.h"
#include <sys/wait.h>

static void	handle_io(int infile, int outfile)
{
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
}

static void	pipe_loop(int *prev_pipe, int *curr_pipe, char *cmd, char **env)
{
	pid_t	pid;

	if (pipe(curr_pipe) == -1)
		ft_error("pipe failed\n", 1);
	pid = fork();
	if (pid == -1)
		ft_error("fork failed\n", 1);
	if (pid == 0)
	{
		close(curr_pipe[READ_END]);
		if (prev_pipe[READ_END] != -1)
		{
			dup2(prev_pipe[READ_END], STDIN_FILENO);
			close(prev_pipe[READ_END]);
		}
		dup2(curr_pipe[WRITE_END], STDOUT_FILENO);
		close(curr_pipe[WRITE_END]);
		execute_command(cmd, env);
	}
	else
	{
		if (prev_pipe[READ_END] != -1)
			close(prev_pipe[READ_END]);
		prev_pipe[READ_END] = curr_pipe[READ_END];
		close(curr_pipe[WRITE_END]);
	}
}

void	handle_multiple_pipes(int argc, char **argv, char **env)
{
	int		prev_pipe[2];
	int		curr_pipe[2];
	int		i;
	int		fd_in;
	int		fd_out;

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	prev_pipe[READ_END] = -1;
	i = 2;
	while (i < argc - 2)
	{
		pipe_loop(prev_pipe, curr_pipe, argv[i], env);
		i++;
	}
	handle_io(fd_in, fd_out);
	execute_command(argv[argc - 2], env);
	close(fd_in);
	close(fd_out);
}

void	here_doc(char *limiter, int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	char	*line;
	int		outfile;

	if (pipe(fd) == -1)
		ft_error("pipe failed\n", 1);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		while (1)
		{
			line = get_next_line(0);
			if (!line || ft_strcmp(line, limiter) == 0)
				break ;
			write(fd[WRITE_END], line, ft_strlen(line));
			free(line);
		}
		if (line)
			free(line);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		waitpid(pid, NULL, 0);
	}
	outfile = open_file_bonus(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	handle_multiple_pipes(argc, argv, env);
	close(outfile);
}

int	open_file_bonus(char *file, int flags, mode_t mode)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}