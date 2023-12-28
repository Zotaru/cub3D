/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:45:35 by amonier           #+#    #+#             */
/*   Updated: 2023/12/11 16:51:22 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// recoder encore qq fonctions 
// pour avoir le point d impact serai pas mal

void	color_c_f(int y, int x, int limit, t_vars *vars)
{
	int	color_f;
	int	color_c;
	int	i;

	i = 0;
	color_f = (((vars->infos->texture->ftab)[0] << 16) | \
	((vars->infos->texture->ftab)[1] << 8) | ((vars->infos->texture->ftab)[2]));
	color_c = (((vars->infos->texture->ctab)[0] << 16) | \
	((vars->infos->texture->ctab)[1] << 8) | ((vars->infos->texture->ctab)[2]));
	while (y > 0 && i < y)
	{
		my_mlx_pixel_put(vars->img, x, i, color_c);
		i++;
	}
	i = limit;
	while (i < IMG_WIDTH)
	{
		my_mlx_pixel_put(vars->img, x, i, color_f);
		i++;
	}
	return ;
}

void	height_wall_px_for_thread(t_vars *vars, t_ray_fov *fov_tab, int count)
{
	int			dist_cam_screen_px;
	double		dist;
	t_wall_lst	*good_wall;

	dist_cam_screen_px = dist_cam_screen_calculate();
	good_wall = throw_ray_method_two(vars, \
	(vars->infos)->body_player, fov_tab[count].ray);
	fov_tab[count].original_dist = fov_tab[count].ray->dist;
	dist = distance_correction_two(good_wall, \
	(vars->infos)->body_player, fov_tab[count].ray);
	fov_tab[count].dist_cam_wall = dist;
	fov_tab[count].wall = good_wall;
	fov_tab[count].height_wall_in_px = (dist_cam_screen_px * H_WALL) / dist;
	return ;
}

void	resize_px(t_ray_fov *fov_tab, int count)
{
	fov_tab[count].resize_height_wall_px = \
	(int)((double)fov_tab[count].height_wall_in_px * \
	(double)IMG_WIDTH / (double)SCREEN_H_PX);
	fov_tab[count].resize_center_y = \
	(int)((double)fov_tab[count].center_wall_y * \
	(double)IMG_WIDTH / (double)SCREEN_H_PX);
}

void	fill_t_ray_fov(t_vars *vars, t_ray_fov *fov_tab, int count)
{
	height_wall_px_for_thread(vars, fov_tab, count);
	if (H_CAM / H_WALL == 0.5)
		fov_tab[count].center_wall_y = SCREEN_H_PX / 2;
	else if (H_CAM / H_WALL > 0.5)
	{
		fov_tab[count].center_wall_y = SCREEN_H_PX / 2 + \
		calcul_center_up(fov_tab[count].ray);
	}
	else if (H_CAM / H_WALL < 0.5)
	{
		fov_tab[count].center_wall_y = SCREEN_H_PX / 2 - \
		calcul_center_down(fov_tab[count].ray);
	}
	resize_px(fov_tab, count);
}

void	raycast_two(t_vars *vars, t_infos *infos)
{
	int	count;

	count = 0;
	while (count < (SCREEN_L_PX + 1))
	{
		fill_t_ray_fov(vars, (infos->body_player->fov_tab), count);
		draw_line_2(vars, (infos->body_player->fov_tab), count);
		display_sprite(vars, (infos->body_player->fov_tab), count);
		count++;
	}
	return ;
}
