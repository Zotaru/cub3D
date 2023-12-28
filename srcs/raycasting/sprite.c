/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:44:34 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/10 20:14:27 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	height_sprite_px(t_vars *vars, t_ray_fov *fov_tab, int count)
{
	int				dist_cam_screen_px;
	double			dist;
	t_sprite_lst	*good_sprite;

	dist_cam_screen_px = dist_cam_screen_calculate();
	good_sprite = throw_ray_meth_two_sprite(vars, \
	(vars->infos)->body_player, fov_tab[count].ray);
	dist = (fov_tab[count].ray)->sprite_dst;
	fov_tab[count].sprite_dist = dist;
	fov_tab[count].sprite = good_sprite;
	if (good_sprite == NULL)
		fov_tab[count].sprite_height_in_px = -1;
	else if (dist <= 0)
		fov_tab[count].sprite_height_in_px = -1;
	else if (dist > fov_tab[count].original_dist)
		fov_tab[count].sprite_height_in_px = -1;
	else
		fov_tab[count].sprite_height_in_px = \
		(dist_cam_screen_px * H_SPRITE) / dist;
	return ;
}

double	find_x_pos_img(t_vars *vars, t_ray_fov *fov_tab, int count)
{
	double	x_on_image;
	double	y_on_image;
	double	dist;
	double	x_pos_img;

	x_on_image = vars->infos->body_player->center_x + \
	fov_tab[count].ray->ray_x * fov_tab[count].sprite_dist;
	y_on_image = vars->infos->body_player->center_y + \
	fov_tab[count].ray->ray_y * fov_tab[count].sprite_dist;
	dist = distance_two_point(x_on_image, y_on_image, \
	fov_tab[count].sprite->x_begin, fov_tab[count].sprite->y_begin);
	x_pos_img = dist / L_SPRITE;
	return (x_pos_img);
}

void	draw_line_for_sprite(t_vars *vars, t_ray_fov *fov_tab, int count)
{
	int	px_x_eq;
	int	x_begin;
	int	step;

	px_x_eq = IMG_LENGTH / SCREEN_L_PX;
	x_begin = px_x_eq * count;
	step = x_begin + px_x_eq;
	while (x_begin < step && x_begin < IMG_LENGTH)
	{
		draw_column_for_sprite(vars, fov_tab, count, x_begin);
		x_begin++;
	}
}

void	display_sprite(t_vars *vars, t_ray_fov *fov_tab, int count)
{
	height_sprite_px(vars, fov_tab, count);
	if (fov_tab[count].sprite_height_in_px <= 0)
		return ;
	fov_tab[count].sprite_height_in_px = \
	(int)((double)fov_tab[count].sprite_height_in_px * \
	(double)IMG_WIDTH / (double)SCREEN_H_PX);
	draw_line_for_sprite(vars, fov_tab, count);
}
