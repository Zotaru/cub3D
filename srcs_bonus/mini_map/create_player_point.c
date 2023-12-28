/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:05:04 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 16:04:59 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_in_the_circle(int i, int j, t_body *body_player, t_square square)
{
	double	x;
	double	y;
	double	radius;

	x = (double) i / (double) square.length_x_pixel;
	y = (double) j / (double) square.width_y_pixel;
	x = (x - body_player->center_x) * (x - body_player->center_x);
	y = (y - body_player->center_y) * (y - body_player->center_y);
	radius = body_player->diameter / 2;
	if (x + y <= radius * radius)
		return (1);
	return (0);
}

void	initialise_point_list_circle(t_vars *vars, \
	t_body *body_player, t_square square)
{
	int	i;
	int	j;

	(void) vars;
	i = square.x_pixel_origin;
	j = square.y_pixel_origin;
	while (j < square.y_pixel_origin + square.width_y_pixel)
	{
		while (i < square.x_pixel_origin + square.length_x_pixel)
		{
			if (is_in_the_circle(i, j, body_player, square) == 1)
			{
				ft_lst_point_addback(&(body_player->body_point), \
					ft_lst_point_new(i, j, (double) i / \
						(double) square.length_x_pixel, \
							(double) j / (double) square.width_y_pixel));
			}
			i++;
		}
		i = square.x_pixel_origin;
		j++;
	}
}

void	print_point(t_point_lst *body)
{
	t_point_lst	*temp;

	temp = body;
	while (temp)
	{
		printf("pixel x: %d, pixel y: %d\n", temp->pixel_x, temp->pixel_y);
		temp = temp->next;
	}
}

void	create_player_point(t_vars *vars, \
	t_infos *infos, int pix_length, int pix_width)
{
	t_body		*body_player;
	t_ray		*ray;

	body_player = create_body_bis(vars, infos, pix_length, pix_width);
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
	{
		destroy(vars);
		exit(1);
	}
	if (infos->player->direction == 'N')
		define_ray(ray, 0.0, -1.0);
	else if (infos->player->direction == 'S')
		define_ray(ray, 0.0, 1.0);
	else if (infos->player->direction == 'E')
		define_ray(ray, 1.0, 0.0);
	else if (infos->player->direction == 'W')
		define_ray(ray, -1.0, 0.0);
	end_create_player(vars, body_player, ray);
}
