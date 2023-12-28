/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:01:31 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 23:24:42 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_wall(t_pars *pars, t_wall_lst **wall, int i, int j)
{
	t_wall_lst	*temp;

	temp = NULL;
	if ((pars->map)[j][i] == '0')
	{
		(pars->map)[j][i] = 'W';
		if ((pars->map)[j + 1][i] == '1')
			find_wall_one(temp, wall, i, j);
		if ((pars->map)[j - 1][i] == '1')
			find_wall_two(temp, wall, i, j);
		if ((pars->map)[j][i + 1] == '1')
			find_wall_three(temp, wall, i, j);
		if ((pars->map)[j][i - 1] == '1')
			find_wall_four(temp, wall, i, j);
		find_wall(pars, wall, i + 1, j);
		find_wall(pars, wall, i - 1, j);
		find_wall(pars, wall, i, j + 1);
		find_wall(pars, wall, i, j - 1);
	}
}

t_wall_lst	*create_wall_lst(t_pars *pars)
{
	t_wall_lst	*wall;

	wall = NULL;
	find_wall(pars, &wall, (pars->player_info)->x_pos, \
	(pars->player_info)->y_pos);
	char_to_char(pars, 'W', '0');
	return (wall);
}
