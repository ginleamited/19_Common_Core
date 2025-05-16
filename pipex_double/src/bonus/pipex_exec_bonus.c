/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:46:03 by jilin             #+#    #+#             */
/*   Updated: 2025/05/16 18:47:50 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    exec_bonus_cmd(char *cmd, char **env)
{
    char    **args;

    args = ft_split(cmd, ' ');
    if (!args)
        exit(1);
    if (ft_strchr(args[0], '/'))
        execve(args[0], args, env);
    ft_run_cmd(args, cmd, env);
}
