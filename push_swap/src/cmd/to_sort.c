/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:55:26 by jilin             #+#    #+#             */
/*   Updated: 2025/02/24 21:49:39 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a,
	t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
//* EXPLANATION:
//? Rotate both top node to the bottom until the cheapest node 
//? is at the top of the stack
//  As long as the current b is not a's cheapest target node
//  and a is not the cheapest node
//  Rotate both stacks
//  Update the index of the current node in both stacks

static void	rev_rotate_both(t_stack_node **a,
	t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
//* EXPLANATION:
//? Rotate both bottom node to the top until the cheapest
//? node is at the top of the stack
//  As long as the current b is not a's cheapest target node 
//  and a is not the cheapest node
//  Rotate both stacks
//  Update the index of the current node in both stacks

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}
//* EXPLANATION:
//? Prepares the cheapest nodes on top for pushing to stack b
//  If above median, rotate up the nodes
//  If below median, rotate down the nodes
//  Prepares the nodes for pushing
//  Pushes the node to stack b

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}
//* EXPLANATION:
//? Prepares the target node on top for pushing to stack a
//  Just prepares them on top for pushing back to a

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
//* EXPLANATION:
//? Sorts the stacks if there are more than 3 nodes
//  Pushes the first 2 nodes to stack b, so we can use the
//  Turk algorithm
//  initialize the nodes in stack a and b
//  Move the cheapest node from a to sorted b until there are 3 nodes left
//  Sort the last 3 nodes in stack a
//  Initialize the nodes in stack a and b again
//  Move the nodes from b to sorted a until empty
//  Refresh the index of the nodes in stack a
//  Reorder the stack so the minimum node is on top