/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:43:33 by nbodin            #+#    #+#             */
/*   Updated: 2025/02/05 17:31:41 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h> //remove

typedef struct StackNode
{
	int					value;
	struct StackNode	*next;
	struct StackNode	*back;
}						t_stacknode;

typedef struct Stack
{
	int					length;
	struct StackNode	*begin;
	struct StackNode	*end;
}						t_stack;

typedef struct Quartils
{
	int					q1;
	int					med;
	int					q3;
}						t_quartils;

void					free_ressources(t_stack *a, t_stack *b,
							int *number_array, t_quartils *quartils);
int						*malloc_three(t_stack **a, t_stack **b, int argc);

int						is_digit(char *str);
long					ft_atol(const char *str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						parse(int nb_of_elements, char **input,
							int *number_array, t_stack **a);
int						check_duplicates(size_t nb_of_elements,
							int *number_array);
int						create_array(size_t nb_of_elements, char **input,
							int *number_array);
void					create_stack(t_stack **a, size_t nb_of_elements,
							int *number_array);
size_t					ft_strlen(char *str);

void					swap_nodes(t_stacknode *top, t_stacknode *bottom);
void					quick_sort(t_stacknode *top, t_stacknode *bottom);
t_stacknode				*partition(t_stacknode *top, t_stacknode *bottom);

int						middle_quartils(t_stack *stack, t_quartils *quartils);
void					get_median(t_stack *a, t_quartils **quartils,
							int med_index);
void					get_first_quartil(t_stack *a, t_quartils **quartils,
							int q1_index);
void					get_third_quartil(t_stack *a, t_quartils **quartils,
							int q3_index);
t_quartils				*get_quartils(t_stack *a, t_stack *b,
							int *number_array);

void					bring_min_to_top(t_stack **a);
void					handle_three(t_stack **a);
void					push_swap(t_stack **a, t_stack **b,
							t_quartils *quartils);
void					push_quartils(t_stack **a, t_stack **b,
							t_quartils *quartils);

int						find_best_move(t_stack *a, t_stack *b);
int						count_move(t_stack *a, t_stack *b, int b_node_value);
int						ft_max(int a, int b);
int						ft_min(int a, int b);

int						find_max(t_stack *stack);
int						find_min(t_stack *stack);
int						find_pos_a(t_stack *a, int node_value);
int						find_pos(t_stack *stack, int node_value);

int						optimize_moves(t_stack **a, t_stack **b, int a_pos,
							int b_pos);
void					bring_a_to_pos(t_stack **a, int a_pos);
void					bring_b_to_pos(t_stack **b, int b_pos);
void					insert_in_a(t_stack **a, t_stack **b,
							int best_b_node_value);
int						is_sorted(t_stack *stack);

int						is_empty_stack(t_stack *stack);
void					print_stack(t_stack *stack);
void					print_stack(t_stack *stack); // remove
void					clear_stack(t_stack **stack);
void					push_stack_top(t_stack **stack, t_stacknode *node);
void					push_stack_bottom(t_stack **stack, t_stacknode *node);
t_stacknode				*create_new_node(int value);
t_stacknode				*remove_stack_top(t_stack **stack);
t_stacknode				*remove_stack_bottom(t_stack **stack);

void					swap_a(t_stack **a);
void					swap_b(t_stack **b);
void					push_a(t_stack **a, t_stack **b);
void					push_b(t_stack **a, t_stack **b);
void					swap_both(t_stack **a, t_stack **b);
void					rotate_a(t_stack **a);
void					rotate_b(t_stack **b);
void					rotate_both(t_stack **a, t_stack **b);
void					reverse_rotate_a(t_stack **a);
void					reverse_rotate_b(t_stack **b);
void					reverse_rotate_both(t_stack **a, t_stack **b);

#endif