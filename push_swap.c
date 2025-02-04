/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:26:32 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:55:43 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(Stack **a, Stack **b, Quartils *quartils)
{
	push_quartils(a, b, quartils);
	if (!is_sorted(*a))
		handle_three(a);
	push_back_into_a(a, b);
}

void	push_back_into_a(Stack **a, Stack **b)
{
	while (*b)
		insert_in_a(a, b, find_best_move(*a, *b));
	bring_min_to_top(a);
}

void	insert_in_a(Stack **a, Stack **b, int best_move)
{
	int		pos_a;
	int		pos_b;
	int		opti;
	
	pos_a = find_pos_a(*a, best_move);
	pos_b = find_pos(*b, best_move);
	opti = optimize_moves(a, b, pos_a, pos_b);
	pos_a -= opti;
	pos_b -= opti;
	bring_b_to_pos(b, pos_b);
	bring_a_to_pos(a, pos_a);
	push_a(a, b);
}

void	bring_b_to_pos(Stack **b, int pos_b)
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

void	bring_a_to_pos(Stack **a, int pos_a)
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

int		optimize_moves(Stack **a, Stack **b, int pos_a, int pos_b)
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

void	bring_min_to_top(Stack **a)
{
	int		min;
	int		pos;

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

int	middle_quartils(Stack *stack, Quartils *quartils)
{
	StackNode	*current;

	current = stack->begin;
	while (current)
	{
		if (quartils->q1 <= current->value && current->value <= quartils->q3)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_quartils(Stack **a, Stack **b, Quartils *quartils)
{
	StackNode	*current;

	while (middle_quartils(*a, quartils) && (*a)->length >= 8)
	{
		current = (*a)->begin;
		if (current->value >= quartils->q1 && current->value <= quartils->med)
		{
			push_b(a, b);
			rotate_b(b);
		}
		else if (current->value <= quartils->q3 && current->value >= quartils->med)
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

int	is_sorted(Stack *stack)
{
	StackNode	*current;
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

void	handle_three(Stack **a)
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