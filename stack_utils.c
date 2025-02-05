/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:47 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 16:16:44 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	clear_stack(t_stack **stack)
{
	t_stacknode	*current;
	t_stacknode	*next;

	if (!(*stack))
		return ;
	current = (*stack)->begin;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
	return ;
}

int	is_empty_stack(t_stack *stack)
{
	if (stack->length == 0)
		return (1);
	return (0);
}

//remove this when pushing
void	print_stack(t_stack *stack)
{
	t_stacknode	*current;

	if (is_empty_stack(stack))
		printf("nothing to print\n");
	else
	{
		current = stack->begin;
		while (current)
		{
			printf("%d ", current->value);
			current = current->next;
		}
		printf("\n");
	}
}

t_stacknode	*create_new_node(int value)
{
	t_stacknode	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->back = NULL;
	return (node);
}
