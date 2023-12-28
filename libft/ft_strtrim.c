/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:08:15 by amonier           #+#    #+#             */
/*   Updated: 2022/11/23 23:00:42 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int	ft_check(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_start(char *set, char *s1)
{
	int	i;

	i = 0;
	while (ft_check(set, s1[i]) == 1 && s1[i])
		i++;
	return (i);
}

static int	ft_check_last(char *set, char *s1)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_check(set, s1[i]) == 1 && s1[i])
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	start = ft_check_start((char *)set, (char *)s1);
	end = ft_check_last((char *)set, (char *)s1);
	if (start > end)
		return (ft_calloc(1, 1));
	str = malloc((end - start + 1 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char *str = "231jour comment vas tu ?111";
	char *set = "123";
	char *fin;

	fin = ft_strtrim(str, set);
	printf("%s", fin);	
	free(fin);
}*/
