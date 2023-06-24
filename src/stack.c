/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:34:25 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/24 17:13:05 by oandelin         ###   ########.fr       */
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

int	scan_stack(t_stack *stack, int data)
{
	t_node	*curr;
	int		count;

	count = 0;
	curr = stack->top;
	while (curr->next != NULL)
	{
		if (data == curr->data)
			count++;
		curr = curr->next;
	}
	if (data == curr->data)
			count++;
	if (count > 1)
		return (1);
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_node *curr;

	ft_printf("stack id: %c, stack size %d\n", stack->stack_id, stack->size);
	if (stack->size == 0)
		return;
	curr = stack->top;
	ft_printf("node place %d, node content: %d\n", curr->place, curr->data);
	while (curr->next != NULL)
	{
		curr = curr->next;
		ft_printf("node place %d, node content: %d\n", curr->place, curr->data);
	}

}

void destroy_stack(t_stack *stack)
{
	t_node *curr;
	t_node *temp;

	curr = stack->top;
	while(curr->next)
	{
		temp = curr;
		free(temp);
		curr = curr->next;
	}
	free(stack->end);
	free(stack);
}
