/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:13:08 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 19:42:26 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_vars *vars, int count, int h_wall_px, int y_central)
{
	int	px_x_eq;
	int	x_begin;
	int	new_h_wall_px;
	int	new_y_central;
	int	step;

	new_h_wall_px = h_wall_px * IMG_WIDTH / SCREEN_H_PX;
	new_y_central = y_central * IMG_WIDTH / SCREEN_H_PX;
	px_x_eq = IMG_LENGTH / SCREEN_L_PX;
	x_begin = px_x_eq * count;
	step = (x_begin + px_x_eq);
	while (x_begin < step && x_begin < IMG_LENGTH)
	{
		draw_column(vars, x_begin, new_h_wall_px, new_y_central);
		x_begin++;
	}
}

int	calcul_center_up(t_ray *ray)
{
	int		dist_cam_ecran;
	double	h;
	double	result;

	dist_cam_ecran = dist_cam_screen_calculate();
	h = H_CAM - H_WALL / 2;
	result = (((double)dist_cam_ecran) * h) / ray->dist;
	return ((int) result);
}

int	calcul_center_down(t_ray *ray)
{
	int		dist_cam_ecran;
	double	h;
	double	result;

	dist_cam_ecran = dist_cam_screen_calculate();
	h = H_WALL / 2 - H_CAM;
	result = (((double)dist_cam_ecran) * h) / ray->dist;
	return ((int) result);
}

void	draw_wall(t_vars *vars, t_ray *ray, int count)
{
	int		h_wall_px;
	double	add1;
	int		y_central;

	h_wall_px = height_wall_px_calculate(vars, ray);
	if (H_CAM / H_WALL == 0.5)
		y_central = SCREEN_H_PX / 2;
	else if (H_CAM / H_WALL > 0.5)
	{
		add1 = calcul_center_up(ray);
		y_central = SCREEN_H_PX / 2 + add1;
	}
	else if (H_CAM / H_WALL < 0.5)
	{
		add1 = calcul_center_down(ray);
		y_central = SCREEN_H_PX / 2 - add1;
	}
	draw_line(vars, count, h_wall_px, y_central);
}

void	raycast(t_vars *vars, t_infos *infos)
{
	t_ray	*new_ray;
	double	step_angle_degree;
	double	step;
	int		count;

	count = 0;
	step_angle_degree = FOV / ((double) SCREEN_L_PX);
	step = 0.0;
	new_ray = create_new_rotate_ray(vars, \
	(infos->body_player)->front_ray, -(FOV / 2.0) - step_angle_degree);
	while (step <= FOV)
	{
		rotate_ray(new_ray, step_angle_degree);
		draw_wall(vars, new_ray, count);
		step = step + step_angle_degree;
		count++;
	}
	printf("count : %d\n", count);
	free(new_ray);
}
