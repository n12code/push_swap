/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:42 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:35:06 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_quartils	*get_quartils(t_stack *a, t_stack *b, int *number_array)
{
	int			q1_index;
	int			med_index;
	int			q3_index;
	t_quartils	*quartils;

	quartils = malloc(sizeof(*quartils));
	if (!quartils)
	{
		free(number_array);
		clear_stack(&a);
		clear_stack(&b);
		print_and_exit();
	}
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
	return (quartils);
}

void	get_first_quartil(t_stack *a, t_quartils **quartils, int q1_index)
{
	int			i;
	t_stacknode	*current;
	t_stacknode	*next;

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

void	get_median(t_stack *a, t_quartils **quartils, int med_index)
{
	int			i;
	t_stacknode	*current;
	t_stacknode	*next;

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

void	get_third_quartil(t_stack *a, t_quartils **quartils, int q3_index)
{
	int			i;
	t_stacknode	*current;
	t_stacknode	*next;

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

int	still_medium_quartils(t_stack *a, t_quartils *quartils)
{
	t_stacknode	*current;
	t_stacknode	*next;

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
