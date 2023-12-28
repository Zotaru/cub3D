/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:15:14 by amonier           #+#    #+#             */
/*   Updated: 2023/01/25 22:46:20 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_putnbr_u(unsigned int n, int *length)
{
	unsigned long long	nb;

	nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10, length);
	ft_putchar(BASE_10[nb % 10]);
	return (*length += 1);
}
