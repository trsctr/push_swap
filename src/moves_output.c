/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:57:41 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/03 14:59:14 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	print_move("p", 'a');
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	print_move("p", 'b');
}

void	move_sa_sb(t_stack *stack)
{
	swap(stack);
	print_move("s", stack->stack_id);
}

void	move_ra_rb(t_stack *stack)
{
	rotate(stack);
	print_move("r", stack->stack_id);
}

void	move_rra_rrb(t_stack *stack)
{
	reverse_rotate(stack);
	print_move("rr", stack->stack_id);
}
