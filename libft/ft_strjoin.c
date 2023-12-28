/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:23:49 by amonier           #+#    #+#             */
/*   Updated: 2022/11/20 18:51:43 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		ls1;
	int		ls2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	final = malloc((ls1 + ls2 + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	ls1 = -1;
	while (s1[++ls1])
		final[ls1] = s1[ls1];
	ls2 = -1;
	ls1--;
	while (s2[++ls2] && (++ls1 >= 0))
		final[ls1] = s2[ls2];
	final[ls1 + 1] = '\0';
	return (final);
}
/*
int main(void)
{
	char	*str1 = "\0orem ipsum";
	char	*str2 = "dolor sit amet";
	char	*fin;

	fin = ft_strjoin(str1, str2);
	printf("%s", fin);
	free(fin);
}*/
