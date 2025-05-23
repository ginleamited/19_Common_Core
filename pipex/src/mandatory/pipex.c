#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		files[2];
	int		fd[2];
	pid_t	id[2];
	int		exit_code;

	if (argc != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	files[0] = open(argv[1], O_RDONLY);
	if (files[0] < 0)
		perror(argv[1]);
	files[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (files[1] < 0)
		perror(argv[4]);
	if (pipe(fd) < 0)
		ft_error("Setup failed\n", 1);

	// First process
	id[0] = fork();
	if (id[0] < 0)
		ft_error("fork failed\n", 1);
	if (id[0] == 0) {
		close(fd[0]);
		dup2(files[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_command(argv[2], env);
	}

	// Second process
	id[1] = fork();
	if (id[1] < 0)
		ft_error("fork failed\n", 1);
	if (id[1] == 0) {
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(files[1], STDOUT_FILENO);
		close(fd[0]);
		execute_command(argv[3], env);
	}

	// Cleanup
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], &exit_code, 0);
	return (WIFEXITED(exit_code) ? WEXITSTATUS(exit_code) : 1);
}