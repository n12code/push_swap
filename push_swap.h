/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:43:33 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/04 10:53:57 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdio.h>//remove

//set it to t_stacknode
typedef struct StackNode
{
	int					value;
	struct StackNode	*next;
	struct StackNode	*back;	
}						StackNode;

//set it to size_t and and t_stack
typedef struct Stack
{
	int					length;
	struct StackNode	*begin;
	struct StackNode	*end;
}						Stack;

//set it to t_quartils
typedef struct Quartils
{
	int					q1;
	int					med;
	int					q3;
}						Quartils;

int			is_digit(char *str);
int			ft_atoi(const char *str);
int			is_not_overflow(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			parse(int nb_of_elements, char **input, int number_array[nb_of_elements], Stack **a);
int			check_duplicates(size_t nb_of_elements, int number_array[nb_of_elements]);
int			create_array(size_t nb_of_elements, char **input, int number_array[nb_of_elements]);
void		create_stack_from_array(Stack **a, size_t nb_of_elements, int number_array[nb_of_elements]);
size_t		ft_strlen(char *str);

void		swap_nodes(StackNode *top, StackNode *bottom);
void		quick_sort(StackNode *top, StackNode *bottom);
StackNode 	*partition(StackNode *top, StackNode *bottom);

int			middle_quartils(Stack *stack, Quartils *quartils);
void		get_median(Stack *a, Quartils **quartils, int med_index);
void 		get_first_quartil(Stack *a, Quartils **quartils, int q1_index);
void		get_third_quartil(Stack *a, Quartils **quartils, int q3_index);
Quartils	*get_quartils(Stack *a);

void		bring_min_to_top(Stack **a);
void		handle_three(Stack **a);
void		push_back_into_a(Stack **a, Stack **b);
void		push_swap(Stack **a, Stack **b, Quartils *quartils);
void		push_quartils(Stack **a, Stack **b, Quartils *quartils);

int			find_best_move(Stack *a, Stack *b);
int			count_move(Stack *a, Stack*b, int b_node_value);

int			find_max(Stack *stack);
int			find_min(Stack *stack);
int			find_pos_a(Stack *a, int node_value);
int			find_pos(Stack *stack, int node_value);

int			optimize_moves(Stack **a, Stack **b, int a_pos, int b_pos);
void		bring_a_to_pos(Stack **a, int a_pos);
void		bring_b_to_pos(Stack **b, int b_pos);
void		insert_in_a(Stack **a, Stack **b, int best_b_node_value);
int			is_sorted(Stack *stack);


int			is_empty_stack(Stack *stack);
void		print_stack(Stack *stack);
void		print_stack(Stack *stack);//remove
void		clear_stack(Stack **stack);
void		push_stack_top(Stack **stack, StackNode *node);
void		push_stack_bottom(Stack **stack, StackNode *node);
StackNode	*create_new_node(int value);
StackNode	*remove_stack_top(Stack **stack);
StackNode	*remove_stack_bottom(Stack **stack);

void		swap_a(Stack **a);
void		swap_b(Stack **b);
void		push_a(Stack **a, Stack **b);
void		push_b(Stack **a, Stack **b);
void		swap_both(Stack **a, Stack **b);
void		rotate_a(Stack **a);
void		rotate_b(Stack **b);
void		rotate_both(Stack **a, Stack **b);
void		reverse_rotate_a(Stack **a);
void		reverse_rotate_b(Stack **b);
void		reverse_rotate_both(Stack **a, Stack **b);

#endif