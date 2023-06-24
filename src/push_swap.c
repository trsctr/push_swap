/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:28:33 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/24 20:54:41 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(0);
	//
	//	error();
	if (argc > 2 && check_input(argv, argc))
		error();
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
		radix(stack_a, stack_b);
//	print_stack(stack_a);
	destroy_stack(stack_a);
	free(stack_b);
}

