/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:27:26 by jilin             #+#    #+#             */
/*   Updated: 2025/01/23 15:40:13 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		resultat *= 10;
		resultat += str[i] - 48;
		i++;
	}
	return (resultat * signe);
}

//* EXPLANATION:
// Basic atoi function

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

//* EXPLANATION:
// This function appends a new node to the stack
// If the stack is empty, then return
// Allocate memory for the new node
// Assign the value of the new node to `n`
// Assign the next node to NULL
// Assign the cheapest flag to 0
// If the stack is empty, then assign the new node to the stack
// If the stack is not empty, then find the last node in the stack
// Assign the next node to the last node
// Assign the previous node to the last node


void	init_stack_a(t_stack_node **a, char **av)
{
	long	n;
	int		i;
	
	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_error(a);
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (error_duplicate(*a, (int)n))
			free_error(a);
		append_node(a, (int)n);
		i++;
	}
}

//* EXPLANATION:
// Check if the input is a number or not
// If not, then free the stack
// To check the overflow, if the number is too big or too small, then free the stack
// If the number is duplicate, then free the stack
// If everything is fine, then append the node to linked list by taking a
// a pointer to stack `a`, create a new node and assign `n` to that new node
// Repeat until the end of the inputI


t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//* EXPLANATION:
// This function searches for the cheapest node
// So we loop in every node in the stack until NULL, for each node we check
// using the boolean if the cheapest flag is true.
// If found, then return stack.
// If not found, moves to the next node.
// In the end, if still no found, return NULL

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

//* EXPLANATION:
// This function moves the required node to the top of the stack
// It will check in each stack if the required node is above median or not,
// resulting doing rotate or reverse rotate