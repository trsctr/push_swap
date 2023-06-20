/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:32:51 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/20 16:47:57 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->end->data < stack->top->data)
	{	
		rotate(stack);
		sort_three(stack);
	}
	if (stack->top->data > stack->top->next->data)
	{
		swap(stack);
		sort_three(stack);
	}
	// if (stack->top->next->data < stack->end->data)
		
}



// 5
// 2
// 3