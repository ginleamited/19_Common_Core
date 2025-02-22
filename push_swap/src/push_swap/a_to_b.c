/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:34:50 by jilin             #+#    #+#             */
/*   Updated: 2025/02/22 13:36:13 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}
//* EXPLANATION:
//? This function gives an index to each node of the stack,
//? and sets a boolean to true if the node is above the median of the stack.
//  It will have a column of true and false values in the stack.

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_b;
	t_stack_node *target_node;
	long match_index;

	while (a)
	{
		match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
					&& current_b->nbr > match_index)
			{
				match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
//* EXPLANATION:
//? This function find 'a' node's target node in stack 'b' to find the largest
//? number in b that is smaller than the current node in a.
// current_b and target_node store the pointer to the node in stack b
//? match_index stores the value of the closest smaller value in stack a
// we set the LONG_MIN value to match_index to compare it with the first value in stack b
//? We set up *current_b to reset its value after each iteration of a
// we set the current_b as b to iterate through the stack b
// If the nbr of b is smaller than the nbr of a and bigger than the match_index, 
// we set the match_index to the nbr of b and the target_node to the current_b
// if not, we iterate through the stack b.
//? Check if match_index is still LONG_MIN, if it is, we set the target node to the maximum value in stack b
// if not, match_index is the closest smaller value in stack b, we set the target node to the target_node
//? Then we will try to find the target node for the next node in stack a

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
//* EXPLANATION:
//? This function calculates the cost of pushing the node 'a' to stack 'b',
//? which is the sum the instrctions of a and b so the node a will be on
//? the top of a and can be pushed to the top of b.
//? If node a is below the median, 
// the push_cost = len_a - index of a.
//? Means the node a is above median, if target node is above the median too, 
// the push_cost += index of target node in b as a->push_cost is a->index.
//? If node a is above median and target node is below median,
//? push_cost += (len_b - index of target node in b).
// Move to the next to calculate the cost.

void set_cheapest(t_stack_node *stack)
{
	long	cheapest_value;
	t_stack_node *cheapest_node;
	
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
//* EXPLANATION:
//? This function sets the cheapest node in true or false in the stack.
// As we are looking for cheapest node, we set to LONG_MAX so
// it can find easily cheaper value than the LONG_MAX.
//? If the push_cost of the node is smaller than the cheapest_value,
// then assign the current node as the cheapest_node.
// Check the next node.
//? If we find the cheapest node, we set the cheapest value to true.

void init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
//* EXPLANATION:
//? This function initializes the nodes of stack a needed for the push_swap algorithm.