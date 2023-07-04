/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:28:33 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/04 19:59:55 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 0;
	if (argc < 2)
		exit(0);
	if (argc == 2 && is_empty_string(argv[1]))
		exit(0);
	stack_a = store_input(argv, argc);
	create_stack(&stack_b);
	stack_b->stack_id = 'b';
	if (stack_a->size < 4)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	destroy_stack(stack_a);
	free(stack_b);
}
