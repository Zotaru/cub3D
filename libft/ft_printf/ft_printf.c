/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:42:29 by amonier           #+#    #+#             */
/*   Updated: 2023/01/25 23:04:00 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	if (str == NULL)
	{
		length += ft_putstr("(null)");
	}
	else
	{
		while (str[length])
		{
			write(1, &str[length], 1);
			length++;
		}
	}
	return (length);
}

int	ft_conversion(va_list ptr, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar((char) va_arg(ptr, int));
	else if (c == 's')
		length += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		length += ft_print_ptr(va_arg(ptr, unsigned long long));
	else if (c == 'd')
		ft_putnbr(va_arg(ptr, int), &length);
	else if (c == 'i')
		ft_putnbr(va_arg(ptr, int), &length);
	else if (c == 'u')
		ft_putnbr_u(va_arg(ptr, unsigned int), &length);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(ptr, unsigned int), (c == 'X'), &length);
	else if (c == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		length;

	i = 0;
	length = 0;
	if (str == NULL)
		return (0);
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_conversion(ptr, str[i + 1]);
			i += 2;
		}
		else
		{
			length += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ptr);
	return (length);
}
