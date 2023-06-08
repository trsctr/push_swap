/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:11:12 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/08 13:11:39 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	print_move(char *move)
{
	ft_printf("%s\n", move);
}
