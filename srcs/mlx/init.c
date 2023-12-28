/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:13:59 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 20:06:28 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_exit(t_vars *vars, t_data *img)
{
	free(vars);
	free(img);
	exit(1);
}

void	init_window(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		init_exit(vars, img);
	vars->win = mlx_new_window(vars->mlx, WINDOW_LENGTH, WINDOW_WIDTH, "Cub3D");
	if (!vars->win)
	{
		free(vars->mlx);
		init_exit(vars, img);
	}
	img->img = mlx_new_image(vars->mlx, IMG_LENGTH, IMG_WIDTH);
	if (!img->img)
	{
		free(vars->mlx);
		free(vars->win);
		init_exit(vars, img);
	}
	img->addr = mlx_get_data_addr(img->img, \
		&(img->bits_per_pixel), &(img->line_length), &(img->endian));
	if (!img->addr)
	{
		free(img->img);
		free(vars->mlx);
		free(vars->win);
		init_exit(vars, img);
	}
}

t_vars	*init_all(void)
{
	t_vars	*vars;
	t_data	*img;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		exit(1);
	img = malloc(sizeof(t_data));
	if (img == NULL)
	{
		free(vars);
		exit(1);
	}
	init_window(vars, img);
	vars->img = img;
	return (vars);
}
