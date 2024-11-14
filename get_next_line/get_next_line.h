/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:17 by jilin             #+#    #+#             */
/*   Updated: 2024/11/13 20:16:46 by jilin            ###   ########.fr       */
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
	char			*str_buff;//point to the buffer holding char read from file
	struct s_list	*next;//point to the next node of the list
}	t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);
char	*get_line(t_list *list);
void	polish_list(t_list **list);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
void	dealloc(t_list **list, t_list *clean_node, char *buf);

#endif