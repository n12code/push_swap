/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:41 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:52:53 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	quick_sort(StackNode *top, StackNode *bottom)
{
	StackNode	*pivot;
	
	if (!top || !bottom || top == bottom)
		return ;
	pivot = partition(top, bottom);
	if (pivot && pivot != top)
		quick_sort(top, pivot->back);
	if (pivot && pivot != bottom)
		quick_sort(pivot->next, bottom);
}

StackNode *partition(StackNode *top, StackNode *bottom)
{
	StackNode	*i;
	StackNode	*j;
	int			pivot;

	i = NULL;
	j = top;
	pivot = bottom->value;
	while (j)
	{
		if (j->value <= pivot)
		{
			if (!i)
				i = top;
			else
				i = i->next;
			swap_nodes(i, j);
		}
		j = j->next;
	}
	return i;
}

void	swap_nodes(StackNode *top, StackNode *bottom)
{
	int	temp;

	temp = top->value;
	top->value = bottom->value;
	bottom->value = temp;
}