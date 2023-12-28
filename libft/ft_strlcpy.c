/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:22:51 by amonier           #+#    #+#             */
/*   Updated: 2022/11/20 17:42:01 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
//#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;
	size_t	dstsize;

	srcsize = ft_strlen(src);
	if (!src || !dst || size == 0)
		return (srcsize);
	dstsize = size;
	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (srcsize);
}
/*
int main()
{
	char *str;
	
	str = malloc(sizeof(char) * 17);
	printf("%ld",strlcpy(str, "lalalalallalalalal", 0));
	printf("%s", str);
}*/
