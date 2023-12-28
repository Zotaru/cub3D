/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:42:01 by amonier           #+#    #+#             */
/*   Updated: 2022/11/13 22:09:21 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbl;
	char		c;

	nbl = n;
	if (nbl < 0)
	{
		write(fd, "-", 1);
		nbl *= (-1);
	}
	if (nbl >= 0 && nbl <= 9)
	{
		c = '0' + nbl;
		write(fd, &c, 1);
		return ;
	}
	else if (nbl >= 10)
	{
		ft_putnbr_fd(nbl / 10, fd);
		ft_putnbr_fd(nbl % 10, fd);
	}
	return ;
}
