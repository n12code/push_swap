/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:58:11 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 10:01:52 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int			min;
	t_stacknode	*current;

	min = stack->begin->value;
	current = stack->begin->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int			max;
	t_stacknode	*current;

	max = stack->begin->value;
	current = stack->begin->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_pos(t_stack *stack, int node_value)
{
	t_stacknode	*current;
	int			i;

	i = 0;
	current = stack->begin;
	while (current)
	{
		if (current->value == node_value)
			return (i);
		current = current->next;
		++i;
	}
	return (i);
}

int	find_pos_a(t_stack *stack, int node_value)
{
	t_stacknode	*current;
	int			min;
	int			max;
	int			i;

	min = find_min(stack);
	max = find_max(stack);
	i = 0;
	if (node_value < min || node_value > max)
		return (find_pos(stack, min));
	current = stack->begin;
	while (current)
	{
		if (!current->back && current == stack->begin
			&& stack->end->value < node_value && node_value < current->value)
			return (i);
		if (current->back
			&& current->back->value < node_value && node_value < current->value)
			return (i);
		current = current->next;
		i++;
	}
	return (find_pos(stack, min));
}
