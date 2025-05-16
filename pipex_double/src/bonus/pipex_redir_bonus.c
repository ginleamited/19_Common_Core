/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redir_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:46:31 by jilin             #+#    #+#             */
/*   Updated: 2025/05/16 19:30:57 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    redirect_io(int in, int out)
{
    if (dup2(in, STDIN_FILENO) < 0)
    {
        ft_error(ERR_DUP2, 1);
        exit(1);
    }
    if (dup2(out, STDOUT_FILENO) < 0)
    {
        ft_error(ERR_DUP2, 1);
    }
    close(in);
    close(out);
}