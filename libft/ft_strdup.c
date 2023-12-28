/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:25:32 by amonier           #+#    #+#             */
/*   Updated: 2022/11/15 15:56:06 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int		l;
	int		i;

	l = ft_strlen(src);
	str = malloc((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*str;
	char	str2[5] = "abcde";
	str = ft_strdup(str2);
	printf("%s = %s",str2, str);
	free(str);
}*/
