/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:14:15 by amonier           #+#    #+#             */
/*   Updated: 2023/01/25 22:53:11 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_putnbr_base_ptr(unsigned long long ptr, int *length)
{
	if (ptr >= 16)
		ft_putnbr_base_ptr(ptr / 16, length);
	ft_putchar(HEXA[ptr % 16]);
	return (*length += 1);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	if (ptr == 0)
	{
		length = ft_putstr("(nil)");
		return (length);
	}
	length = ft_putstr("0x");
	ft_putnbr_base_ptr(ptr, &length);
	return (length);
}
