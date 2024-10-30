/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:42:45 by jilin             #+#    #+#             */
/*   Updated: 2024/10/30 23:03:24 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lst_size(t_list *lst)
{
	int	counter;
	
	counter = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		counter++;
	}
	return (counter)
}

//* MAIN

//* EXPLANATION
// We have to return the size
// lst = lst->next : It will go from node to node as long counter increase