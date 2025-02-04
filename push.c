/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:34 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:52:47 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(Stack **a, Stack **b)
{
	StackNode	*node_to_push;

	if (is_empty_stack(*b))
		return ;
	node_to_push = remove_stack_top(b);
	if (!node_to_push)
		return ;
	push_stack_top(a, node_to_push);
	if (!(*a))
		return ;
	printf("pa\n");
}

void	push_b(Stack **a, Stack **b)
{
	StackNode	*node_to_push;

	if (is_empty_stack(*a))
		return ;
	node_to_push = remove_stack_top(a);
	if (!node_to_push)
		return ;
	push_stack_top(b, node_to_push);
	if (!(*b))
		return ;
	printf("pb\n");
}