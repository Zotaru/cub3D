/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:03:59 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/10 16:04:54 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_body	*create_body_bis(t_vars *vars, t_infos *infos, \
	int pix_length, int pix_width)
{
	t_square	square;
	t_body		*body_player;

	square.length_x_pixel = pix_length / (((infos)->map)->size_x);
	square.width_y_pixel = pix_width / (((infos)->map)->size_y);
	body_player = malloc(sizeof(t_body));
	if (body_player == NULL)
	{
		destroy(vars);
		exit(1);
	}
	body_player->center_x = (infos->player)->x_pos + 0.5;
	body_player->center_y = (infos->player)->y_pos + 0.5;
	body_player->pixel_x_center = body_player->center_x * square.length_x_pixel;
	body_player->pixel_y_center = body_player->center_y * square.width_y_pixel;
	square.x_pixel_origin = (infos->player)->x_pos * square.length_x_pixel;
	square.y_pixel_origin = (infos->player)->y_pos * square.width_y_pixel;
	body_player->diameter = 0.5;
	body_player->body_point = NULL;
	initialise_point_list_circle(vars, body_player, square);
	color_point_lst(vars, body_player->body_point, 0x0000FF00);
	infos->body_player = body_player;
	body_player->length_x_pixel = square.length_x_pixel;
	body_player->width_y_pixel = square.width_y_pixel;
	return (body_player);
}

void	end_create_player(t_vars *vars, t_body *body_player, t_ray *ray)
{
	body_player->front_ray = ray;
	draw_ray(vars, body_player, ray, 0x0000FF00);
	body_player->right_ray = \
		create_new_rotate_ray(vars, body_player->front_ray, 90.0);
	draw_ray(vars, body_player, body_player->right_ray, 0x00800080);
	body_player->back_ray = \
		create_new_rotate_ray(vars, body_player->front_ray, 180.0);
	draw_ray(vars, body_player, body_player->back_ray, 0x00800080);
	body_player->left_ray = \
		create_new_rotate_ray(vars, body_player->front_ray, -90.0);
	draw_ray(vars, body_player, body_player->left_ray, 0x00800080);
}

void	define_ray(t_ray *ray, int x, int y)
{
	ray->ray_x = x;
	ray->ray_y = y;
}
