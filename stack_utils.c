/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:47 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:51:36 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	clear_stack(Stack **stack)
{
	StackNode	*current;
	StackNode	*next;

	if (is_empty_stack(*stack))
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

int	is_empty_stack(Stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

//remove this when pushing
void	print_stack(Stack *stack)
{
	StackNode	*current;

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

StackNode	*create_new_node(int value)
{
	StackNode	*node;
	
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->back = NULL;
	return (node);
}