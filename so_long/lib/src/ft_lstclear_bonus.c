/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:52:37 by jilin             #+#    #+#             */
/*   Updated: 2024/11/01 00:52:37 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = (NULL);
}

//* MAIN

//* EXPLANATION
// clear the content then free the node
// We declare current to iterate and we declare tmp just like swap
// First we check if it exist
// Then we iterate between nodes, we store the value of the actual
// node into tmp, then we iterate to the next node
// Then we delete the content that is in the previous node
// then we free the previous node itself
// until we atteign the NULL, we will del and free the last node
//! **lst is a double pointer because it access and free each node in the list
//! It can also modify *lst to NULL after freeing the list