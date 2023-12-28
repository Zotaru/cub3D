/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:43:16 by amonier           #+#    #+#             */
/*   Updated: 2022/11/21 16:17:21 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	tab[3];

	if (!s)
		return (NULL);
	tab[0] = 0;
	tab[1] = (size_t)start;
	tab[2] = ft_strlen(s) - tab[1];
	if (ft_strlen(s) < tab[1])
	{
		dst = malloc(sizeof(char) * 1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (tab[2] > len)
		tab[2] = len;
	dst = malloc((tab[2] + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (s[tab[1]] && (tab[1] - (size_t)start) < tab[2])
		dst[tab[0]++] = s[tab[1]++];
	dst[tab[0]] = '\0';
	return (dst);
}
/*
int	main(void)
{
	char	*str = "bontab_i[0]our";
	char	*substr;

	substr = ft_substr(str, 5, 5);
	printf("%s", substr);
	free(substr);
}*/
