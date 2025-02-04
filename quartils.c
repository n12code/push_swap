/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:42 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:52:50 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

//re-check the system to get the quartils, need to be more precise
Quartils *get_quartils(Stack *a)
{
	int			q1_index;
	int			med_index;
	int			q3_index;
	Quartils 	*quartils;
	
	quartils = malloc(sizeof(*quartils));
	if (!quartils)
		return (NULL);
	if (a->length % 2 == 0)
		med_index = a->length / 2;
	else
		med_index = (a->length + 1) / 2;
	q1_index = (med_index + 1) / 2;
	if (med_index % 2 == 0)
		q1_index = med_index / 2;
	q3_index = med_index + q1_index;
	get_first_quartil(a, &quartils, q1_index);
	get_median(a, &quartils, med_index);
	get_third_quartil(a, &quartils, q3_index);
	return quartils;
}

void get_first_quartil(Stack *a, Quartils **quartils, int q1_index)
{
	int			i;
	StackNode	*current;
	StackNode	*next;

	i = 0;
	current = a->begin;
	while (current)
	{
		next = current->next;
		if (i == q1_index - 1)
		{
			(*quartils)->q1 = current->value;
			return ;
		}
		current = next;
		i++;
	}
}

void get_median(Stack *a, Quartils **quartils, int med_index)
{
	int			i;
	StackNode	*current;
	StackNode	*next;

	i = 0;
	current = a->begin;
	while (current)
	{
		next = current->next;
		if (i == med_index - 1)
		{
			(*quartils)->med = current->value;
			return ;
		}
		current = next;
		i++;
	}
}

void get_third_quartil(Stack *a, Quartils **quartils, int q3_index)
{
	int			i;
	StackNode	*current;
	StackNode	*next;

	i = 0;
	current = a->begin;
	while (current)
	{
		next = current->next;
		if (i == q3_index - 1)
		{
			(*quartils)->q3 = current->value;
			return ;
		}
		current = next;
		i++;
	}
}

int	still_medium_quartils(Stack *a, Quartils *quartils)
{
	StackNode *current;
	StackNode *next;
	
	current = a->begin;
	while (current)
	{
		next = current->next;
		if (quartils->q1 <= current->value && current->value <= quartils->q3)
			return (1);
		current = next;
	}
	return (0);	
}