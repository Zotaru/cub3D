/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:26:20 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 16:18:09 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	verification_point_dir(t_vars *vars, t_body *body, t_ray *dir)
{
	t_point_lst	*temp;
	double		temp_x;
	double		temp_y;

	temp = body->body_point;
	while (temp)
	{
		temp_x = temp->x_pos;
		temp_y = temp->y_pos;
		temp_x = temp_x + MOUV * dir->ray_x;
		temp_y = temp_y + MOUV * dir->ray_y;
		if ((((vars->infos)->map)->map)[(int) temp_y][(int) temp_x] == '1')
		{
			return (0);
		}
		else if ((((vars->infos)->map)->map)[(int) temp_y][(int) temp_x] == 'V')
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

void	maj_t_point(t_body *body, t_ray *ray)
{
	t_point_lst	*temp;

	temp = body->body_point;
	while (temp)
	{
		temp->x_pos = temp->x_pos + ray->ray_x * MOUV;
		temp->y_pos = temp->y_pos + ray->ray_y * MOUV;
		temp->pixel_x = temp->x_pos * body->length_x_pixel;
		temp->pixel_y = temp->y_pos * body->width_y_pixel;
		temp = temp->next;
	}
}

void	applied_move_on_body(t_body *body, t_ray *ray)
{
	body->center_x = body->center_x + ray->ray_x * MOUV;
	body->center_y = body->center_y + ray->ray_y * MOUV;
	body->pixel_x_center = body->center_x * body->length_x_pixel;
	body->pixel_y_center = body->center_y * body->width_y_pixel;
	maj_t_point(body, ray);
}
