/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:55:22 by jilin             #+#    #+#             */
/*   Updated: 2025/02/18 22:50:23 by jilin            ###   ########.fr       */
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
	last->next->prev = last;
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


Example Walkthrough

Let’s use an example to visualize how this works. Suppose we have the following stack:
Copy

stack -> [A] -> [B] -> [C] -> NULL

Here:

    [A] is the top node.

    [C] is the last node.

    [B] is the second-to-last node.

Step 1: Check if the stack is empty or has only one node

    The stack has more than one node, so the function proceeds.

Step 2: Find the last node

    last = find_last(*stack); sets last to point to [C].

Step 3: Detach the last node from the stack

    last->prev->next = NULL; updates the next pointer of [B] (the second-to-last node) to NULL:
    Copy

    [B]->next = NULL;

    Now the stack looks like this:
    Copy

    stack -> [A] -> [B] -> NULL
    [C] is detached.

Step 4: Move the last node to the top

    last->next = *stack; sets [C]->next to point to [A]:
    Copy

    [C]->next = [A];

    Now the stack looks like this:
    Copy

    [C] -> [A] -> [B] -> NULL

Step 5: Set the prev pointer of the last node to NULL

    last->prev = NULL; sets [C]->prev to NULL:
    Copy

    [C]->prev = NULL;

Step 6: Update the stack pointer to the new top node

    *stack = last; updates the stack pointer to point to [C]:
    Copy

    stack -> [C] -> [A] -> [B] -> NULL

Step 7: Update the prev pointer of the new second node

    last->next->prev = last; updates the prev pointer of [A] to point back to [C]:
    Copy

    [A]->prev = [C];

    Now the stack looks like this:
    Copy

    stack -> [C] -> [A] -> [B] -> NULL
           ^         |
           |_________|

Final Result

After the rev_rotate function, the stack is rotated such that the bottom node ([C]) is now at the top:
Copy

stack -> [C] -> [A] -> [B] -> NULL