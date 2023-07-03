/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:52:58 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/03 15:00:46 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	t_node	*curr;

	ft_printf("stack id: %c, stack size %d\n", stack->stack_id, stack->size);
	if (stack->size == 0)
		return ;
	curr = stack->top;
	ft_printf("node place %d, node content: %d\n", curr->place, curr->data);
	while (curr->next != NULL)
	{
		curr = curr->next;
		ft_printf("node place %d, node content: %d\n", curr->place, curr->data);
	}
}

void	destroy_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*temp;

	curr = stack->top;
	while (curr->next)
	{
		temp = curr;
		free(temp);
		curr = curr->next;
	}
	free(stack->end);
	free(stack);
}
