/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:11:01 by jilin             #+#    #+#             */
/*   Updated: 2025/05/16 19:31:34 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *find_cmd_path(char **path, char *cmd)
{
    char    *tmp;
    char    *cmd_path;
    int     i;

    i = 0;
    while (path[i])
    {
        tmp = ft_strjoin(path[i], "/");
        cmd_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(cmd_path, X_OK) == 0)
            return (cmd_path);
        free(cmd_path);
        i++;
    }
    return (NULL);
}

void    ft_run_cmd(char **args, char *cmd, char **env)
{
    char    **path;
    char    *cmd_path;

    (void)cmd;
    path = ft_find_path(env);
    if (!path) {
        perror("pipex: PATH not found");
        exit(127);
    }
    cmd_path = find_cmd_path(path, args[0]);
    ft_free_split(path);
    if (!cmd_path) {
        perror("pipex: command not found");
        exit(127);
    }
    execve(cmd_path, args, env);
    perror("pipex: execve");
    free(cmd_path);
    exit(127);
}

void    execute_cmd(char *cmd, char **env)
{
    char    **args;

    if (!cmd || !*cmd)
        exit(1);
    args = ft_split(cmd, ' ');
    if (!args)
        exit(1);
    if (ft_strchr(args[0], '/'))
        execve(args[0], args, env);
    ft_run_cmd(args, cmd, env);
}