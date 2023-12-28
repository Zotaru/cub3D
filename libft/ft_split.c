/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:10:42 by amonier           #+#    #+#             */
/*   Updated: 2022/11/23 22:59:35 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int	ft_count_word(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c && *str)
		{
			count++;
			while (*str != c && *str)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static int	*count_letters(int count_words, char *str, char c)
{
	int	j;
	int	nb_letters;
	int	*tab;

	j = 0;
	nb_letters = 0;
	tab = malloc((count_words) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (*str && j < count_words)
	{
		if (*str && *str != c)
		{
			while (*str && *str != c)
			{
				nb_letters++;
				str++;
			}
			tab[j++] = nb_letters;
			nb_letters = 0;
		}
		else
			str++;
	}
	return (tab);
}

static char	**alloc_case(char **tab, int *letters, char *str, char c)
{
	int	tabi[3];

	tabi[0] = 0;
	tabi[1] = 0;
	tabi[2] = ft_count_word(str, c);
	while (*str)
	{
		if (*str && *str != c)
		{
			tab[tabi[0]] = malloc((letters[tabi[0]] + 1) * sizeof(char));
			if (!tab[tabi[0]])
			{
				while (tabi[1] <= tabi[2])
					free(tab[tabi[1]++]);
				free(tab);
				return (NULL);
			}
			while (*str && *str != c)
				str++;
			tabi[0]++;
		}
		else
			str++;
	}
	return (tab);
}

static char	**remplissage(char **tab, char *str, char c)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (*str)
	{
		if (*str && *str != c)
		{
			while (*str && *str != c)
			{
				tab[j][k] = *str;
				str++;
				k++;
			}
			tab[j][k] = '\0';
			k = 0;
			j++;
		}
		else
			str++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;
	int		*letters;

	if (!s)
		return (NULL);
	count = ft_count_word((char *)s, c);
	tab = malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	letters = count_letters(count, (char *)s, c);
	if (letters == NULL)
		return (NULL);
	tab = alloc_case(tab, letters, (char *)s, c);
	if (!tab)
		return (NULL);
	free(letters);
	tab = remplissage(tab, (char *)s, c);
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("arg faux");
		return (0);
	}
	char    **tab;
	//char  tab2[] = "  bonjour je suis un genie  ";
	//char  sep[] = " ";
	int i; 
	int count;

	count = ft_count_word(argv[1], ' ');   
	tab = ft_split(argv[1], ' ');
	i= 0;
	while (i < count)
	{   
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	} 
	free(tab);
	return (0);
}*/
