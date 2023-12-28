/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:44:03 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 23:39:52 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ray(t_vars *vars, t_body *body, t_ray *ray, int color)
{
	double	i;
	double	j;
	int		pix_x;
	int		pix_y;

	i = body->center_x;
	j = body->center_y;
	while (1)
	{
		if ((((vars->infos)->map)->map)[(int) j][(int) i] == '0')
		{
			pix_x = i * body->length_x_pixel;
			pix_y = j * body->width_y_pixel;
			my_mlx_pixel_put(vars->img, pix_x, pix_y, color);
			i = i + 0.1 * ray->ray_x;
			j = j + 0.1 * ray->ray_y;
		}
		else
			break ;
	}
	return ;
}
