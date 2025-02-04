/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:42 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:51:13 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	Stack		*a;
	Stack		*b;
	Quartils 	*quartils;
	int			number_array[argc - 1];
	
	a = NULL;
	b = NULL;
	if (parse(argc, argv, number_array, &a))
		return (1);
	quick_sort(a->begin, a->end);
	quartils = get_quartils(a);
	clear_stack(&a);
	if (parse(argc, argv, number_array, &a))
		return (1);
	push_swap(&a, &b, quartils);
	clear_stack(&a);
	clear_stack(&b);
	return (0);	
}