/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:22:15 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/10 19:23:00 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	dist_cam_screen_calculate(void)
{
	double	result;

	result = ((double) SCREEN_L_PX) / (2 * tan(degree_to_radian(FOV / 2.0)));
	return ((int) result);
}

double	distance_correction(t_vars *vars, double dist, t_ray *ray)
{
	double	dot_product;
	double	angle_radians;
	double	dist_modif;

	dot_product = ray->ray_x * \
	(((vars->infos)->body_player)->front_ray)->ray_x + ray->ray_y * \
	(((vars->infos)->body_player)->front_ray)->ray_y;
	angle_radians = acos(dot_product);
	dist_modif = dist * cos(angle_radians);
	return (dist_modif);
}

double	distance_correction_two(t_wall_lst *wall, t_body *body, t_ray *ray)
{
	double	cos_mabite;

	(void) wall;
	cos_mabite = ray->ray_x * body->front_ray->ray_x + \
	ray->ray_y * body->front_ray->ray_y;
	ray->dist = ray->dist * cos_mabite;
	return (ray->dist);
}

int	height_wall_px_calculate(t_vars *vars, t_ray *ray)
{
	double		height_wall_px;
	int			dist_cam_screen_px;
	double		dist;
	t_wall_lst	*good_wall;

	dist_cam_screen_px = dist_cam_screen_calculate();
	good_wall = throw_ray_method_two(vars, (vars->infos)->body_player, ray);
	dist = distance_correction_two(good_wall, (vars->infos)->body_player, ray);
	height_wall_px = (dist_cam_screen_px * H_WALL) / dist;
	return ((int) height_wall_px);
}

void	draw_column(t_vars *vars, int x, int h_wall_px, int y_central)
{
	int	y_begin;
	int	limit;

	y_begin = y_central - (h_wall_px / 2);
	limit = y_begin + h_wall_px;
	while (y_begin < limit && y_begin < IMG_WIDTH)
	{
		if (y_begin >= 0)
			my_mlx_pixel_put(vars->img, x, y_begin, 0x00F0F8FF);
		y_begin++;
	}
}
