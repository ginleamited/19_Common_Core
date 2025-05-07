/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:31:51 by jilin             #+#    #+#             */
/*   Updated: 2025/04/30 18:16:20 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../../inc/libft.h"

typedef struct s_command {
    char *cmd;              // Command name (e.g., "ls")
    char **args;            // Argument array (e.g., {"ls", "-l", NULL})
    char *input_file;       // Input redirection (e.g., "in.txt")
    char *output_file;      // Output redirection (e.g., "out.txt")
    int append;             // 1 if >>, 0 if >
    int is_heredoc;         // 1 if <<, 0 otherwise
    struct s_command *next; // Next command (for pipes)
} t_command;

#endif
