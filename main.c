/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:42 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 11:30:23 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_quartils	*quartils;
	int			*number_array;

	number_array = malloc((argc - 1) * sizeof(int));
	if (!number_array)
		exit(1);
	a = malloc(sizeof(*a));
	if (!a)
	{
		free(number_array);
		exit(1);
	}
	b = malloc(sizeof(*b));
	if (!b)
	{
		free(number_array);
		clear_stack(&a);
		exit(1);
	}
	if (parse(argc, argv, number_array, &a))
	{
		free(number_array);
		clear_stack(&a);
		clear_stack(&b);
		exit(1);
	}
	quick_sort(a->begin, a->end);
	quartils = get_quartils(a);
	if (!quartils)
	{
		free(number_array);
		clear_stack(&a);
		exit(1);
	}
	clear_stack(&a);
	if (parse(argc, argv, number_array, &a))
	{
		free(number_array);
		free(quartils);
		exit(1);
	}
	free(number_array);
	//error done above
	push_swap(&a, &b, quartils);
	print_stack(a);
	clear_stack(&a);
	clear_stack(&b);
	free(quartils);
	return (0);
}
