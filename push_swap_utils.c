/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:51:38 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 10:06:40 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_b_to_pos(t_stack **b, int pos_b)
{
	if (pos_b <= (*b)->length / 2)
		while (pos_b--)
			rotate_b(b);
	else
	{
		pos_b = (*b)->length - pos_b;
		while (pos_b--)
			reverse_rotate_b(b);
	}
}

void	bring_a_to_pos(t_stack **a, int pos_a)
{
	if (pos_a <= (*a)->length / 2)
		while (pos_a--)
			rotate_a(a);
	else
	{
		pos_a = (*a)->length - pos_a;
		while (pos_a--)
			reverse_rotate_a(a);
	}
}

int	optimize_moves(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	int	i;

	i = 0;
	if ((pos_a <= ((*a)->length / 2)) && (pos_b <= ((*b)->length / 2)))
	{
		while (i < pos_a && i < pos_b)
		{
			rotate_both(a, b);
			i++;
		}
	}
	return (i);
}

int	middle_quartils(t_stack *stack, t_quartils *quartils)
{
	t_stacknode	*current;

	current = stack->begin;
	while (current)
	{
		if (quartils->q1 <= current->value && current->value <= quartils->q3)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_stacknode	*current;
	int			i;

	current = stack->begin;
	if (stack->length > 0)
	{
		i = 1;
		while (i++ < stack->length)
		{
			if (current->value > current->next->value)
				return (0);
			current = current->next;
		}
		return (1);
	}
	return (0);
}
