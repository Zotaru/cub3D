/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:39:19 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 21:57:14 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_player(char **map)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (cmp_char_to_charlst(map[i][j], "NSEW") == 1)
				nb++;
			j++;
		}
		i++;
		j = 0;
	}
	return (nb);
}

void	find_pos(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((pars->map)[j])
	{
		while ((pars->map)[j][i])
		{
			if (cmp_char_to_charlst((pars->map)[j][i], "NSEW") == 1)
			{
				(pars->player_info)->direction = (pars->map)[j][i];
				(pars->player_info)->x_pos = i;
				(pars->player_info)->y_pos = j;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}

void	map_close_recursive(t_pars *pars, int x, int y)
{
	if ((pars->map)[y][x] == '0')
	{
		(pars->map)[y][x] = 'W';
		map_close_recursive(pars, x + 1, y);
		map_close_recursive(pars, x - 1, y);
		map_close_recursive(pars, x, y + 1);
		map_close_recursive(pars, x, y - 1);
	}
	else if ((pars->map)[y][x] == 'V')
	{
		(pars)->map_close = 1;
	}
	return ;
}

void	map_close(t_pars *pars)
{
	(pars->map)[pars->player_info->y_pos][pars->player_info->x_pos] = '0';
	map_close_recursive(pars, pars->player_info->x_pos, \
		pars->player_info->y_pos);
}

void	check_map(t_pars *pars, t_sprite_lst *sprite)
{
	if (check_player(pars->map) != 1)
		exit_check_map(pars, sprite);
	pars->player_info = malloc(sizeof(t_player));
	if (pars->player_info == NULL)
	{
		free_t_pars(pars);
		ft_lst_sprite_clear(&sprite);
		exit(1);
	}
	find_pos(pars);
	(pars)->map_close = 0;
	map_close(pars);
	if ((pars)->map_close == 1)
		exit_check_map(pars, sprite);
	char_to_char(pars, '0', 'V');
	char_to_char(pars, 'W', '0');
	return ;
}
