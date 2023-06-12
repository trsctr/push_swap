/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:03:32 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/12 17:31:17 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"

typedef struct s_stack {
	void	*data;
	int		place;
	int		stack_size;
	struct t_stack *prev;
	struct t_stack *next;
} t_stack;



// OUTPUT

void	error(void);
void	print_move(char *move);

// INPUT

int store_input(char **argv, int argc);
int check_input(char **argv, int argc);

#endif