/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preselection_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:19:12 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 18:29:43 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	norm_elseif_zero(double x, double y, t_ray *ray, t_sprite_lst *sprite)
{
	if (ray->ray_x > 0 && ray->ray_y > 0)
	{
		if (sprite->x_begin < x || sprite->y_begin < y)
		{
			if (sprite->x_end < x || sprite->y_end < y)
				return (0);
		}
	}
	else if (ray->ray_x < 0 && ray->ray_y < 0)
	{
		if (sprite->x_begin > x || sprite->y_begin > y)
		{
			if (sprite->x_end > x || sprite->y_end > y)
				return (0);
		}
	}
	return (1);
}

int	norm_elseif_one(double x, double y, t_ray *ray, t_sprite_lst *sprite)
{
	if (ray->ray_x > 0 && ray->ray_y < 0)
	{
		if (sprite->x_begin < x || sprite->y_begin > y)
		{
			if (sprite->x_end < x || sprite->y_end > y)
				return (0);
		}
	}
	else if (ray->ray_x < 0 && ray->ray_y > 0)
	{
		if (sprite->x_begin > x || sprite->y_begin < y)
		{
			if (sprite->x_end > x || sprite->y_end < y)
				return (0);
		}
	}
	return (1);
}

int	norm_elseif_two(double x, double y, t_ray *ray, t_sprite_lst *sprite)
{
	if (ray->ray_x == 0 && ray->ray_y > 0)
	{
		if (sprite->y_begin < y || sprite->y_end < y)
			return (0);
		if (sprite->x_begin > x && sprite->x_end > x)
			return (0);
		else if (sprite->x_begin < x && sprite->x_end < x)
			return (0);
	}
	else if (ray->ray_x == 0 && ray->ray_y < 0)
	{
		if (sprite->y_begin > y || sprite->y_end > y)
			return (0);
		if (sprite->x_begin > x && sprite->x_end > x)
			return (0);
		else if (sprite->x_begin < x && sprite->x_end < x)
			return (0);
	}
	return (1);
}

int	norm_elseif_three(double x, double y, t_ray *ray, t_sprite_lst *sprite)
{
	if (ray->ray_x > 0 && ray->ray_y == 0)
	{
		if (sprite->x_begin < x || sprite->x_end < x)
			return (0);
		if (sprite->y_begin > y && sprite->y_end > y)
			return (0);
		else if (sprite->y_begin < y && sprite->y_end < y)
			return (0);
	}
	else if (ray->ray_x < 0 && ray->ray_y == 0)
	{
		if (sprite->x_begin > x || sprite->x_end > x)
			return (0);
		if (sprite->y_begin > y && sprite->y_end > y)
			return (0);
		else if (sprite->y_begin < y && sprite->y_end < y)
			return (0);
	}
	return (1);
}

int	preselection_sprite(double x, double y, t_ray *ray, t_sprite_lst *sprite)
{
	int	i;

	i = 1;
	i = norm_elseif_zero(x, y, ray, sprite);
	if (i == 0)
		return (i);
	i = norm_elseif_one(x, y, ray, sprite);
	if (i == 0)
		return (i);
	i = norm_elseif_two(x, y, ray, sprite);
	if (i == 0)
		return (i);
	i = norm_elseif_three(x, y, ray, sprite);
	return (i);
}
