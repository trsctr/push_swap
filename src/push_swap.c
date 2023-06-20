/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:28:33 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/20 17:26:08 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	if (argc < 3)
		error();
	if (check_input(argv, argc))
		error();
	stack_a = store_input(argv, argc);
	create_stack(&stack_b);
		// print_stack(stack_a);

	stack_b->stack_id = 'b';
	if (stack_a->size == 3)
		sort_three(stack_a);
	print_stack(stack_a);
// 	reverse_rotate(stack_a);
// 	print_stack(stack_a);
// 	swap(stack_a);
// 	print_stack(stack_a);
// 	rotate(stack_a);
// 	print_stack(stack_a);
// 	push(stack_a, stack_b);
// 	//print_stack(stack_b);
// 	push(stack_a, stack_b);
// 	push(stack_a, stack_b);
// 	//print_stack(stack_b);
// 	//push(stack_b, &stack_a);
// 	reverse_rotate(stack_b);
// 	print_stack(stack_a);
	//print_stack(stack_b);
// 	push(stack_b, stack_a);
// 	print_stack(stack_a);
// 	print_stack(stack_b);
	

// //	print_move(argv[2]);
}

