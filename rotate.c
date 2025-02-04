/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:37 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:53:05 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(Stack **a)
{
	StackNode	*node_to_rotate;

	if ((*a)->length < 2)
		return ;
	node_to_rotate = remove_stack_top(a);
	if (!node_to_rotate)
		return ;
	push_stack_bottom(a, node_to_rotate);
	if (!(*a))
		return ;
	printf("ra\n");
}

void	rotate_b(Stack **b)
{
	StackNode	*node_to_rotate;

	if ((*b)->length < 2)
		return ;
	node_to_rotate = remove_stack_top(b);
	if (!node_to_rotate)
		return ;
	push_stack_bottom(b, node_to_rotate);
	if (!(*b))
		return ;
	printf("rb\n");
}

void	rotate_both(Stack **a, Stack **b)
{
	StackNode	*a_node_to_rotate;
	StackNode	*b_node_to_rotate;

	if ((*a)->length >= 2)
	{
		a_node_to_rotate = remove_stack_top(a);
		if (!a_node_to_rotate)
			return ;
		push_stack_bottom(a, a_node_to_rotate);
		if (!(*a))
			return ;
	}
	if ((*b)->length >= 2)
	{
		b_node_to_rotate = remove_stack_top(b);
		if (!b_node_to_rotate)
			return ;
		push_stack_bottom(b, b_node_to_rotate);
		if (!(*b))
			return ;
	}
	printf("rr\n");
}