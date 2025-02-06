/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:34 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:19:19 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stacknode	*node_to_push;

	node_to_push = remove_stack_top(b);
	if (!node_to_push)
		return ;
	push_stack_top(a, node_to_push);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stacknode	*node_to_push;

	node_to_push = remove_stack_top(a);
	if (!node_to_push)
		return ;
	push_stack_top(b, node_to_push);
	ft_putendl_fd("pb", 1);
}
