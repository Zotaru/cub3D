/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:48:53 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 20:22:42 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_length_longest_line(char **map)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while ((map)[i])
	{
		if (ft_strlen((map)[i]) > len)
			len = ft_strlen((map)[i]);
		i++;
	}
	return (len);
}

void	fill_line(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len - 2)
	{
		str[i] = 'V';
		i++;
	}
	str[i] = '\n';
	i++;
	str[i] = '\0';
}

void	cpy_to_new_map(char *line_new_map, int len_tot, char *to_copy)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	line_new_map[i] = 'V';
	i++;
	while (to_copy[j] && to_copy[j] != '\n')
	{
		line_new_map[i] = to_copy[j];
		i++;
		j++;
	}
	while (i < len_tot - 3)
	{
		line_new_map[i] = '0';
		i++;
	}
	line_new_map[i] = 'V';
	i++;
	line_new_map[i] = '\n';
	i++;
	line_new_map[i] = '\0';
}

void	char_to_char(t_pars *pars, char target, char new_one)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((pars->map)[i])
	{
		while ((pars->map)[i][j])
		{
			if ((pars->map)[i][j] == target)
				(pars->map)[i][j] = new_one;
			j++;
		}
		j = 0;
		i++;
	}
}

void	new_map(t_pars *pars)
{
	int		height;
	int		len;
	char	**new_map;

	height = nb_line_double_tab(pars->map);
	len = find_length_longest_line(pars->map);
	new_map = malloc(sizeof(char *) * (height + 2 + 1));
	if (new_map == NULL)
	{
		free_t_pars(pars);
		exit(1);
	}
	fill_new_map(pars, new_map, len);
	free_double_tab_char(pars->map);
	pars->map = new_map;
	char_to_char(pars, ' ', '0');
}
