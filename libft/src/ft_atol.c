/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:01:48 by oandelin          #+#    #+#             */
/*   Updated: 2023/06/22 18:11:51 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_atol
//	converts ascii input *str to a long and returns the long value
long	ft_atol(const char *str)
{
	int		i;
	long	res;
	long	dig;
	long	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		dig = str[i] - 48;
		res = res * 10 + dig;
		i++;
	}
	return (res * sign);
}
