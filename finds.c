/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:58:11 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:51:44 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(Stack *stack)
{
	int			min;
	StackNode	*current;

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

int	find_max(Stack *stack)
{
	int			max;
	StackNode	*current;

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

int	find_pos(Stack *stack, int node_value)
{
	StackNode	*current;
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

int	find_pos_a(Stack *stack, int node_value)
{
	StackNode	*current;
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
		if (current->back && (current->back->value < node_value && node_value < current->value))
			return (i);
		current = current->next;
		i++;
	}
	return (find_pos(stack, min));
}