/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:28:22 by amonier           #+#    #+#             */
/*   Updated: 2022/11/23 22:58:36 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int	ft_putnbr_count(long long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9)
	{
		count++;
		return (count);
	}
	else if (nb >= 10)
	{
		count += ft_putnbr_count(nb / 10);
		count += ft_putnbr_count(nb % 10);
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*dest;
	long long	nbl;

	nbl = n;
	len = ft_putnbr_count(nbl);
	dest = ft_calloc((len + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (nbl < 0)
	{
		nbl = nbl * (-1);
		dest[0] = '-';
	}
	dest[len] = '\0';
	len--;
	while (len != (-1) && dest[len] != '-')
	{
		dest[len] = '0' + (nbl % 10);
		nbl = nbl / 10;
		len--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	*result;

	result = ft_itoa(-2147483648);
	printf("%s", result);
	free(result);
}*/
