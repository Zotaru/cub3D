/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:31:35 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 16:44:53 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	change_sprite(t_vars *vars, t_sprite_lst *sprite_lst)
{
	t_sprite_lst	*spt;

	spt = sprite_lst;
	while (spt)
	{
		spt->norm_x = (vars->infos->body_player->center_x - spt->center_x) \
		/ sqrt((vars->infos->body_player->center_x - spt->center_x) * \
		(vars->infos->body_player->center_x - spt->center_x) + \
		(vars->infos->body_player->center_y - spt->center_y) * \
		(vars->infos->body_player->center_y - spt->center_y));
		spt->norm_y = (vars->infos->body_player->center_y - spt->center_y) \
		/ sqrt((vars->infos->body_player->center_x - spt->center_x) * \
		(vars->infos->body_player->center_x - spt->center_x) + \
		(vars->infos->body_player->center_y - spt->center_y) * \
		(vars->infos->body_player->center_y - spt->center_y));
		spt->vec_l_x = spt->norm_y;
		spt->vec_l_y = -spt->norm_x;
		spt->x_begin = spt->center_x + spt->vec_l_x * L_SPRITE / 2;
		spt->y_begin = spt->center_y + spt->vec_l_y * L_SPRITE / 2;
		spt->x_end = spt->center_x - spt->vec_l_x * L_SPRITE / 2;
		spt->y_end = spt->center_y - spt->vec_l_y * L_SPRITE / 2;
		spt = spt->next;
	}
	return ;
}
