/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:28:51 by amonier           #+#    #+#             */
/*   Updated: 2022/11/21 16:31:11 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char 	s[] = "012345";
	char	*rep = ft_memchr(s, 2 + 256, 3);
	printf("%s\n%s", rep, s + 2);
}*/
