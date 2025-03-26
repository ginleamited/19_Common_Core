/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:42:36 by jilin             #+#    #+#             */
/*   Updated: 2025/03/26 16:42:07 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	count_tokens(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

char	*get_env(char *name, char **envp)
{
	int	len;

	len = ft_strlen(name);
	while (*envp)
	{
		if (ft_strncmp(name, *envp, len) == 0 && (*envp)[len] == '=')
			return (*envp + len + 1);
		envp++;
	}
	return (NULL);
}


char	**parse_cmd(char *cmd_str)
{
	char	**args;
	char	**tokens;
	int		i;

	tokens = ft_split(cmd_str, ' ');
	if (!tokens)
		return (NULL);
	args = malloc(sizeof(char *) * (count_tokens(tokens) + 1));
	if (!args)
		return (ft_free_array(tokens), NULL);
	i = 0;
	while (tokens[i])
	{
		args[i] = ft_strdup(tokens[i]);
		i++;
	}
	args[i] = NULL;
	ft_free_array(tokens);
	return (args);
}

static char	*try_path(char *dir, char *cmd)
{
	char	*full_path;

	if (!cmd || !*cmd)
	{
		ft_putstr_fd("Error: Command is empty or NULL\n", 2);
		return (NULL);
	}
	full_path = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
	if (!full_path)
		return (NULL);
	ft_snprintf(full_path, ft_strlen(dir) + ft_strlen(cmd) + 2, "%s/%s", dir, cmd);
	ft_putstr_fd("Checking path: ", 2);
	ft_putstr_fd(full_path, 2);
	ft_putstr_fd("\n", 2);
	if (access(full_path, F_OK) == 0 && access(full_path, X_OK) == 0) // Check existence and executability
		return (full_path);
	free(full_path);
	return (NULL);
}

static char	*check_absolute(char *cmd)
{
	if (cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**dirs;
	char	*full_path;
	int		i;

	full_path = check_absolute(cmd);
	if (full_path)
		return (full_path);
	if (!cmd || !*cmd)
	{
		ft_putstr_fd("Error: Command is empty or NULL in find_path\n", 2);
		return (NULL);
	}
	path = get_env("PATH", envp);
	if (!path)
	{
		ft_putstr_fd("Error: PATH not found in envp\n", 2);
		return (NULL);
	}
	dirs = ft_split(path, ':');
	if (!dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		ft_putstr_fd("Trying directory: ", 2);
		ft_putstr_fd(dirs[i], 2);
		ft_putstr_fd(" with command: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\n", 2);
		full_path = try_path(dirs[i], cmd);
		if (full_path)
			return (ft_free_array(dirs), full_path);
		i++;
	}
	ft_free_array(dirs);
	return (NULL);
}

static void	setup_files_and_pipe(t_files *files)
{
	*files->fd_in = open(files->argv[1], O_RDONLY);
	if (*files->fd_in < 0)
		perror("open file1"), exit(1);
	*files->fd_out = open(files->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*files->fd_out < 0)
		perror("open file2"), close(*files->fd_in), exit(1);
	if (pipe(files->pipefd) < 0)
		perror("pipe"), close(*files->fd_in), close(*files->fd_out), exit(1);
}

static void	setup_child1(int fd_in, int *pipefd, int fd_out)
{
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	close(fd_out);
}

static void	exec_cmd(char *cmd_str, char **envp, int exit_code)
{
	char	**args;
	char	*path;

	args = parse_cmd(cmd_str);
	if (!args)
	{
		ft_putstr_fd("Failed to parse command\n", 2);
		exit(exit_code);
	}
	path = find_path(args[0], envp);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_array(args);
		exit(exit_code);
	}
	// Debugging output
	ft_putstr_fd("Trying to execute: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("\n", 2);
	if (access(path, X_OK) != 0)
	{
		ft_putstr_fd("Permission denied or not executable: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		free(path);
		ft_free_array(args);
		exit(exit_code);
	}
	execve(path, args, envp);
	perror("execve"); // This prints the specific error
	free(path);
	ft_free_array(args);
	exit(exit_code);
}

static void	handle_child1(int fd_in, int *pipefd, int fd_out, char **argv, char **envp)
{
	setup_child1(fd_in, pipefd, fd_out);
	exec_cmd(argv[2], envp, 1);
}

static void	setup_child2(int *pipefd, int fd_out, int fd_in)
{
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(fd_in);
}

static void	handle_child2(int *pipefd, int fd_out, int fd_in, char **argv, char **envp)
{
	setup_child2(pipefd, fd_out, fd_in);
	exec_cmd(argv[3], envp, 1);
}

static void	run_processes(t_files *files, char **envp, pid_t *pid1, pid_t *pid2)
{
	*pid1 = fork();
	if (*pid1 < 0)
		perror("fork"), close(*files->fd_in), close(*files->fd_out),
		close(files->pipefd[0]), close(files->pipefd[1]), exit(1);
	if (*pid1 == 0)
		handle_child1(*files->fd_in, files->pipefd, *files->fd_out, files->argv, envp);
	close(files->pipefd[1]);
	*pid2 = fork();
	if (*pid2 < 0)
		perror("fork"), close(*files->fd_in), close(*files->fd_out),
		close(files->pipefd[0]), waitpid(*pid1, NULL, 0), exit(1);
	if (*pid2 == 0)
		handle_child2(files->pipefd, *files->fd_out, *files->fd_in, files->argv, envp);
}

static void	check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" file1 cmd1 cmd2 file2\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_files	files;
	int		fd_in;
	int		fd_out;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	check_args(argc, argv);
	files.fd_in = &fd_in;
	files.fd_out = &fd_out;
	files.pipefd = pipefd;
	files.argv = argv;
	setup_files_and_pipe(&files);
	run_processes(&files, envp, &pid1, &pid2);
	close(files.pipefd[0]);
	close(*files.fd_in);
	close(*files.fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
