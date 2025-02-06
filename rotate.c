/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:37 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:18:40 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	t_stacknode	*node_to_rotate;

	if ((*a)->length < 2)
		return ;
	node_to_rotate = remove_stack_top(a);
	if (!node_to_rotate)
		return ;
	push_stack_bottom(a, node_to_rotate);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack **b)
{
	t_stacknode	*node_to_rotate;

	if ((*b)->length < 2)
		return ;
	node_to_rotate = remove_stack_top(b);
	if (!node_to_rotate)
		return ;
	push_stack_bottom(b, node_to_rotate);
	ft_putendl_fd("rb", 1);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	t_stacknode	*a_node_to_rotate;
	t_stacknode	*b_node_to_rotate;

	if ((*a)->length >= 2)
	{
		a_node_to_rotate = remove_stack_top(a);
		if (!a_node_to_rotate)
			return ;
		push_stack_bottom(a, a_node_to_rotate);
	}
	if ((*b)->length >= 2)
	{
		b_node_to_rotate = remove_stack_top(b);
		if (!b_node_to_rotate)
			return ;
		push_stack_bottom(b, b_node_to_rotate);
	}
	ft_putendl_fd("rr", 1);
}
