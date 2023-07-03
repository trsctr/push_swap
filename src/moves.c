/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:41:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/03 14:58:28 by oandelin         ###   ########.fr       */
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
	newtop = stack->top->next;
	oldtop->next = newtop->next;
	stack->top = newtop;
	stack->top->next = oldtop;
	newtop->place = 0;
	oldtop->place = 1;
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
	oldtop->next = stack->top->next;
	oldtop->prev = newtop;
	stack->top = newtop;
	stack->top->next = oldtop;
	temp = stack->top;
	while (temp->next != NULL)
	{
		temp = temp->next;
		temp->place += 1;
	}
}

void	push(t_stack *src, t_stack *dst)
{
	t_node	*temp;
	t_node	*curr;

	temp = src->top;
	src->top = temp->next;
	temp->next = NULL;
	src->size -= 1;
	ft_addtotop(dst, temp);
	if (src->size > 1)
	{
		curr = src->top;
		curr->place -= 1;
		while (curr->next != NULL)
		{
			curr = curr->next;
			curr->place -= 1;
		}
	}
}
