/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:17 by jilin             #+#    #+#             */
/*   Updated: 2024/11/12 23:30:02 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_H
# define get_next_line_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}	t_list;

#endif