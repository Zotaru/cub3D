/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:42:06 by amonier           #+#    #+#             */
/*   Updated: 2023/12/11 16:52:29 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_tex(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->infos->texture->img_no->img);
	free(vars->infos->texture->img_no);
	mlx_destroy_image(vars->mlx, vars->infos->texture->img_so->img);
	free(vars->infos->texture->img_so);
	mlx_destroy_image(vars->mlx, vars->infos->texture->img_ea->img);
	free(vars->infos->texture->img_ea);
	mlx_destroy_image(vars->mlx, vars->infos->texture->img_we->img);
	free(vars->infos->texture->img_we);
}

void	destroy(t_vars *vars)
{
	destroy_tex(vars);
	mlx_destroy_image(vars->mlx, vars->infos->img_sprite->img_one->img);
	free(vars->infos->img_sprite->img_one);
	mlx_destroy_image(vars->mlx, vars->infos->img_sprite->img_two->img);
	free(vars->infos->img_sprite->img_two);
	mlx_destroy_image(vars->mlx, vars->infos->img_sprite->img_three->img);
	free(vars->infos->img_sprite->img_three);
	free(vars->infos->img_sprite);
	free(vars->infos->texture->ctab);
	free(vars->infos->texture->ftab);
	free_t_infos(vars->infos);
	mlx_destroy_image(vars->mlx, (vars->img)->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->img);
	free(vars);
	return ;
}
