/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:24:51 by amonier           #+#    #+#             */
/*   Updated: 2023/12/12 02:12:53 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_all_vector(t_body *body, double angle)
{
	rotate_ray(body->front_ray, angle);
	rotate_ray(body->left_ray, angle);
	rotate_ray(body->right_ray, angle);
	rotate_ray(body->back_ray, angle);
}

static void	left(t_vars *param)
{
	rotate_all_vector(param->infos->body_player, -1.0);
	rotate_fov(param->infos->body_player->fov_tab, -1.0);
	clear_image(param->img);
	raycast_two(param, param->infos);
	mlx_put_image_to_window(param->mlx, param->win, ((param->img)->img), 0, 0);
}

static void	right(t_vars *param)
{
	rotate_all_vector(param->infos->body_player, 1.0);
	rotate_fov(param->infos->body_player->fov_tab, 1.0);
	clear_image(param->img);
	raycast_two(param, param->infos);
	mlx_put_image_to_window(param->mlx, param->win, ((param->img)->img), 0, 0);
}

int	keyboard(int keycode, t_vars *param)
{
	if (keycode == 65361)
		left(param);
	else if (keycode == 65362)
		(void)param;
	else if (keycode == 65363)
		right(param);
	else if (keycode == 65364)
		(void)param;
	else if (keycode == 65307)
		cross(param);
	else if (keycode == 4)
		mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	mouv(keycode, param);
	(void) param;
	return (0);
}
