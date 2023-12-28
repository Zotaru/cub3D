/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:14:24 by amonier           #+#    #+#             */
/*   Updated: 2022/11/15 15:57:09 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, s);
		i++;
		s++;
	}
}
/*
void	fonction_test(unsigned int i, char *s)
{
	if(i % 2 == 0)
	{
		*s = 'A';
	}
}

int	main(int argc, char **argv)
{
	char	*res;

	if (argc != 2)
	{
		printf("wrong argument");
		return (0);
	}
	res = argv[1];
	ft_striteri(res, &fonction_test);
	printf("%s", res);
}*/
