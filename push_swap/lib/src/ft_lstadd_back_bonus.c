/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:24:35 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	if (last)
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
