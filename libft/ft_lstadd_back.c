/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:24:35 by jilin             #+#    #+#             */
/*   Updated: 2024/10/31 15:55:16 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **lst, t_list *new)
{
	t_list	*last;
	
	if (NULL == lst)
		return ;
	if (NULL == *lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

//* MAIN

//* EXPLANATION
// Add a new element in the back of a list
// First verify if lst itself exist or properly initialized
// Then check if the *lst is empty, if yes then the add the "new"
// node which will be the first and the only node.
// Then let's use the lstlast function to point the last node
// last->next = new : the last node will point the "new" node
