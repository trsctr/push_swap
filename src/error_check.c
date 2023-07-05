/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:33:00 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/05 13:24:16 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
			i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	valid_string(char **input)
{
	int	arg;
	int	digit;

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

int	valid_args(char **argv, int argc)
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
			return (-1);
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

int	has_duplicates(t_stack *stack)
{
	int		temp;
	t_node	*curr;

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
