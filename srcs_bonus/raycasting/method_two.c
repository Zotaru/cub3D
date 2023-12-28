/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:07:10 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 18:18:24 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	distance_two_point(double x1, double y1, double x2, double y2)
{
	double	dist;
	double	add1;
	double	add2;

	add1 = (x1 - x2) * (x1 - x2);
	add2 = (y1 - y2) * (y1 - y2);
	dist = sqrt(add1 + add2);
	return (dist);
}

double	calcule_eq_all_straight_line(t_body *body, t_ray *ray, t_wall_lst *wall)
{
	double	u;
	double	num;
	double	den;
	double	x_pos;
	double	y_pos;

	num = ray->ray_x * \
	(wall->y_start - body->center_y) - ray->ray_y * \
	(wall->x_start - body->center_x);
	den = ray->ray_y * \
	(wall->x_end - wall->x_start) - ray->ray_x * (wall->y_end - wall->y_start);
	u = num / den;
	if (u >= 0.0 && u <= 1.0)
	{
		x_pos = wall->x_start + u * (wall->x_end - wall->x_start);
		y_pos = wall->y_start + u * (wall->y_end - wall->y_start);
		return (distance_two_point(x_pos, y_pos, \
		body->center_x, body->center_y));
	}
	else
		return (-1.0);
}

double	check_one_wall(t_body *body, t_ray *ray, t_wall_lst *wall)
{
	double	res;

	if (preselection_wall(body->center_x, body->center_y, ray, wall) == 0)
		return (-1.0);
	res = calcule_eq_all_straight_line(body, ray, wall);
	return (res);
}

void	norm_throw_two(double *d_good, double new, \
t_wall_lst **wall_good, t_wall_lst **temp)
{
	*d_good = new;
	*wall_good = *temp;
}

t_wall_lst	*throw_ray_method_two(t_vars *vars, t_body *body, t_ray *ray)
{
	t_wall_lst	*wall_good;
	t_wall_lst	*temp;
	double		d_good;
	double		new;

	temp = (vars->infos)->wall;
	d_good = -1.0;
	wall_good = NULL;
	while (temp)
	{
		new = check_one_wall(body, ray, temp);
		if (new != -1.0)
		{
			if (d_good != -1.0)
			{
				if (d_good > new)
					norm_throw_two(&d_good, new, &wall_good, &temp);
			}
			else
				norm_throw_two(&d_good, new, &wall_good, &temp);
		}
		temp = temp->next;
	}
	ray->dist = d_good;
	return (wall_good);
}
