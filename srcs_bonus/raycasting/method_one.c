/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:50:32 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 17:59:06 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	throw_ray_method_one(t_vars *vars, t_body *body, t_ray *ray)
{
	double	step;
	double	center_x;
	double	center_y;
	double	count;

	count = 0.0;
	step = 0.01;
	center_x = body->center_x;
	center_y = body->center_y;
	while ((((vars->infos)->map)->map)[(int) center_y][(int) center_x] == '0')
	{
		center_x = center_x + step * ray->ray_x;
		center_y = center_y + step * ray->ray_y;
		count = count + 1.0;
	}
	return (step * count);
}
