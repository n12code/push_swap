/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:00:57 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 10:29:57 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	parse(int nb_of_elements, char **input, int *number_array, t_stack **a)
{
	if (nb_of_elements <= 1)
		return (1);
	if (create_array(nb_of_elements - 1, input, number_array))
		return (1);
	if (check_duplicates(nb_of_elements - 1, number_array))
		return (1);
	create_stack(a, nb_of_elements - 1, number_array);
	if (!(*a))
		return (1);
	return (0);
}

void	create_stack(t_stack **a, size_t nb_of_elements, int *number_array)
{
	t_stacknode	*node;
	size_t		i;

	i = 0;
	while (i < nb_of_elements)
	{
		node = create_new_node(number_array[i]);
		if (!node)
			return ;
		push_stack_bottom(a, node);
		if (!(*a))
			return ;
		i++;
	}
}

int	create_array(size_t nb_of_elements, char **input, int *number_array)
{
	size_t	i;
	long	number;

	i = 0;
	while (i < nb_of_elements)
	{
		if (is_digit(input[i + 1]))
		{
			number = ft_atol((const char *)input[i + 1]);
			if (number > INT_MAX || number < INT_MIN)
				return (1);
			number_array[i] = (int) number;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	size_t		i;
	long		nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * sign);
}
