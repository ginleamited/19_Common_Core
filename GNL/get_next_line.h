/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:17 by jilin             #+#    #+#             */
/*   Updated: 2024/11/20 12:49:51 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str_buf;//point to the buffer holding char read from file
	struct s_list	*next;//point to the next node of the list
}	t_list;

typedef struct l_stax
{
	t_list	*top;
}	t_stack;

void	sort(l_stack *top)
{
	t_list	current_top = top->next;

	current_top node 1
}
// str_buf: pointer to a dynamically allocated string (buffer)
// containing a chunk of text read from the file.
// ext: This is a pointer to the next node in the list, 
// allowing each node to be linked to the next.

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);
char	*get_line(t_list *list);
void	polish_list(t_list **list);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
void	dealloc(t_list **list, t_list *clean_node, char *buf);

#endif