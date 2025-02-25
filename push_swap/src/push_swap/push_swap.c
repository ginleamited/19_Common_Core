/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:16:16 by jilin             #+#    #+#             */
/*   Updated: 2025/02/25 01:16:42 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// void	print_stack(t_stack_node *stack)
// {
// 	t_stack_node	*current;

// 	current = stack;
// 	while (current)
// 	{
// 		printf("%d\n", current->nbr);
// 		current = current->next;
// 	}
// }

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (ac != 2)
		init_stack_a(&a, av + 1);
	else
		init_stack_a(&a, av);
	if (ac == 2)
		ft_free(av);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	// print_stack(a);
	// return (free_stack(&a), 0);
}

//* EXPLANATION
//? This program will sort random numbers in ascending order
// 	First, set both pointers in a and b to NULL
//?  If argc is 1, means there is no argument, return 1
//?  If argc is 2, and the first character of the first argument is NULL,
//?  return 1
//?  If argc is 2, split the first argument by space and store it in av
//?  If argc is not 2, av + 1 to skip the program name
//?  If argc is 2, av is the first argument, then we will free it
//?  So if the stack is not sorted:
//?  If the stack length is 2, swap the first two elements
//?  If the stack length is 3, sort with the sort_three function
//?  If the stack length is more than 3, sort with the sort_stacks function
//  In the end, free the stack and return 0