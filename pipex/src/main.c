/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:42:36 by jilin             #+#    #+#             */
/*   Updated: 2025/03/26 14:15:00 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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

char **parse_cmd(char *cmd_str)
{
    char **args;
    char **tokens;	
    int i;

	i = 0;
    tokens = ft_split(cmd_str, ' ');
    if (!tokens)
        return (NULL);
    while (tokens[i])
        i++;
    args = malloc(sizeof(char *) * (i + 1));
    if (!args)
    {
        ft_free_array(tokens);
        return (NULL);
    }
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

static char *try_path(char *dir, char *cmd) // Helper
{
    char *full_path = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
    if (!full_path)
        return (NULL);
    ft_snprintf(full_path, ft_strlen(dir) + ft_strlen(cmd) + 2, "%s/%s", dir, cmd);
    if (access(full_path, X_OK) == 0)
        return (full_path);
    free(full_path);
    return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**dirs;
	char	*full_path;
	int		i;

	i = 0;
	path = get_env("PATH", envp);
	if (cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!path)
		return (NULL);
	dirs = ft_split(path, ':');
	if (!dirs)
		return (NULL);
	while (dirs[i])
	{
		full_path = try_path(dirs[i], cmd);
		if (full_path)
		{
			ft_free_array(dirs);
			return (full_path);
		}
		i++;
	}
	ft_free_array(dirs);
	return (NULL);
}

static void setup_files_and_pipe(int *fd_in, int *fd_out, int *pipefd, char **argv)
{
  *fd_in = open(argv[1], O_RDONLY);
  if (*fd_in < 0)
      perror("open file1"), exit(1);
  *fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (*fd_out < 0)
      perror("open file2"), close(*fd_in), exit(1);
  if (pipe(pipefd) < 0)
      perror("pipe"), close(*fd_in), close(*fd_out), exit(1);
}

static void handle_child1(int fd_in, int *pipefd, int fd_out, char **argv, char **envp)
{
  char **args1 = parse_cmd(argv[2]);
  char *path1 = find_path(args1[0], envp);
  dup2(fd_in, STDIN_FILENO);
  close(fd_in);
  dup2(pipefd[1], STDOUT_FILENO);
  close(pipefd[1]);
  close(pipefd[0]);
  close(fd_out);
  if (!path1)
      ft_putstr_fd("Command not found: ", 2), ft_putstr_fd(args1[0], 2), ft_putstr_fd("\n", 2), exit(1);
  execve(path1, args1, envp);
  perror("execve cmd1");
  exit(1);
}

static void handle_child2(int *pipefd, int fd_out, int fd_in, char **argv, char **envp)
{
  char **args2 = parse_cmd(argv[3]);
  char *path2 = find_path(args2[0], envp);
  dup2(pipefd[0], STDIN_FILENO);
  close(pipefd[0]);
  dup2(fd_out, STDOUT_FILENO);
  close(fd_out);
  close(fd_in);
  if (!path2)
      ft_putstr_fd("Command not found: ", 2), ft_putstr_fd(args2[0], 2), ft_putstr_fd("\n", 2), exit(1);
  execve(path2, args2, envp);
  perror("execve cmd2");
  exit(1);
}

int main(int argc, char **argv, char **envp)
{
  int fd_in, fd_out, pipefd[2];
  pid_t pid1, pid2;
  if (argc != 5)
      ft_putstr_fd("Usage: ", 2), ft_putstr_fd(argv[0], 2), ft_putstr_fd(" file1 cmd1 cmd2 file2\n", 2), exit(1);
  setup_files_and_pipe(&fd_in, &fd_out, pipefd, argv);
  pid1 = fork();
  if (pid1 < 0)
      perror("fork"), close(fd_in), close(fd_out), close(pipefd[0]), close(pipefd[1]), exit(1);
  if (pid1 == 0)
      handle_child1(fd_in, pipefd, fd_out, argv, envp);
  close(pipefd[1]);
  pid2 = fork();
  if (pid2 < 0)
      perror("fork"), close(fd_in), close(fd_out), close(pipefd[0]), waitpid(pid1, NULL, 0), exit(1);
  if (pid2 == 0)
      handle_child2(pipefd, fd_out, fd_in, argv, envp);
  close(pipefd[0]);
  close(fd_in);
  close(fd_out);
  waitpid(pid1, NULL, 0);
  waitpid(pid2, NULL, 0);
  return (0);
}