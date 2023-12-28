/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:45:36 by amonier           #+#    #+#             */
/*   Updated: 2023/12/12 17:59:52 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	keycode_122(t_vars *vars)
{
	if (verification_point_dir(vars, (vars->infos)->body_player, \
		((vars->infos)->body_player)->front_ray))
	{
		applied_move_on_body((vars->infos)->body_player, \
			((vars->infos)->body_player)->front_ray);
		change_sprite(vars, vars->infos->sprite);
		clear_image(vars->img);
		raycast_two(vars, vars->infos);
		create_mini_map(vars, (vars->infos), 320, 180);
		color_point_lst(vars, \
			((vars->infos)->body_player)->body_point, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->front_ray, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->left_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->right_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->back_ray, 0x00800080);
		mlx_put_image_to_window(vars->mlx, vars->win, (vars->img)->img, 0, 0);
	}
}

void	keycode_115(t_vars *vars)
{
	if (verification_point_dir(vars, (vars->infos)->body_player, \
		((vars->infos)->body_player)->back_ray))
	{
		applied_move_on_body((vars->infos)->body_player, \
			((vars->infos)->body_player)->back_ray);
		change_sprite(vars, vars->infos->sprite);
		clear_image(vars->img);
		raycast_two(vars, vars->infos);
		create_mini_map(vars, (vars->infos), 320, 180);
		color_point_lst(vars, \
			((vars->infos)->body_player)->body_point, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->front_ray, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->left_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->right_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->back_ray, 0x00800080);
		mlx_put_image_to_window(vars->mlx, vars->win, (vars->img)->img, 0, 0);
	}
}

void	keycode_113(t_vars *vars)
{
	if (verification_point_dir(vars, \
		(vars->infos)->body_player, ((vars->infos)->body_player)->left_ray))
	{
		applied_move_on_body((vars->infos)->body_player, \
			((vars->infos)->body_player)->left_ray);
		change_sprite(vars, vars->infos->sprite);
		clear_image(vars->img);
		raycast_two(vars, vars->infos);
		create_mini_map(vars, (vars->infos), 320, 180);
		color_point_lst(vars, \
			((vars->infos)->body_player)->body_point, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->front_ray, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->left_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->right_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->back_ray, 0x00800080);
		mlx_put_image_to_window(vars->mlx, vars->win, (vars->img)->img, 0, 0);
	}
}

void	keycode_100(t_vars *vars)
{
	if (verification_point_dir(vars, \
		(vars->infos)->body_player, ((vars->infos)->body_player)->right_ray))
	{
		applied_move_on_body((vars->infos)->body_player, \
			((vars->infos)->body_player)->right_ray);
		change_sprite(vars, vars->infos->sprite);
		clear_image(vars->img);
		raycast_two(vars, vars->infos);
		create_mini_map(vars, (vars->infos), 320, 180);
		color_point_lst(vars, \
			((vars->infos)->body_player)->body_point, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->front_ray, 0x0000FF00);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->left_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->right_ray, 0x00800080);
		draw_ray(vars, (vars->infos)->body_player, \
			((vars->infos)->body_player)->back_ray, 0x00800080);
		mlx_put_image_to_window(vars->mlx, vars->win, (vars->img)->img, 0, 0);
	}
}

void	mouv(int keycode, t_vars *vars)
{
	if (keycode == 119)
		keycode_122(vars);
	else if (keycode == 115)
		keycode_115(vars);
	else if (keycode == 97)
		keycode_113(vars);
	else if (keycode == 100)
		keycode_100(vars);
}
