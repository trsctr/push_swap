/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:03:32 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/04 17:10:26 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"

typedef struct s_node {
	int				data;
	int				place;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	char			stack_id;
	int				size;	
	struct s_node	*top;
	struct s_node	*end;
}	t_stack;

// INPUT HANDLING

t_stack	*store_input(char **argv, int argc);
void	store_input_from_string(t_stack *stack, char *input);
void	store_input_from_args(t_stack *stack, char **argv, int argc);
int		valid_args(char **argv, int argc);
int		is_sorted(t_stack *stack);
int		has_duplicates(t_stack *stack);
int		valid_string(char **input);
int		is_empty_string(char *str);

// INPUT CONVERSION

void	convert_input(t_stack *stack);
int		get_index(int value, int *numbers, int size);
void	store_numbers(t_stack *stack, int *numbers);
void	sort_numbers(int *numbers, int size);
void	update_indices(t_stack *stack, int *numbers);
void	swap_ints(int *a, int *b);

// STACK

void	create_stack(t_stack **stack);
t_node	*ft_newnode(int data);
void	ft_addtotop(t_stack *stack, t_node *node);
void	ft_addtoend(t_stack *stack, t_node *node);

// STACK UTILS
void	print_stack(t_stack *stack);
int		scan_stack(t_stack *stack, int data);
void	destroy_stack(t_stack *stack);

// SORTING

void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit, int maxnum);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

// MOVES

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *src, t_stack *dst);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	move_sa_sb(t_stack *stack);
void	move_ra_rb(t_stack *stack);
void	move_rra_rrb(t_stack *stack);

// OUTPUT

void	error(void);
void	print_move(char *move, char stack_id);

#endif