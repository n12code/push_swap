/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:36:39 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/06 09:37:05 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	*malloc_three(t_stack **a, t_stack **b, int argc)
{
	int	*number_array;

	number_array = malloc((argc - 1) * sizeof(int));
	if (!number_array)
		print_and_exit();
	*a = malloc(sizeof(**a));
	if (!(*a))
	{
		free(number_array);
		print_and_exit();
	}
	(*a)->length = 0;
	(*a)->begin = NULL;
	(*a)->end = NULL;
	(*b) = malloc(sizeof(**b));
	if (!(*b))
	{
		free(number_array);
		clear_stack(a);
		print_and_exit();
	}
	(*b)->length = 0;
	(*b)->begin = NULL;
	(*b)->end = NULL;
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
	print_and_exit();
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
