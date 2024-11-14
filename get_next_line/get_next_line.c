/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:23 by jilin             #+#    #+#             */
/*   Updated: 2024/11/13 20:37:23 by jilin            ###   ########.fr       */
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
//! Read the next line from a fd
// declare a static linked list which retains content
// secure the code, fd always > 0, only work if bufsize has something,
// read(fd, &, 0) is for checking if we can open, else read will return -1
// Create_list : fill the list with file content until \n found
// get_line : extract next line
// polish_list : clean up list, remove the used char

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
//! Read BUFFER_SIZE char from fd into the linked list until \n found
// Alloc mem with malloc size of BUFFER_SIZE
// Reads fd in the buffer and append its content to the list until \n found
// if (!char_read) : when char_read = 0 (end of file), free buf and = '\0'

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
//! Add new node containing buf to the end of list
// Find last node, then alloc new node, assign buf to str_buf
// so the last_node's next node is str_buf with buf as content
// if last_node is NULL, list is empty, so new_node become first node

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);

	copy_str(list, next_str);
	return (next_str);
	
}
//* EXPLANATION
//! Extract the content of the list up to the first newline as a string
// calcul len of the actual string plus the new string
// alloc mem for the two string

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);

	i = 0;
	k = 0;
	while (last_node->str_buf[i] != '\0' 
		&& last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] != '\0'
		&& last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}
//* EXPLANATION
//! Remove char from the list that have been read and prepare
//! the list for the next line read
// alloc buf for string after \n
// clean_node is new list node allocated to store buf

// Find the last node, this node contains the char from the last read buffer

// Locate the end 