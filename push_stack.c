/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:44 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:34:49 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack_top(t_stack **stack, t_stacknode *node)
{
	if (is_empty_stack(*stack))
	{
		(*stack)->length = 1;
		(*stack)->begin = node;
		(*stack)->end = node;
	}
	else
	{
		(*stack)->begin->back = node;
		node->next = (*stack)->begin;
		node->back = NULL;
		(*stack)->begin = node;
		(*stack)->length++;
	}
}

void	push_stack_bottom(t_stack **stack, t_stacknode *node)
{
	if (is_empty_stack(*stack))
	{
		(*stack)->length = 1;
		(*stack)->begin = node;
		(*stack)->end = node;
	}
	else
	{
		(*stack)->end->next = node;
		node->back = (*stack)->end;
		node->next = NULL;
		(*stack)->end = node;
		(*stack)->length++;
	}
}
