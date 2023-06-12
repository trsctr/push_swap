/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:15:01 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/12 17:39:28 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	store_input(char **argv, int argc)
{
	int	*nums;
	int	counter;
	int	i;

	nums = NULL;
	counter = 1;
	i = 0;
	// tee stackista ihan linked list eika array
	// just a sketch fn
	nums = malloc(sizeof(int) * argc);
	while (counter < argc)
	{
		nums[i] = ft_atoi(argv[counter]);
		i++;
		counter++;
	}
	i = 0;
	while (i < counter)
		ft_printf("%d\n", nums[i++]);
	free(nums);
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
		while (argv[arg][digit])
		{
			if (!ft_isdigit(argv[arg][digit]))
				return (-1);
			digit++;
		}
		arg++;
	}
	return(0);

	
}