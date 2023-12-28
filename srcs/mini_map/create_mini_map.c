/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:19:40 by amonier           #+#    #+#             */
/*   Updated: 2023/12/12 17:05:58 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_square(t_data *img, int color, t_square square)
{
	int	i;
	int	j;

	i = square.x_pixel_origin;
	j = square.y_pixel_origin;
	while (j < (square.y_pixel_origin + square.width_y_pixel))
	{
		while (i < (square.x_pixel_origin + square.length_x_pixel))
		{
			my_mlx_pixel_put(img, i, j, color);
			i++;
		}
		i = square.x_pixel_origin;
		j++;
	}
}

t_square	init_square(t_infos *infos, t_square *square, \
	int pix_length, int pix_width)
{
	square->length_x_pixel = pix_length / (((infos)->map)->size_x);
	square->width_y_pixel = pix_width / (((infos)->map)->size_y);
	square->x_pixel_origin = 0;
	square->y_pixel_origin = 0;
	return (*square);
}

void	create_mini_map(t_vars *vars, \
	t_infos *infos, int pix_length, int pix_width)
{
	t_square	square;
	int			i;
	int			j;

	square = init_square(infos, &square, pix_length, pix_width);
	i = 0;
	j = 0;
	while (j < (((infos)->map)->size_y))
	{
		while (i < (((infos)->map)->size_x))
		{
			if (((infos->map)->map)[j][i] == '1')
				fill_square(vars->img, 0x00FF0000, square);
			else if (((infos->map)->map)[j][i] == '0')
				fill_square(vars->img, 0x000000FF, square);
			square.x_pixel_origin = \
				square.x_pixel_origin + square.length_x_pixel;
			i++;
		}
		square.x_pixel_origin = 0;
		square.y_pixel_origin = square.y_pixel_origin + square.width_y_pixel;
		i = 0;
		j++;
	}
	return ;
}
