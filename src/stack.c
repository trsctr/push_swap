/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:34:25 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/03 15:00:34 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_stack(t_stack **stack)
{
	*stack = ft_calloc(1, sizeof(t_stack));
}

t_node	*ft_newnode(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_addtoend(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->top = node;
		stack->end = node;
	}
	else
	{
	stack->end->next = node;
	node->prev = stack->end;
	stack->end = node;
	}
	stack->size += 1;
	node->place = stack->size - 1;
}

void	ft_addtotop(t_stack *stack, t_node *node)
{
	t_node	*temp;

	if (stack->size == 0)
	{
		stack->top = node;
		stack->end = node;
	}
	else
	{
	stack->top->prev = node;
	node->next = stack->top;
	stack->top = node;
	}
	stack->size += 1;
	node->place = 0;
	temp = stack->top;
	while (temp->next != NULL)
	{
		temp = temp->next;
		temp->place += 1;
	}
}
