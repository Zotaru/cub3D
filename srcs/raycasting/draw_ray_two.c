/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:10:10 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 16:42:56 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	while_column(t_column *col, t_vars *vars, int x, double count)
{
	(*col).y_in_texture = (int)((double)((*col).y - (*col).y_begin) / \
	count * (double)(*col).img_height);
	(*col).color = *(unsigned int *)((*col).img->addr + ((*col).y_in_texture * \
	(*col).img->line_length + (*col).x_in_texture * \
	((*col).img->bits_per_pixel / 8)));
	if ((*col).y >= 0)
		my_mlx_pixel_put(vars->img, x, (*col).y, (*col).color);
	(*col).y++;
}

void	draw_column_2(t_vars *vars, t_ray_fov *fov_tab, int count, int x)
{
	t_column	col;

	col.y = fov_tab[count].resize_center_y - \
	(fov_tab[count].resize_height_wall_px / 2);
	col.limit = col.y + fov_tab[count].resize_height_wall_px;
	if (fov_tab[count].wall->norm_x == 0.0
		&& fov_tab[count].wall->norm_y == 1.0)
		draw_if_one(&col, vars, fov_tab, count);
	else if (fov_tab[count].wall->norm_x == 0.0
		&& fov_tab[count].wall->norm_y == -1.0)
		draw_if_two(&col, vars, fov_tab, count);
	else if (fov_tab[count].wall->norm_x == 1.0
		&& fov_tab[count].wall->norm_y == 0.0)
		draw_if_three(&col, vars, fov_tab, count);
	else
		draw_if_four(&col, vars, fov_tab, count);
	col.x_in_texture = (int)(((double) col.img_width) * col.x_pos_img);
	color_c_f(col.y, x, col.limit, vars);
	col.y_begin = col.y;
	while (col.y < col.limit && col.y < IMG_WIDTH)
	{
		while_column(&col, vars, x, \
		(double)fov_tab[count].resize_height_wall_px);
	}
}

void	draw_line_2(t_vars *vars, t_ray_fov *fov_tab, int count)
{
	int	px_x_eq;
	int	x_begin;
	int	step;

	px_x_eq = IMG_LENGTH / SCREEN_L_PX;
	x_begin = px_x_eq * count;
	step = x_begin + px_x_eq;
	while (x_begin < step && x_begin < IMG_LENGTH)
	{
		draw_column_2(vars, fov_tab, count, x_begin);
		x_begin++;
	}
}
