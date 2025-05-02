/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:11:49 by jilin             #+#    #+#             */
/*   Updated: 2024/11/01 01:11:49 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (f != NULL)
			content = f(lst->content);
		else
			content = lst->content;
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (f != NULL)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

//* MAIN

//* EXPLANATION
// Create a new linked list by applying a function f to each node's content
// We declare *new_list for a list that countain new nodes
// We declare *new_node that contain modified "content"
// We declare *content to store modified content or point original content

//? Initially used this but has severals issues
// if (f != NULL)
//     new_node = ft_lstnew(f(lst->content));
// else
//     new_node = ft_lstnew(lst->content);
// With this code we wouldn't have a way to access 
// or free the transformed content before calling ft_lstclear

// Check if lst exist
// set new_list to NULL se we can append nodes in it, becoming the 
// head of the new list.

// Loop lst so we can set the function to each node's "content"
// If f != NULL, the content has been transformed, point to newly
// allocated memory.
// If f == NULL, point the original content when creating the new node

// If !new_node or stnew fails, we don't need to del the content because 
// it is not dynamically allocated memory created by function f,
// it will be free later with lstclear

// Then use the lstadd function to append new node behind the actual one
// And iterate to the next one using lst = lst->next