/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:39 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:19:07 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **a)
{
	t_stacknode	*node_to_rotate;

	if ((*a)->length < 2)
		return ;
	node_to_rotate = remove_stack_bottom(a);
	if (!node_to_rotate)
		return ;
	push_stack_top(a, node_to_rotate);
	ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(t_stack **b)
{
	t_stacknode	*node_to_rotate;

	if ((*b)->length < 2)
		return ;
	node_to_rotate = remove_stack_bottom(b);
	if (!node_to_rotate)
		return ;
	push_stack_top(b, node_to_rotate);
	ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	t_stacknode	*a_node_to_rotate;
	t_stacknode	*b_node_to_rotate;

	if ((*a)->length >= 2)
	{
		a_node_to_rotate = remove_stack_bottom(a);
		if (!a_node_to_rotate)
			return ;
		push_stack_top(a, a_node_to_rotate);
	}
	if ((*b)->length >= 2)
	{
		b_node_to_rotate = remove_stack_bottom(b);
		if (!b_node_to_rotate)
			return ;
		push_stack_top(b, b_node_to_rotate);
	}
	ft_putendl_fd("rrr", 1);
}
