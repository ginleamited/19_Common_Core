/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:29:24 by jilin             #+#    #+#             */
/*   Updated: 2024/11/13 18:05:16 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_newline(t_list *list)
{
	int i;
	int len;

	if (NULl == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	copy_str(t_list *list, char *str)
{
	int i;
	int k;
	
	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[k] = '\0'
	
}

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

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;
	
	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
// t_node {
// 	int	x;
// 	node *next ;
		
	
// 		x	x	x	x	x	x	x	x	x
// list	
// 		node node node node node node node node
// }

// (t_node *list)
// {
// 	(list) // the whole list
// }
// (t_node *list)
// {
// 	(list)->next // the first node of the list
// }
// (t_node **list)
// {
// 	(*list) // the first node of the list
// }
// (t_node **list)
// {
// 	(*list)->x // the first x of the node
// }
// (t_node **list)
// {
// 	(*list)->next // the second node of the list
	
// (t_node **list)
// {
// 	(*list)->next->x // the x of the second node of the list
// }