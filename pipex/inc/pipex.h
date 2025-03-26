/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:29:49 by jilin             #+#    #+#             */
/*   Updated: 2025/03/26 16:17:15 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "../lib/inc/libft.h"

typedef struct s_files
{
	int *fd_in;
	int *fd_out;
	int *pipefd;
	char **argv;
}	t_files;

char	*get_env(char *name, char **envp);
char	**parse_cmd(char *cmd_str);
char	*find_path(char *cmd, char **envp);


#endif