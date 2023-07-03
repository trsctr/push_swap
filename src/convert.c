/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:31:37 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/03 14:44:05 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	store_numbers(t_stack *stack, int *numbers)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack->top;
	while (curr->next != NULL)
	{
		numbers[i++] = curr->data;
		curr = curr->next;
	}
	numbers[i] = curr->data;
}

void	sort_numbers(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
				swap_ints(&numbers[j], &numbers[i]);
			j++;
		}
		i++;
	}
}

void	update_indices(t_stack *stack, int *numbers)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = stack->top;
	while (curr->next)
	{
		curr->data = get_index(curr->data, numbers, stack->size);
		curr = curr->next;
	}
	curr->data = get_index(curr->data, numbers, stack->size);
}

void	swap_ints(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	get_index(int value, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (value == numbers[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
