/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:20:17 by jilin             #+#    #+#             */
/*   Updated: 2024/10/30 22:42:26 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

//* MAIN

//* EXPLANATION
// Add a new element in the front of a list
// if (lst && new) : check if it is NULL pointers
// new->next = *lst : new will point where lst points
// (*lst) = new : *lst will points to new