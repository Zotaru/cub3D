/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:13:59 by amonier           #+#    #+#             */
/*   Updated: 2023/12/28 17:35:04 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_exit(t_vars *vars, t_data *img, t_infos *infos)
{
	free_infos_before(infos);
	free(vars);
	free(img);
	exit(1);
}

void	init_window(t_vars *vars, t_data *img, t_infos *infos)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		init_exit(vars, img, infos);
	vars->win = mlx_new_window(vars->mlx, WINDOW_LENGTH, WINDOW_WIDTH, "Cub3D");
	if (!vars->win)
	{
		free(vars->mlx);
		init_exit(vars, img, infos);
	}
	img->img = mlx_new_image(vars->mlx, IMG_LENGTH, IMG_WIDTH);
	if (!img->img)
	{
		free(vars->mlx);
		free(vars->win);
		init_exit(vars, img, infos);
	}
	img->addr = mlx_get_data_addr(img->img, \
		&(img->bits_per_pixel), &(img->line_length), &(img->endian));
	if (!img->addr)
	{
		free(img->img);
		free(vars->mlx);
		free(vars->win);
		init_exit(vars, img, infos);
	}
}

t_vars	*init_all(t_infos *infos)
{
	t_vars	*vars;
	t_data	*img;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
	{
		free_infos_before(infos);
		exit(1);
	}
	img = malloc(sizeof(t_data));
	if (img == NULL)
	{
		free_infos_before(infos);
		free(vars);
		exit(1);
	}
	init_window(vars, img, infos);
	vars->img = img;
	return (vars);
}
