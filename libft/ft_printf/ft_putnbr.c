/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:14:58 by amonier           #+#    #+#             */
/*   Updated: 2023/01/25 22:44:38 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_putnbr(int n, int *length)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
		*length += 1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, length);
	}
	ft_putchar(BASE_10[nb % 10]);
	return (*length += 1);
}
