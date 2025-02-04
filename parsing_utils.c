/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:01:07 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:52:37 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int		check_duplicates(size_t nb_of_elements, int number_array[nb_of_elements])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < nb_of_elements)
	{
		j = i + 1;
		while (j < nb_of_elements)
		{
			if (number_array[i] == number_array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if ((str[i + 1] > '9' || str[i + 1] < '0') || i != 0)
				return (0);
		}
		else if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && n - 1
		&& (unsigned char) s1[i] == (unsigned char) s2[i])
	{
		i++;
		n--;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}


//re-check this function
int	is_not_overflow(char *str)
{
	char	*limit;

	if (str[0] ==  '-')
		limit = "2147483648";
	else
		limit = "2147483647";
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) == 10 && ft_strncmp(str, limit, 10) > 0)
		return (0);
	return (1);		
}