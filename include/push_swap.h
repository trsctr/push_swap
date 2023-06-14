/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:03:32 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/14 17:35:36 by oandelin         ###   ########.fr       */
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

// OUTPUT

void	error(void);
void	print_move(char *move, char stack_id);

// INPUT

t_stack	*store_input(char **argv, int argc);
int		check_input(char **argv, int argc);
int		check_if_sorted(t_stack *stack);
int		check_duplicates(t_stack *stack);




// STACK

void	create_stack(t_stack **stack);
t_node	*ft_newnode(int data);
void	ft_addtotop(t_stack *stack, t_node *node);
void	ft_addtoend(t_stack *stack, t_node *node);
void	print_stack(t_stack *stack);
int		scan_stack(t_stack *stack, int data);

// MOVES

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *src, t_stack *dst);


#endif