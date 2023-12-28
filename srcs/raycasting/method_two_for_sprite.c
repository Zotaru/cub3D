/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_two_for_sprite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:43:29 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/10 18:36:35 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calcule_eq_all_straight_line_sprite(t_body *body, t_ray *ray, \
t_sprite_lst *sprite)
{
	double	u;
	double	num;
	double	den;
	double	x_pos;
	double	y_pos;

	num = ray->ray_x * (sprite->y_begin - body->center_y) - \
	ray->ray_y * (sprite->x_begin - body->center_x);
	den = ray->ray_y * (sprite->x_end - sprite->x_begin) - \
	ray->ray_x * (sprite->y_end - sprite->y_begin);
	u = num / den;
	if (u >= 0.0 && u <= 1.0)
	{
		x_pos = sprite->x_begin + u * (sprite->x_end - sprite->x_begin);
		y_pos = sprite->y_begin + u * (sprite->y_end - sprite->y_begin);
		return (distance_two_point(x_pos, y_pos, \
		body->center_x, body->center_y));
	}
	else
		return (-1.0);
}

double	check_one_sprite(t_body *body, t_ray *ray, t_sprite_lst *sprite)
{
	double	res;

	if (preselection_sprite(body->center_x, body->center_y, ray, sprite) == 0)
		return (-1.0);
	res = calcule_eq_all_straight_line_sprite(body, ray, sprite);
	return (res);
}

void	norm_throw_two_sprite(double *d_good, double new, \
t_sprite_lst **wall_good, t_sprite_lst **temp)
{
	*d_good = new;
	*wall_good = *temp;
}

t_sprite_lst	*throw_ray_meth_two_sprite(t_vars *vars, \
t_body *body, t_ray *ray)
{
	t_sprite_lst	*gd_spt;
	t_sprite_lst	*temp;
	double			d_good;
	double			new;

	temp = (vars->infos)->sprite;
	d_good = -1.0;
	gd_spt = NULL;
	while (temp)
	{
		new = check_one_sprite(body, ray, temp);
		if (new != -1.0)
		{
			if (d_good != -1.0)
			{
				if (d_good > new)
					norm_throw_two_sprite(&d_good, new, &gd_spt, &temp);
			}
			else
				norm_throw_two_sprite(&d_good, new, &gd_spt, &temp);
		}
		temp = temp->next;
	}
	ray->sprite_dst = d_good;
	return (gd_spt);
}
