/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:44 by amonier           #+#    #+#             */
/*   Updated: 2023/12/12 02:15:23 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_infos	*infos;

	infos = parsing(argc, argv);
	vars = init_all();
	vars->infos = infos;
	simplifying_wall(&(infos->wall));
	texture_check(infos, vars);
	color_check(infos, vars);
	all_hook(vars);
	create_player_point(vars, (vars->infos), 320, 180);
	infos->body_player->fov_tab = create_fov_ray_tab(vars, vars->infos);
	init_sprite(vars);
	sprite_ges(vars, infos);
	raycast_two(vars, vars->infos);
	mlx_put_image_to_window(vars->mlx, vars->win, ((vars->img)->img), 0, 0);
	mlx_loop_hook(vars->mlx, change_status_sprite, (void *)vars);
	mlx_loop(vars->mlx);
	return (0);
}
