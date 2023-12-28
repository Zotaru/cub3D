/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:44:46 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 16:49:55 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_if_one(t_column *col, t_vars *vars, \
t_ray_fov *fov_tab, int count)
{
	(*col).img = vars->infos->texture->img_no;
	(*col).img_width = vars->infos->texture->no_width;
	(*col).img_height = vars->infos->texture->no_height;
	(*col).x_pos_img = (vars->infos->body_player->center_x) + \
	fov_tab[count].ray->ray_x * fov_tab[count].original_dist;
	(*col).x_pos_img = ((*col).x_pos_img - (double)((int)(*col).x_pos_img));
}

void	draw_if_two(t_column *col, t_vars *vars, \
t_ray_fov *fov_tab, int count)
{
	(*col).img = vars->infos->texture->img_so;
	(*col).img_width = vars->infos->texture->so_width;
	(*col).img_height = vars->infos->texture->so_height;
	(*col).x_pos_img = (vars->infos->body_player->center_x) + \
	fov_tab[count].ray->ray_x * fov_tab[count].original_dist;
	(*col).x_pos_img = ((*col).x_pos_img - (double)((int)(*col).x_pos_img));
}

void	draw_if_three(t_column *col, t_vars *vars, \
t_ray_fov *fov_tab, int count)
{
	(*col).img = vars->infos->texture->img_we;
	(*col).img_width = vars->infos->texture->we_width;
	(*col).img_height = vars->infos->texture->we_height;
	(*col).x_pos_img = (vars->infos->body_player->center_y) + \
	fov_tab[count].ray->ray_y * fov_tab[count].original_dist;
	(*col).x_pos_img = modf((*col).x_pos_img, &(*col).x_pos_img);
}

void	draw_if_four(t_column *col, t_vars *vars, \
t_ray_fov *fov_tab, int count)
{
	(*col).img = vars->infos->texture->img_ea;
	(*col).img_width = vars->infos->texture->ea_width;
	(*col).img_height = vars->infos->texture->ea_height;
	(*col).x_pos_img = (vars->infos->body_player->center_y) + \
	fov_tab[count].ray->ray_y * fov_tab[count].original_dist;
	(*col).x_pos_img = modf((*col).x_pos_img, &(*col).x_pos_img);
}
