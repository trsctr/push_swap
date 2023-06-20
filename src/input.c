/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:15:01 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/20 18:03:03 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*store_input(char **argv, int argc)
{
	t_stack	*stack;
	int		counter;

	counter = 1;
	create_stack(&stack);
	stack->stack_id = 'a';
	while (counter < argc)
	{
		ft_addtoend(stack, ft_newnode(ft_atoi(argv[counter])));
		counter++;
	}
	if (check_if_sorted(stack))
		error();
	if (check_duplicates(stack))
		error();
	convert_input(stack);
	return (stack);
}

int	check_input(char **argv, int argc)
{
	int	arg;
	int	digit;

	arg = 1;
	while (arg < argc)
	{
		digit = 0;
		if (argv[arg][0] == '-')
			digit++;
		while (argv[arg][digit])
		{
			if (!ft_isdigit(argv[arg][digit]))
				return (-1);
			digit++;
		}
		arg++;
	}
	return (0);
}

int check_if_sorted(t_stack *stack)
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

int check_duplicates(t_stack *stack)
{
	int temp;
	t_node *curr;

	curr = stack->top;
	while (curr->next != NULL)
	{
		temp = curr->data;
		if (scan_stack(stack, temp))
			return (1);
		curr = curr->next;
	}
	return (0);
}

void swap_ints(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

void convert_input(t_stack *stack)
{
	int numbers[stack->size + 1];
	int i;
	int j;
	t_node *curr;
	t_node *temp;
	//int min_idx;
	curr = stack->top;
	i = 0;
	while (curr->next != NULL)
	{
		numbers[i] = curr->data;
		i++;
		curr = curr->next;
	}
	numbers[i] = curr->data;
	i = 0;
	while (i < stack->size)
	{

		j = i + 1;
		while (j < stack->size)
		{
			if (numbers[i] > numbers[j])
				swap_ints(&numbers[j], &numbers[i]);
			j++;
		}
		i++;
	}
	i = 0;
	curr = stack->top;
	while (i <= stack->size)
	{
		j = i + 1;
		if(curr->data == numbers[i])
			curr->data = j;
		else 
		{	
			temp = curr;
			while(temp->next)
			{
				if(temp->data == numbers[i])
					temp->data = j;
				temp = temp->next;
			}
		}
		i++;
		if(curr->next)
			curr = curr->next;

	}
}
