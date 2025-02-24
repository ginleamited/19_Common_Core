/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:21 by jilin             #+#    #+#             */
/*   Updated: 2025/02/24 03:06:15 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || ft_isdigit(*str_n)))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !ft_isdigit(*(str_n + 1)))
		return (1);
	while (*++str_n)
	{
		if (!ft_isdigit(*str_n))
			return (1);
	}
	return (0);
}
//* EXPLANATION:
//? This function return 1 if the input is not a number including the sign
//  In the while loop we preincrement 1 because we already checked the first char,
//  it is checking if the rest of the input is a number or not.

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}
//* EXPLANATION:
//? This function check if there is duplicate input in a
//  If a->nbr == n, means there is a duplicate and it is already in n

void	free_stack(t_stack_node **stack)
{
	t_stack_node *tmp;
	t_stack_node *current;
	
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
//* EXPLANATION:
//? This function will free each node in the stack
//  we use a tmp pointer to store current->next, because when we free current,
//  current->next will be lost, then we will update current to tmp

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
//* EXPLANATION:
//? This function will free the stack a and print "Error"