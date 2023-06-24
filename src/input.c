/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:15:01 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/24 21:13:19 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_stack	*store_input(char **argv, int argc)
{
	t_stack	*stack;
	char	**args;
	int		counter;
	long	num;
	int		i;

	i = 0;
	args = NULL;
	create_stack(&stack);
	stack->stack_id = 'a';
	if (argc > 2) 
	{	
		counter = 1;
		while (counter < argc)
		{
			num = ft_atol(argv[counter]);
			if(num > INT_MAX || num < INT_MIN)
				error();
			ft_addtoend(stack, ft_newnode((int)num));
			counter++;
		}
	}
	else
	{
		counter = 0;
		while(argv[1][i] == ' ')
			i++;
		if(argv[1][i] == '\0')
			error();
		args = ft_split(argv[1], ' ');
		if(another_error_check(args))
			error();
		while(args[counter])
		{
			num = ft_atol(args[counter]);
			if(num > INT_MAX || num < INT_MIN)
				error();
			ft_addtoend(stack, ft_newnode((int)num));
			free(args[counter]);
			counter++;
		}
	}
	free(args);
	if (check_if_sorted(stack))
		exit(0);
	if (check_duplicates(stack))
		error();
	convert_input(stack);
	return (stack);
}

int	another_error_check(char **input)
{
	int arg;
	int digit;

	arg = 0;
	while (input[arg])
	{
		digit = 0;
		if (input[arg][0] == '-')
			digit++;
		if (input[arg][digit] == '\0')
			return (-1);
		while (input[arg][digit])
		{
			if (!ft_isdigit(input[arg][digit]))
				return (-1);
			digit++;
		}
		arg++;
	}
	return (0);
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
		if (argv[arg][digit] == '\0')
			return(-1);
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

int set_index(int value, int *numbers, int size)
{
	int i;
	
	i = 0;
	while (i <= size)
	{
		if (value == numbers[i])
		{
			return(i);
		}
		i++;
	}
	return(-1);
}
void convert_input(t_stack *stack)
{
	int *numbers;
	int i;
	int j;
	t_node *curr;
	//int min_idx;

	numbers = malloc(sizeof(int)*stack->size);
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
	while (curr->next)
	{
		curr->data = set_index(curr->data, numbers, stack->size);
		curr = curr->next;
	}
	curr->data = set_index(curr->data, numbers, stack->size);
	free(numbers);
}

