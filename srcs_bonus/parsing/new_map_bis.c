/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:15:43 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/08 20:22:22 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	malloc_error_map(t_pars *pars, char **new_map)
{
	free_t_pars(pars);
	if (new_map[0])
		free_double_tab_char(new_map);
	else
		free(new_map);
	exit(1);
}

void	fill_new_map(t_pars *pars, char **new_map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_map[i] = malloc(sizeof(char) * (len + 2 + 1));
	if (new_map[i] == NULL)
		malloc_error_map(pars, new_map);
	fill_line(new_map[i], (len + 2 + 1));
	i++;
	while ((pars->map)[j])
	{
		new_map[i] = malloc(sizeof(char) * (len + 2 + 1 + 1));
		if (new_map[i] == NULL)
			malloc_error_map(pars, new_map);
		cpy_to_new_map(new_map[i], (len + 2 + 1), (pars->map)[j]);
		j++;
		i++;
	}
	new_map[i] = malloc(sizeof(char) * (len + 2 + 1));
	if (new_map[i] == NULL)
		malloc_error_map(pars, new_map);
	fill_line(new_map[i], (len + 2 + 1));
	i++;
	new_map[i] = NULL;
}
