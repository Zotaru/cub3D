/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:14:31 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 17:59:23 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	if_col(t_vars *vars, t_column *col)
{
	(*col).img = vars->infos->img_sprite->img_one;
	(*col).img_width = vars->infos->img_sprite->img_one_width;
	(*col).img_height = vars->infos->img_sprite->img_one_height;
}

void	else_if_col(t_vars *vars, t_column *col)
{
	(*col).img = vars->infos->img_sprite->img_two;
	(*col).img_width = vars->infos->img_sprite->img_two_width;
	(*col).img_height = vars->infos->img_sprite->img_two_height;
}

void	else_col(t_vars *vars, t_column *col)
{
	(*col).img = vars->infos->img_sprite->img_three;
	(*col).img_width = vars->infos->img_sprite->img_three_width;
	(*col).img_height = vars->infos->img_sprite->img_three_height;
}

void	draw_column_for_sprite(t_vars *vars, \
t_ray_fov *fov_tab, int count, int x)
{
	t_column	col;

	col.y = IMG_WIDTH / 2 - (fov_tab[count].sprite_height_in_px / 2);
	col.limit = col.y + fov_tab[count].sprite_height_in_px;
	if (vars->infos->img_sprite->status == 1)
		if_col(vars, &col);
	else if (vars->infos->img_sprite->status == 2)
		else_if_col(vars, &col);
	else
		else_col(vars, &col);
	col.x_pos_img = find_x_pos_img(vars, fov_tab, count);
	col.x_in_texture = (int)(((double) col.img_width) * col.x_pos_img);
	col.y_begin = col.y;
	while (col.y < col.limit && col.y < IMG_WIDTH)
	{
		col.y_in_texture = (int)((double)(col.y - col.y_begin) / \
		(double)fov_tab[count].sprite_height_in_px * (double)col.img_height);
		col.color = *(unsigned int *)(col.img->addr + \
		(col.y_in_texture * col.img->line_length + col.x_in_texture * \
		(col.img->bits_per_pixel / 8)));
		if (col.y >= 0 && col.color != 0xFFFFFF)
			my_mlx_pixel_put(vars->img, x, col.y, col.color);
		col.y++;
	}
}
