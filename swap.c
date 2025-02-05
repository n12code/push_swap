/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:36 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 11:28:26 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stacknode	*first_node;
	t_stacknode	*second_node;

	if ((*a)->length < 2)
		return ;
	first_node = remove_stack_top(a);
	if (!first_node)
		return ;
	second_node = remove_stack_top(a);
	if (!second_node)
		return ;
	push_stack_top(a, first_node);
	push_stack_top(a, second_node);
	printf("sa\n");
}

void	swap_b(t_stack **b)
{
	t_stacknode	*first_node;
	t_stacknode	*second_node;

	if ((*b)->length < 2)
		return ;
	first_node = remove_stack_top(b);
	if (!first_node)
		return ;
	second_node = remove_stack_top(b);
	if (!second_node)
		return ;
	push_stack_top(b, first_node);
	push_stack_top(b, second_node);
	printf("sb\n");
}

void	swap_both(t_stack **a, t_stack **b)
{
	t_stacknode	*first_node_a;
	t_stacknode	*second_node_a;
	t_stacknode	*first_node_b;
	t_stacknode	*second_node_b;

	if ((*a)->length < 2 || (*b)->length < 2)
		return ;
	first_node_a = remove_stack_top(a);
	first_node_b = remove_stack_top(b);
	if (!first_node_a || !first_node_b)
		return ;
	second_node_a = remove_stack_top(a);
	second_node_b = remove_stack_top(b);
	if (!second_node_a || !second_node_b)
		return ;
	push_stack_top(a, first_node_a);
	push_stack_top(b, first_node_b);
	push_stack_top(a, second_node_a);
	push_stack_top(b, second_node_b);
	printf("ss\n");
}

// void	swap_a(t_stack **a)
// {
// 	int		first_node_value;

// 	if ((*a)->length < 2)
// 		return ;
// 	first_node_value = (*a)->begin->value;
// 	(*a)->begin->value = (*a)->begin->next->value;
// 	(*a)->begin->next->value = first_node_value;
// 	printf("sa\n");
// }

// void	swap_b(t_stack **b)
// {
// 	int		first_node_value;

// 	if ((*b)->length < 2)
// 		return ;
// 	first_node_value = (*b)->begin->value;
// 	(*b)->begin->value = (*b)->begin->next->value;
// 	(*b)->begin->next->value = first_node_value;
// 	printf("sb\n");
// }

// void	swap_both(t_stack **a, t_stack **b)
// {
// 	int	first_node_value;

// 	if ((*a)->length >= 2)
// 	{
// 		if ((*a)->length < 2)
// 			return ;
// 		first_node_value = (*a)->begin->value;
// 		(*a)->begin->value = (*a)->begin->next->value;
// 		(*a)->begin->next->value = first_node_value;
// 	}
// 	if ((*b)->length >= 2)
// 	{
// 		if ((*b)->length < 2)
// 			return ;
// 		first_node_value = (*b)->begin->value;
// 		(*b)->begin->value = (*b)->begin->next->value;
// 		(*b)->begin->next->value = first_node_value;
// 	}
// 	printf("ss\n");
// }