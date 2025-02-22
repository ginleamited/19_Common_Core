/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:55:20 by jilin             #+#    #+#             */
/*   Updated: 2025/02/22 14:11:59 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*top_node;
	
	if (!*src)
		return ;
	top_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top_node->prev = NULL;
	if (!*dst)
	{
		*dst = top_node;
		top_node->next = NULL;
	}
	else
	{
		top_node->next = *dst;
		top_node->next->prev = top_node;
		*dst = top_node;
	}
}
//* EXPLANATION:
//?	This function is pushing the top element of src to the top of dst
//  the top_node will store the top element of src
//  src will point to the next element, then we will pop the top element
//  If dst is empty, we will assign top_node to dst and Null terminate
//  If not, top_node will point to the first node of dst, 
//  as top_node -> [top_node1] -> [dst1] -> [dst2] -> NULL
//  then we will make sure in this double linked list, next and prev
//  are pointing to the right node, so the prev of top_node->next will not be NULL
//  Then we will assign top_node to dst, so the node in top_node will be
//  on the top of dst

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}
//* EXPLANATION:
//? This function is pushing the top element of a to the top of b

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
//* EXPLANATION:
//? This function is pushing the top element of b to the top of a