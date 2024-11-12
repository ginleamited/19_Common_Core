/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:23 by jilin             #+#    #+#             */
/*   Updated: 2024/11/13 00:10:34 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	
	create_list(&list, fd);

	if (list == NULL)
		return (NULL);
		
	next_line = get_line(list);

	polish_list(&list);
	return (next_line);
}

//* EXPLANATION
// declare a static function
// secure the code, fd always > 0, only work if bufsize has something,
// read(fd, &, 0) is for checking if we can open, else read will return -1

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;

		char_read = read(fd, buf, BUFFER_SIZE);
		
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read = '\0']
		
		append(list, buf);
	}
}
//* EXPLANATION
// if (!char_read) : if char_read = 0, free buf and = '\0'

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->str_buf = buf;
		new_node->next = NULL;
}
//* EXPLANATION
// if last_node is NULL then replace *list with new_nodes
// 

char	*get_line(t_list *list)
{
	
}