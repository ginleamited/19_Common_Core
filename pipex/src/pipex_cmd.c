/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:38:15 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:38:23 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_executable(char **path, char *cmd)
{
    char	*temp;
    char	*cmd_path;
    int		i;

    i = 0;
    while (path[i])
    {
        temp = ft_strjoin(path[i], "/");
        if (!temp)
            return (NULL);
        cmd_path = ft_strjoin(temp, cmd);
        free(temp);
        if (!cmd_path)
            return (NULL);
        if (access(cmd_path, X_OK) == 0)
            return (cmd_path);
        free(cmd_path);
        i++;
    }
    return (NULL);
}

static void	handle_cmd_not_found(char *cmd, char **args)
{
    ft_putstr_fd("Failed to execute: ", 2);
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd("\n", 2);
    ft_free(args);
    exit(127);
}

void	ft_run(char **args, char *cmd, char **env)
{
    char	**path;
    char	*cmd_path;

    if (!cmd || !args || !args[0])
    {
        ft_free(args);
        exit(127);
    }
    path = ft_find_path(env);
    if (!path)
    {
        ft_putstr_fd("PATH not found\n", 2);
        ft_free(args);
        exit(127);
    }
    cmd_path = find_executable(path, cmd);
    ft_free(path);
    if (cmd_path)
    {
        execve(cmd_path, args, env);
        free(cmd_path);
    }
    handle_cmd_not_found(cmd, args);
}
