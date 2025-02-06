/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:42 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:52:39 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	a->begin = NULL;
	a->end = NULL;
	if (parse(argc, argv, number_array, &a))
		free_ressources(a, b, number_array, quartils);
	free(number_array);
	push_swap(&a, &b, quartils);
	clear_stack(&a);
	clear_stack(&b);
	free(quartils);
	return (0);
}
