/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:05:30 by jilin             #+#    #+#             */
/*   Updated: 2025/02/12 00:18:13 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
//* EXPLANATION:
//? This function will return the length of the stack.
// in this while loop, it will iterate through the stack 
// and increment the len
//? while (stack) will loop until the last node in the stack
// because we need to count all nodes, including the last one.

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
//* EXPLANATION:
//? This function will return true if the stack is sorted in ascending order
// if stack->nbr is greater than the next stack->nbr, 
// it means that it is not in ascending order, if not, move to the next node
//? while (stack->next) will check if the next node is NULL.
// We need to compare each node with the next, 
// so we stop before the last node to avoid accessing NULL.

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
//* EXPLANATION:
//? This function will return the last node in the stack
// 	As the next node is not NULL, the stack will point to the next node
// until the next node is NULL, then the stack will return the last node

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node)
}

//* EXPLANATION:

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}