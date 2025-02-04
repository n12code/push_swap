/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:44:58 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:56:49 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_move(Stack *a, Stack *b, int b_node_value)
{
	int	move;
	int	pos_b;
	int	pos_a;

	pos_b = find_pos(b, b_node_value);
	pos_a = find_pos_a(a, b_node_value);
	move = 1;
	if (pos_b > 1 && pos_b > (b->length / 2))
		move += b->length - pos_b - 1;
	else if (pos_b > 1 && pos_b <= (b->length / 2))
		move += pos_b - 1;
	if (pos_a > 1 && pos_a > (a->length / 2))
		move += a->length - pos_a - 1;
	else if (pos_a > 1 && pos_a <= (a->length / 2))
		move += pos_a - 1;
	return (move);
}

int	find_best_move(Stack *a, Stack *b)
{
	int			best_b_node_value;
	int			nb_move;
	int			best_nb_move;
	StackNode	*current;

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