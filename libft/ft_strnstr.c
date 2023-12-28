/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:15:44 by amonier           #+#    #+#             */
/*   Updated: 2022/11/19 19:09:17 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	if (big == NULL && len == 0)
		return (NULL);
	i = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (*big && (i + len_little - 1) < len)
	{
		if (!ft_strncmp(big, little, len_little))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
/*
int	main (void)
{
	char	*s;
	char	*in;
	char	*res;

	s = "je suis un genie";
	in = "suis";
	res = ft_strnstr(s, in, 6);
	printf("%s", res);
}*/
