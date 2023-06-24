/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:32:51 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/24 14:34:06 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->end->data < stack->top->data)
	{	
		move_ra_rb(stack);
		sort_three(stack);
	}
	else if (stack->top->data > stack->top->next->data)
	{
		move_sa_sb(stack);
		sort_three(stack);
	}
	else if (stack->top->next->data > stack->end->data)
	{
		move_rra_rrb(stack);
		sort_three(stack);
	}
//	if(check_if_sorted(stack))
//		exit(0);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int min;

	if (stack_b->size > 0)
		min = stack_b->size + 1;
	else min = 1;
	if (check_if_sorted(stack_a))
	 	return ;
	if (stack_a->top->data == min)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (stack_a->top->next->data == min)
	{
		move_sa_sb(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (stack_a->end->data == min)
	{
		move_rra_rrb(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else
	{
		move_rra_rrb(stack_a);
		sort_four(stack_a, stack_b);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if(check_if_sorted(stack_a))
			exit(0);
	if (stack_a->top->data == 1)
	{
		push(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		push(stack_b, stack_a);
	}
	else if (stack_a->top->next->data == 1)
	{
		move_sa_sb(stack_a);
		if(check_if_sorted(stack_a))
			return ;
		else sort_five(stack_a, stack_b);
	}
	else if (stack_a->end->data == 1)
	{
		move_rra_rrb(stack_a);
		if(check_if_sorted(stack_a))
			return ;
		else sort_five(stack_a, stack_b);
	}
	else
	{
		move_ra_rb(stack_a);
		sort_five(stack_a, stack_b);
	}
	if(check_if_sorted(stack_a))
		return ;
}

// 	if(stack_a->size == 3)
// 	{
// 		sort_three(stack_a);
// 		pa(stack_a, stack_b);
// 	}
// 	if (stack_a->top->data == 1 || stack_a->top->data == 2)
//  	{
// 		pb(stack_a, stack_b);
// 		sort_five(stack_a, stack_b);
// 	}
// 	// else if (stack_a->end->data == 1 || stack_a->end->data == 2)
// 	// {
// 	// 	move_rra_rrb(stack_a);
// 	// 	pb(stack_a, stack_b);
// 	// 	sort_four(stack_a, stack_b);
// 	// }
// 	// else 
// 	// {
// 	// 	move_ra_rb(stack_a);
// 	// 	sort_five(stack_a, stack_b);
// 	// }
	
// }

// }


// void radix(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node *curr;
// 	int num;
// 	int	maxnum;
// 	int bit;

// 	bit = 0;	
// 	maxnum = stack_a->size / 2;
// 	curr = stack_a->top;
// 	num = 1;
// 	while(num < maxnum)
// 	{
// 		if ((curr->data >> bit & 1) == 1)
// 		{
// 			ft_printf("%d", curr->data >> bit & 1);
// 			move_ra_rb(stack_a);
// 			curr = stack_a->top;
// 		}
// 		else
// 			ft_printf("%d", curr->data >> bit & 1);
// 			push(stack_a, stack_b);
// 			curr = stack_a->top;
// 		num++;
// 	}
// 	ft_printf("%d", num);
// }








// {
// 	if (stack_a->top->data == 1)
// 	{
// 		push(stack_a, stack_b);
// 		sort_four(stack_a, stack_b);
// 		push(stack_b, stack_a);
// 	}
// 	else if (stack_a->top->next->data == 1)
// 	{
// 		move_sa_sb(stack_a);
// 		if(check_if_sorted(stack_a))
// 			return ;
// 		else sort_five(stack_a, stack_b);
// 	}
// 	else if (stack_a->end->data == 1)
// 	{
// 	ft_putchar_fd('!', 1);
// 		move_rra_rrb(stack_a);
// 		if(check_if_sorted(stack_a))
// 			return ;
// 		else sort_five(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		move_ra_rb(stack_a);
// 		sort_five(stack_a, stack_b);
// 	}
// 	if(check_if_sorted(stack_a))
// 		return ;
// }

// 5
// 2
// 3