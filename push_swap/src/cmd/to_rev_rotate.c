/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:55:22 by jilin             #+#    #+#             */
/*   Updated: 2025/02/22 13:29:00 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}
//* EXPLANATION:
//?	This function is rotating the stack's bottom node to the top
//  If the stack is empty or has only one node, nothing to rotate
//  Set last_node to the last node of the stack
//  when we set the last_node->prev->next to NULL, we are detaching the last node,
//  the second last node will be the last node
//  When we point the next to *stack, it point to the top node of the stack
//  Last node-s prev will be NULL, because it is the top node now
//  Then we set the stack to last_node, so the last node will be the top node
//  Then we update the prev pointer of the previous first node to point to the
//  last node, so the doubly linked list is maintained

void rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}
//* EXPLANATION:
//? Put the bottom node of stack a to the top of the stack

void rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}
//* EXPLANATION:
//? Put the bottom node of stack b to the top of the stack

void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
//* EXPLANATION:
//? Put the bottom node of both stacks to the top of the stack