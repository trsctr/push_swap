/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:32:51 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/04 22:21:25 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack)
{
	while (!is_sorted(stack))
	{
		if (stack->end->data < stack->top->data)
			move_ra_rb(stack);
		else if (stack->top->data > stack->top->next->data)
			move_sa_sb(stack);
		else if (stack->top->next->data > stack->end->data)
			move_rra_rrb(stack);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	if (stack_b->size > 0)
		min = stack_b->size;
	else
		min = 0;
	while (!is_sorted(stack_a))
	{
		if (stack_a->top->data == min)
		{
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
		}
		else
			move_rra_rrb(stack_a);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_a->size == 5)
		exit(0);
	if (stack_a->top->data == 0)
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		if (is_sorted(stack_a) && stack_a->size == 5)
			exit(0);
	}
	if (stack_a->end->data == 0)
		move_rra_rrb(stack_a);
	while (stack_a->top->data != 0)
		move_ra_rb(stack_a);
	if (is_sorted(stack_a) && stack_a->size == 5)
		exit(0);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		maxnum;
	int		bit;

	bit = 0;
	maxnum = stack_a->size;
	while (bit < 16)
	{	
		if (is_sorted(stack_a) && stack_a->size == maxnum)
			return ;
		process_bit(stack_a, stack_b, bit, maxnum);
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		if (is_sorted(stack_a) && stack_a->size == maxnum)
			exit(0);
		bit++;
	}
	return ;
}

void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit, int maxnum)
{
	t_node	*curr;
	int		num;

	curr = stack_a->top;
	num = 1;
	while (num <= maxnum)
	{
		if ((curr->data >> bit & 1) == 1)
			move_ra_rb(stack_a);
		else
			pb(stack_a, stack_b);
		curr = stack_a->top;
		num++;
	}
	return ;
}
