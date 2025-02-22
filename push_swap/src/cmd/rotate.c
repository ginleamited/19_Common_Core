/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:55:24 by jilin             #+#    #+#             */
/*   Updated: 2025/02/22 13:32:03 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}
//* EXPLANATION:
//?	This function is rotating the stack's top node to the bottom
//  If the stack is empty or one node, do nothing
//  Find the last node and connect it to the top node by
//  moving the first node behind the last node
//  Move the second node to the first
//  Set the prev as NULL, so we can detach it from the top
//  Last_node's next is the old first node, it's prev
//  will be last_node, so double linked list is maintained
//  Last_node's next is the old first node NULL its next node

void ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}
//* EXPLANATION:
//? Put the top node of stack a to the bottom of the stack

void rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}
//* EXPLANATION:
//? Put the top node of stack b to the bottom of the stack

void rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
//* EXPLANATION:
//? Put the top node of both stacks to the bottom of the stack
