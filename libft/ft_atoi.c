/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:18:58 by amonier           #+#    #+#             */
/*   Updated: 2022/11/15 16:03:36 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int	ft_atoi(const char *string)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	i = 0;
	sign = 1;
	while ((string[i] >= 9 && string[i] <= 13) || string[i] == 32)
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign *= (-1);
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		res = res * 10 + string[i] - '0';
		i++;
	}
	return (res * sign);
}
