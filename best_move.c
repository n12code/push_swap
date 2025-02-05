/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:44:58 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 10:01:48 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_move(t_stack *a, t_stack *b, int b_node_value)
{
	int	move_a;
	int	move_b;
	int	pos_b;
	int	pos_a;

	pos_b = find_pos(b, b_node_value);
	pos_a = find_pos_a(a, b_node_value);
	move_b = 1;
	move_a = 1;
	if (pos_b > 1 && pos_b > (b->length / 2))
		move_b += b->length - pos_b - 1;
	else if (pos_b > 1 && pos_b <= (b->length / 2))
		move_b += pos_b - 1;
	if (pos_a > 1 && pos_a > (a->length / 2))
		move_a += a->length - pos_a - 1;
	else if (pos_a > 1 && pos_a <= (a->length / 2))
		move_a += pos_a - 1;
	return (move_a + move_b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_best_move(t_stack *a, t_stack *b)
{
	int			best_b_node_value;
	int			nb_move;
	int			best_nb_move;
	t_stacknode	*current;

	best_b_node_value = b->begin->value;
	best_nb_move = count_move(a, b, best_b_node_value);
	current = b->begin->next;
	while (current)
	{
		nb_move = count_move(a, b, current->value);
		if (nb_move < best_nb_move)
		{
			best_nb_move = nb_move;
			best_b_node_value = current->value;
		}
		current = current->next;
	}
	return (best_b_node_value);
}
