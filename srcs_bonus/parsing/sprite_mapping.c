/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_mapping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:05:45 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/08 20:24:35 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_sprite_lst	*sprite_mapping(t_pars *pars)
{
	int				i;
	int				j;
	t_sprite_lst	*sprite;

	i = 0;
	j = 0;
	sprite = NULL;
	while (pars->map[i])
	{
		while (pars->map[i][j])
		{
			if (pars->map[i][j] == 'Y')
			{
				(pars->map)[i][j] = '0';
				ft_lst_sprite_addback(&sprite, ft_lst_sprite_new(j, i));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (sprite);
}
