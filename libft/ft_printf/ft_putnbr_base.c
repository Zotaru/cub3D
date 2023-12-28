/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:47:22 by amonier           #+#    #+#             */
/*   Updated: 2023/01/12 01:20:11 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	ft_putnbr_base(char *base, int para)
// {
// 	int	len;
// 	int	len_base;

// 	len_base = ft_strlen(base);
// 	len = 0;
// 	if (para < 0)
// 	{
// 		ft_putchar('-');
// 		len++;
// 		para = para * (-1);
// 	}
// 	if (para >= 0 && para < len_base)
// 	{
// 		ft_putchar(base[para]);
// 		len++;
// 	}
// 	else if (para >= len_base)
// 	{
// 		len += ft_putnbr_base(base, para / len_base);
// 		len += ft_putnbr_base(base, para % len_base);
// 	}
// 	return (len);
// }

unsigned int	ft_putnbr_base(unsigned int n, int c, int *length)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, c, length);
	ft_putchar(HEXA[n % 16 + c * 16]);
	return (*length += 1);
}
