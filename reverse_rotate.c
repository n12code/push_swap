/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:39 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:53:02 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(Stack **a)
{
	StackNode	*node_to_rotate;

	if ((*a)->length < 2)
		return ;
	node_to_rotate = remove_stack_bottom(a);
	if (!node_to_rotate)
		return ;
	push_stack_top(a, node_to_rotate);
	if (!(*a))
		return ;
	printf("rra\n");	
}

void	reverse_rotate_b(Stack **b)
{
	StackNode	*node_to_rotate;

	if ((*b)->length < 2)
		return ;
	node_to_rotate = remove_stack_bottom(b);
	if (!node_to_rotate)
		return ;
	push_stack_top(b, node_to_rotate);
	if (!(*b))
		return ;
	printf("rrb\n");	
}

void	reverse_rotate_both(Stack **a, Stack **b)
{
	StackNode	*a_node_to_rotate;
	StackNode	*b_node_to_rotate;

	if ((*a)->length >= 2)
	{
		a_node_to_rotate = remove_stack_bottom(a);
		if (!a_node_to_rotate)
			return ;
		push_stack_top(a, a_node_to_rotate);
		if (!(*a))
			return ;
	}
	if ((*b)->length >= 2)
	{
		b_node_to_rotate = remove_stack_bottom(b);
		if (!b_node_to_rotate)
			return ;
		push_stack_top(b, b_node_to_rotate);
		if (!(*b))
			return ;
	}
	printf("rrr\n");
}