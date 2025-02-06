/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:41 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:35:20 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacknode *top, t_stacknode *bottom)
{
	t_stacknode	*pivot;

	if (!top || !bottom || top == bottom)
		return ;
	pivot = partition(top, bottom);
	if (pivot && pivot != top)
		quick_sort(top, pivot->back);
	if (pivot && pivot != bottom)
		quick_sort(pivot->next, bottom);
}

t_stacknode	*partition(t_stacknode *top, t_stacknode *bottom)
{
	t_stacknode	*i;
	t_stacknode	*j;
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
	return (i);
}

void	swap_nodes(t_stacknode *top, t_stacknode *bottom)
{
	int	temp;

	temp = top->value;
	top->value = bottom->value;
	bottom->value = temp;
}
