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
    char **argv;                // arguments of the command
    char *infile;               // input file (for <)
    char *outfile;              // output file (for > or >>)
    int   append;               // 1 if >>, 0 if >
    struct s_command *next;     // next command in pipeline
} t_command;



#endif