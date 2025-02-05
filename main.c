/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:42 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 17:38:31 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	*malloc_three(t_stack **a, t_stack **b, int argc)
{
	int	*number_array;

	number_array = malloc((argc - 1) * sizeof(int));
	if (!number_array)
		exit(1);
	*a = malloc(sizeof(**a));
	if (!(*a))
	{
		free(number_array);
		exit(1);
	}
	(*a)->length = 0;
	(*b) = malloc(sizeof(**b));
	if (!(*b))
	{
		free(number_array);
		clear_stack(a);
		exit(1);
	}
	(*b)->length = 0;
	return (number_array);
}

void	free_ressources(t_stack *a, t_stack *b, int *number_array,
		t_quartils *quartils)
{
	if (a)
		clear_stack(&a);
	if (b)
		clear_stack(&b);
	if (number_array)
		free(number_array);
	if (quartils)
		free(quartils);
	exit(1);
}


//remove printf, uneccesary libs, return Error\n on the error canal, test the checker_OS, see if i do the checker program
int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_quartils	*quartils;
	int			*number_array;

	number_array = malloc_three(&a, &b, argc);
	if (parse(argc, argv, number_array, &a))
		free_ressources(a, b, number_array, NULL);
	quick_sort(a->begin, a->end);
	quartils = get_quartils(a, b, number_array);
	clear_stack(&a);
	a = malloc(sizeof(*a));
	if (!a)
		free_ressources(NULL, b, number_array, quartils);
	a->length = 0;
	if (parse(argc, argv, number_array, &a))
		free_ressources(a, b, number_array, quartils);
	free(number_array);
	push_swap(&a, &b, quartils);
	print_stack(a);
	clear_stack(&a);
	clear_stack(&b);
	free(quartils);
	return (0);
}
