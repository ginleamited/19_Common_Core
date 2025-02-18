/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:55:20 by jilin             #+#    #+#             */
/*   Updated: 2025/02/18 22:25:35 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void push(t_stack **dst, t_stack **src)
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

Example Walkthrough

Let’s say we have:

    Source stack (*src):
    Copy

    src -> [node1] -> [node2] -> NULL

    Destination stack (*dst):
    Copy

    dst -> [A] -> [B] -> NULL

Step 1: tmp = *src;

    tmp points to [node1].

Step 2: *src = (*src)->next;

    src now points to [node2].

Step 3: tmp->next = *dst;

    tmp (which is [node1]) now points to [A]:
    Copy

    tmp -> [node1] -> [A] -> [B] -> NULL

Step 4: tmp->next->prev = tmp;

    The prev pointer of [A] is updated to point back to [node1]:
    Copy

    tmp -> [node1] -> [A] -> [B] -> NULL
           ^         |
           |_________|

Step 5: *dst = tmp;

    dst now points to [node1]:
    Copy

    dst -> [node1] -> [A] -> [B] -> NULL
           ^         |
           |_________|

Final Result

    Source stack (*src):
    Copy

    src -> [node2] -> NULL

    Destination stack (*dst):
    Copy

    dst -> [node1] -> [A] -> [B] -> NULL


What is tmp->next->prev?

    tmp: This is the node being moved from the source stack to the destination stack. In our example, tmp is [node1].

    tmp->next: After tmp->next = *dst;, tmp->next points to the current top element of the destination stack. In our example, tmp->next is [A].

    tmp->next->prev: This refers to the prev pointer of the node that tmp->next points to. In our example, tmp->next->prev is the prev pointer of [A].

What does tmp->next->prev = tmp; do?

This line updates the prev pointer of the node [A] to point back to [node1]. Here's why this is necessary:

    In a doubly linked list, every node has two pointers:

        next: Points to the next node in the list.

        prev: Points to the previous node in the list.

    When we insert [node1] at the top of the destination stack, we need to ensure that the prev pointer of the node after [node1] (which is [A]) correctly points back to [node1].

Visualization

Let’s visualize the state of the stacks before and after this line.
Before tmp->next->prev = tmp;:

    tmp points to [node1].

    tmp->next points to [A].

    The prev pointer of [A] is currently NULL (or pointing to whatever it was before).

Copy

tmp -> [node1] -> [A] -> [B] -> NULL
       ^         |
       |_________|

At this point:

    [node1] is correctly linked to [A] via tmp->next = *dst;.

    However, [A]'s prev pointer is not yet updated to point back to [node1].

After tmp->next->prev = tmp;:

    The prev pointer of [A] is updated to point back to [node1].

Copy

tmp -> [node1] -> [A] -> [B] -> NULL
       ^         |
       |_________|

Now:

    [node1] points to [A] via next.

    [A] points back to [node1] via prev.

Why is this important?

In a doubly linked list, every node must maintain correct next and prev pointers to ensure the list can be traversed in both directions. If we don’t update tmp->next->prev, the prev pointer of [A] would still point to its previous node (or NULL), breaking the doubly linked list structure.


void	push_a(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}
//* EXPLANATION:
//? This function is pushing the top element of a to the top of b

void	push_b(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
//* EXPLANATION:
//? This function is pushing the top element of b to the top of a