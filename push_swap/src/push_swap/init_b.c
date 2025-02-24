/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:34:55 by jilin             #+#    #+#             */
/*   Updated: 2025/02/24 22:04:26 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			match_index;

	while (b)
	{
		match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr
				&& current_a->nbr < match_index)
			{
				match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
//* EXPLANATION:
//? This functin sets a target node for each node in stack
//? b to find the smallest
//? number but greater than the current node in stack b.
//? To make it decreasing order.
//  The target node in this function is a pointer to store
//  the target node in stack a for each node in stack b.
//?  The b loop tries to find the target node for each node in stack b.
//  We set the LONG_MAX value to match_index to make sure the
//  first value in stack a is smaller than the match_index.
//?  If the nbr of a is bigger than the nbr of b and smaller
//?  than the match_index, 
// we set the match_index to the nbr of a and the target_node to the current_a.
//  If not, we iterate through the stack a.
//?  If match_index not changed, we set the target node to the
//?  smallest in stack a.
//  If target node is found, we will update it and we will find
// the target node of the next node in b.

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
//* EXPLANATION:
//? This function prepares the nodes for pushing `b` to `a`