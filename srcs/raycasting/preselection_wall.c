/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preselection_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:52 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 18:37:30 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	norm_elseif_wallzero(double x, double y, t_ray *ray, t_wall_lst *wall)
{
	if (ray->ray_x > 0 && ray->ray_y > 0)
	{
		if (wall->x_start < x || wall->y_start < y)
		{
			if (wall->x_end < x || wall->y_end < y)
				return (0);
		}
	}
	else if (ray->ray_x < 0 && ray->ray_y < 0)
	{
		if (wall->x_start > x || wall->y_start > y)
		{
			if (wall->x_end > x || wall->y_end > y)
				return (0);
		}
	}
	return (1);
}

int	norm_elseif_wallone(double x, double y, t_ray *ray, t_wall_lst *wall)
{
	if (ray->ray_x > 0 && ray->ray_y < 0)
	{
		if (wall->x_start < x || wall->y_start > y)
		{
			if (wall->x_end < x || wall->y_end > y)
				return (0);
		}
	}
	else if (ray->ray_x < 0 && ray->ray_y > 0)
	{
		if (wall->x_start > x || wall->y_start < y)
		{
			if (wall->x_end > x || wall->y_end < y)
				return (0);
		}
	}
	return (1);
}

int	norm_elseif_walltwo(double x, double y, t_ray *ray, t_wall_lst *wall)
{
	if (ray->ray_x == 0 && ray->ray_y > 0)
	{
		if (wall->y_start < y || wall->y_end < y)
		{
			return (0);
		}
		if (wall->x_start > x && wall->x_end > x)
			return (0);
		else if (wall->x_start < x && wall->x_end < x)
			return (0);
	}
	else if (ray->ray_x == 0 && ray->ray_y < 0)
	{
		if (wall->y_start > y || wall->y_end > y)
			return (0);
		if (wall->x_start > x && wall->x_end > x)
			return (0);
		else if (wall->x_start < x && wall->x_end < x)
			return (0);
	}
	return (1);
}

int	norm_elseif_wallthree(double x, double y, t_ray *ray, t_wall_lst *wall)
{
	if (ray->ray_x > 0 && ray->ray_y == 0)
	{
		if (wall->x_start < x || wall->x_end < x)
			return (0);
		if (wall->y_start > y && wall->y_end > y)
			return (0);
		else if (wall->y_start < y && wall->y_end < y)
			return (0);
	}
	else if (ray->ray_x < 0 && ray->ray_y == 0)
	{
		if (wall->x_start > x || wall->x_end > x)
			return (0);
		if (wall->y_start > y && wall->y_end > y)
			return (0);
		else if (wall->y_start < y && wall->y_end < y)
			return (0);
	}
	return (1);
}

int	preselection_wall(double x, double y, t_ray *ray, t_wall_lst *wall)
{
	int	i;

	i = 1;
	i = norm_elseif_wallzero(x, y, ray, wall);
	if (i == 0)
		return (i);
	i = norm_elseif_wallone(x, y, ray, wall);
	if (i == 0)
		return (i);
	i = norm_elseif_walltwo(x, y, ray, wall);
	if (i == 0)
		return (i);
	i = norm_elseif_wallthree(x, y, ray, wall);
	return (i);
}
