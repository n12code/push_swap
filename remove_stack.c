/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:46 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:52:59 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

StackNode	*remove_stack_top(Stack **stack)
{
	StackNode	*temp;
	
	if (is_empty_stack(*stack))
		return (NULL);
	else if ((*stack)->begin == (*stack)->end)
	{
		temp = (*stack)->begin;
		(*stack)->length = 0;
		(*stack)->begin = NULL;
		(*stack)->end = NULL;
		temp->next = NULL;
		temp->back = NULL;
	}
	else
	{
		temp = (*stack)->begin;
		(*stack)->begin = (*stack)->begin->next;
		(*stack)->begin->back = NULL;
		(*stack)->length--;
		temp->next = NULL;
		temp->back = NULL;
	}
	return (temp);
}

StackNode	*remove_stack_bottom(Stack **stack)
{
	StackNode	*temp;

	if (is_empty_stack(*stack))
		return (NULL);
	else if ((*stack)->begin == (*stack)->end)
	{
		temp = (*stack)->begin;
		(*stack)->length = 0;
		(*stack)->begin = NULL;
		(*stack)->end = NULL;
		temp->next = NULL;
		temp->back = NULL;
	}
	else
	{
		temp = (*stack)->end;
		(*stack)->end = (*stack)->end->back;
		(*stack)->end->next = NULL;
		(*stack)->length--;
		temp->next = NULL;
		temp->back = NULL;
	}
	return (temp);
}