/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:17:31 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 21:53:33 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cmp_char_to_charlst(char c, char *lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		if (lst[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (cmp_char_to_charlst(str[i], "01NSEWY \n") == 0)
			return (0);
		i++;
	}
	return (1);
}	

void	exit_extract(t_pars *pars)
{
	free_t_pars(pars);
	exit(1);
}

void	extract_map(t_pars *pars)
{
	int	size;
	int	i;
	int	j;

	j = 0;
	size = nb_line_double_tab(pars->file);
	i = size;
	i--;
	while (check_line((pars->file)[i]) == 1 && i >= 0)
		i--;
	pars->map = malloc(sizeof(char *) * (size - i + 1));
	if (pars->map == NULL)
		exit_extract(pars);
	i++;
	while ((pars->file)[i])
	{
		(pars->map)[j] = ft_strdup((pars->file)[i]);
		if ((pars->map)[j] == NULL)
			exit_extract(pars);
		j++;
		i++;
	}
	(pars->map)[j] = NULL;
	return ;
}
