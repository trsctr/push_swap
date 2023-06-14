/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:41:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/14 17:02:09 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*newtop;
	t_node	*oldtop;

	if (stack->size == 1)
		return ;
	oldtop = stack->top;
	newtop = oldtop->next;
	oldtop->next = newtop->next;
	stack->top = newtop;
	newtop->next = oldtop;
	newtop->place = 0;
	oldtop->place = 1;
	print_move("s", stack->stack_id);
}

void	rotate(t_stack *stack)
{
	t_node	*newtop;
	t_node	*oldtop;
	t_node	*temp;

	if (stack->size == 0)
		return ;
	oldtop = stack->top;
	newtop = oldtop->next;
	stack->top = newtop;
	oldtop->prev = stack->end;
	stack->end->next = oldtop;
	oldtop->next = NULL;
	temp = stack->top;
	while (temp->next != NULL)
	{
		temp->place -= 1;
		temp = temp->next;
	}
	stack->end = temp;
	temp->place = stack->size - 1;
	print_move("r", stack->stack_id);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*newtop;
	t_node	*oldtop;
	t_node	*temp;

	oldtop = stack->top;
	newtop = stack->end;
	stack->end = newtop->prev;
	newtop->prev = NULL;
	newtop->place = 0;
	stack->end->next = NULL;
	oldtop->prev = newtop;
	newtop->next = oldtop;
	stack->top = newtop;
	temp = stack->top;
	while (temp->next != NULL)
	{
		temp = temp->next;
		temp->place += 1;
	}
	print_move("rr", stack->stack_id);
}

void	push(t_stack *src, t_stack *dst)
{
	t_node *temp;
	t_node *curr;
	
	temp = src->top;
	src->top = temp->next;
	temp->next = NULL;
	src->size -= 1;
	ft_addtotop(dst, temp);
	curr = src->top;
	curr->place -= 1;
	while (curr->next != NULL)
	{
		curr = curr->next;
		curr->place -= 1;
	}
	print_move("p", src->stack_id);
}

/* moves:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.*/