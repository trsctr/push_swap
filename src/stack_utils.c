/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:52:58 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/05 13:24:25 by oandelin         ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	int		temp;
	int		count;
	t_node	*curr;

	count = 0;
	curr = stack->top;
	temp = curr->data;
	while (curr->next != NULL)
	{
		curr = curr->next;
		if (curr->data > temp)
		{
			temp = curr->data;
			count++;
		}
	}
	if (curr->data > temp)
		count++;
	if (count == curr->place)
		return (1);
	return (0);
}

void	destroy_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*temp;

	curr = stack->top;
	while (curr->next)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(stack->end);
	free(stack);
}
