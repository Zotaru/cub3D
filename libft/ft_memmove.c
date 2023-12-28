/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:23:39 by amonier           #+#    #+#             */
/*   Updated: 2022/11/19 05:57:44 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;
	int		n2;

	n2 = n;
	d = (char *)dest;
	s = (char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d > s)
	{
		while (--n2 >= 0)
			d[n2] = s[n2];
	}
	else
	{
		i = 0;
		while (i < n2)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
int    main(void)
{
    char    str[27]= "pure reason revolution";
    char str1[27] = "1234 12345 1234567891";
    ft_memmove(str, str1, 26);
    //str[0] = "avant";
    printf("%s\n", str);
    memmove(str, str1, 26);
    //str[0] = "avant";
    printf("%s\n", str);
    return (0);
}*/
