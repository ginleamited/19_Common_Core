/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:23 by jilin             #+#    #+#             */
/*   Updated: 2024/11/14 23:09:52 by jilin            ###   ########.fr       */
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

//! Read the file line by line, store the content in a custom linked list(t_list)
//! when we call get_next_line, returns the next line

// declare a static linked list which retains content and let it stay in the stopped position
// (char *next_line) to store extracted line that will be returned and 
// hold the char up to the first \n

// secure the code, fd always > 0, only work if bufsize has something,
// read(fd, &, 0) is for checking if we can open, else read will return -1

// Create_list : fill the list with characters from fd until \n found
// get_line : extract next line from the list
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

//! Read char from fd into a buffer and store them in a linked list 
//! until \n found

// (t_list **list) is a pointer to the linked list that stores the file's content
// allow allso to modify the oiginal list (add node) and update it
// int char_read store number of char read on each call, if 0 -> end of file
// char *buf is a dynamically allocated buffer that temporarily hold read char
// buf is size of BUFFER_SIZE + 1

// Alloc mem for BUFFER_SIZE + 1 and read data from fd in the buffer 
// and append its content to the list until \n found
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

// t_list *new_node is a pointer to a new allocated node that contain buf,
// as str_buf and be added to the end of list
// t_list *last_node is a pointer to the last node in the linked list,
// used to find where new node should be appended
// char *buf is data read from the file that need to be store in new node

// Find last node, then alloc new node, assign buf to str_buf
// so the last_node's next node is str_buf with buf as content
// if last_node is NULL so new_node become first node

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

// t_list *list : head of the linked list, containing all the buffered
// data read so far. read through this list to extract a line up to \n or \0
// int str_len store len of the line up to the /n
// char *next_str : dynamically allocated string that will contain the 
// extracted line from the linked list.

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

// t_list *last_node point the last node
// t_list *clean_node store remaining char after \n if no char then free
// int i : locate the \n in last_node->str_buf
// int k : copying char after \n into buf
// char *buf : if there are char after \n they are copied in buf

// alloc buf for string after \n
// clean_node is new list node allocated to store buf

// Find the last node in the linked list, this node contains 
// the char from the last buffer read from file
// First while: i will count the str_buf and stop at \n or \0
// Second while: start after \n and copy chars from str_buf into buf
// starting with k, represent the beginning of buf, 
// add a \0

// assign buf to the str_buf of clean_node
// indicate that clean_node will be the last node
// call dealloc to free any nodes in the list that 
// have been processed