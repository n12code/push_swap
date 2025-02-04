/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:44 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:52:42 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void push_stack_top(Stack **stack, StackNode *node)
{
    if (is_empty_stack(*stack))
    {
		*stack = malloc(sizeof(**stack));
		if (!*stack)
		{
			*stack = NULL;
			return ;
		}
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

void	push_stack_bottom(Stack **stack, StackNode *node)
{
	if (is_empty_stack(*stack))
	{
		*stack = malloc(sizeof(**stack));
		if (!*stack)
		{
			*stack = NULL;
			return ;
		}
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