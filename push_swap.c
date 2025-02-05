/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:26:32 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 11:30:14 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, t_quartils *quartils)
{
	push_quartils(a, b, quartils);
	//errors done above
	if (!is_sorted(*a))
		handle_three(a);
	while ((*b)->length > 0)
		insert_in_a(a, b, find_best_move(*a, *b));
	bring_min_to_top(a);
}

void	insert_in_a(t_stack **a, t_stack **b, int best_move)
{
	int	pos_a;
	int	pos_b;
	int	opti;

	pos_a = find_pos_a(*a, best_move);
	pos_b = find_pos(*b, best_move);
	opti = optimize_moves(a, b, pos_a, pos_b);
	pos_a -= opti;
	pos_b -= opti;
	bring_b_to_pos(b, pos_b);
	bring_a_to_pos(a, pos_a);
	push_a(a, b);
}

void	bring_min_to_top(t_stack **a)
{
	int	min;
	int	pos;

	min = find_min(*a);
	if ((*a)->begin->value != min)
	{
		pos = find_pos(*a, min);
		if (pos <= (*a)->length / 2)
			while ((*a)->begin->value != min)
				rotate_a(a);
		else
			while ((*a)->begin->value != min)
				reverse_rotate_a(a);
	}
}

void	push_quartils(t_stack **a, t_stack **b, t_quartils *quartils)
{
	t_stacknode	*current;

	current = (*a)->begin;
	while (current && middle_quartils(*a, quartils) && (*a)->length >= 8)
	{
		current = (*a)->begin;
		if (current->value >= quartils->q1 && current->value <= quartils->med)
		{
			push_b(a, b);
			rotate_b(b);
		}
		else if (current->value <= quartils->q3
			&& current->value >= quartils->med)
			push_b(a, b);
		else
			rotate_a(a);
	}
	while ((*a)->length > 3)
	{
		current = (*a)->begin;
		push_b(a, b);
		if (current->value < quartils->med)
			rotate_b(b);
	}
}

void	handle_three(t_stack **a)
{
	int	first;
	int	mid;
	int	last;

	first = (*a)->begin->value;
	mid = (*a)->begin->next->value;
	last = (*a)->end->value;
	if ((first < mid) && (mid > last) && (first < last))
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else if ((first < mid) && (mid > last) && (first > last))
		reverse_rotate_a(a);
	else if ((first > mid) && (mid < last) && (first > last))
		rotate_a(a);
	else if ((first > mid) && (mid > last))
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else
		swap_a(a);
}
