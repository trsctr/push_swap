/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:15:01 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/04 21:24:47 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*store_input(char **argv, int argc)
{
	t_stack	*stack;

	create_stack(&stack);
	stack->stack_id = 'a';
	if (argc > 2)
	{	
		if (valid_args(argv, argc))
			error();
		store_input_from_args(stack, argv, argc);
	}
	else
	{
		store_input_from_string(stack, argv[1]);
	}
	if (is_sorted(stack))
		exit(0);
	if (has_duplicates(stack))
		error();
	convert_input(stack);
	return (stack);
}

void	store_input_from_args(t_stack *stack, char **argv, int argc)
{
	int		counter;
	long	num;

	counter = 1;
	while (counter < argc)
	{
		num = ft_atol(argv[counter]);
		if (num > INT_MAX || num < INT_MIN)
			error();
		ft_addtoend(stack, ft_newnode((int)num));
		counter++;
	}	
}

void	store_input_from_string(t_stack *stack, char *input)
{
	int		counter;
	char	**args;
	long	num;

	counter = 0;
	while (input[counter] == ' ')
		counter++;
	if (input[counter] == '\0')
		error();
	args = ft_split(input, ' ');
	if (valid_string(args))
		error();
	counter = 0;
	while (args[counter])
	{
		num = ft_atol(args[counter]);
		if (num > INT_MAX || num < INT_MIN)
			error();
		ft_addtoend(stack, ft_newnode((int)num));
		free(args[counter]);
		counter++;
	}
	free(args);
}

void	convert_input(t_stack *stack)
{
	int		*numbers;

	numbers = malloc(sizeof(int) * stack->size);
	store_numbers(stack, numbers);
	sort_numbers(numbers, stack->size);
	update_indices(stack, numbers);
	free(numbers);
}
