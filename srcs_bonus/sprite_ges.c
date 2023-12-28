/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_ges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:10:10 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/12 02:34:26 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_sprite(t_vars *vars)
{
	t_sprite_lst	*temp;
	t_body			*p;

	p = vars->infos->body_player;
	temp = vars->infos->sprite;
	while (temp)
	{
		temp->center_x = temp->pos_x + 0.5;
		temp->center_y = temp->pos_y + 0.5;
		temp->norm_x = (p->center_x - temp->center_x) / \
		sqrt((p->center_x - temp->center_x) * \
		(p->center_x - temp->center_x) + (p->center_y - temp->center_y) * \
		(p->center_y - temp->center_y));
		temp->norm_y = (p->center_y - temp->center_y) / \
		sqrt((p->center_x - temp->center_x) * (p->center_x - temp->center_x) + \
		(p->center_y - temp->center_y) * (p->center_y - temp->center_y));
		temp->vec_l_x = temp->norm_y;
		temp->vec_l_y = -temp->norm_x;
		temp->x_begin = temp->center_x + temp->vec_l_x * L_SPRITE / 2;
		temp->y_begin = temp->center_y + temp->vec_l_y * L_SPRITE / 2;
		temp->x_end = temp->center_x - temp->vec_l_x * L_SPRITE / 2;
		temp->y_end = temp->center_y - temp->vec_l_y * L_SPRITE / 2;
		temp = temp->next;
	}
	return ;
}

int	change_status_sprite(void *tvars)
{
	t_vars	*vars;

	vars = (t_vars *)tvars;
	if (vars->infos->img_sprite->status == 1)
		vars->infos->img_sprite->status = 2;
	else if (vars->infos->img_sprite->status == 2)
		vars->infos->img_sprite->status = 3;
	else if (vars->infos->img_sprite->status == 3)
		vars->infos->img_sprite->status = 1;
	clear_image(vars->img);
	raycast_two(vars, vars->infos);
	create_mini_map(vars, (vars->infos), 320, 180);
	color_point_lst(vars, ((vars->infos)->body_player)->body_point, 0x0000FF00);
	draw_ray(vars, (vars->infos)->body_player, \
	((vars->infos)->body_player)->front_ray, 0x0000FF00);
	draw_ray(vars, (vars->infos)->body_player, \
	((vars->infos)->body_player)->left_ray, 0x00800080);
	draw_ray(vars, (vars->infos)->body_player, \
	((vars->infos)->body_player)->right_ray, 0x00800080);
	draw_ray(vars, (vars->infos)->body_player, \
	((vars->infos)->body_player)->back_ray, 0x00800080);
	mlx_put_image_to_window(vars->mlx, vars->win, (vars->img)->img, 0, 0);
	return (vars->infos->img_sprite->status);
}

void	tex_to_img_sprite(t_vars *vars, t_img_sprite *img_sprite)
{
	img_sprite->img_one->img = mlx_xpm_file_to_image(vars->mlx, \
	"./texture/spritebluno1.xpm", &(img_sprite->img_one_width), \
	&(img_sprite->img_one_height));
	img_sprite->img_one->addr = mlx_get_data_addr(img_sprite->img_one->img, \
	&(img_sprite->img_one->bits_per_pixel), \
	&(img_sprite->img_one->line_length), &(img_sprite->img_one->endian));
	img_sprite->img_two->img = mlx_xpm_file_to_image(vars->mlx, \
	"./texture/spritebluno2.xpm", &(img_sprite->img_two_width), \
	&(img_sprite->img_two_height));
	img_sprite->img_two->addr = mlx_get_data_addr(img_sprite->img_two->img, \
	&(img_sprite->img_two->bits_per_pixel), \
	&(img_sprite->img_two->line_length), &(img_sprite->img_two->endian));
	img_sprite->img_three->img = mlx_xpm_file_to_image(vars->mlx, \
	"./texture/spritebluno3.xpm", &(img_sprite->img_three_width), \
	&(img_sprite->img_three_height));
	img_sprite->img_three->addr = mlx_get_data_addr(img_sprite->img_three->img, \
	&(img_sprite->img_three->bits_per_pixel), \
	&(img_sprite->img_three->line_length), &(img_sprite->img_three->endian));
}

void	sprite_ges(t_vars *vars, t_infos *infos)
{
	t_img_sprite	*img_sprite;

	img_sprite = malloc(sizeof(t_img_sprite));
	img_sprite->status = 1;
	img_sprite->img_one = malloc(sizeof(t_data));
	img_sprite->img_three = malloc(sizeof(t_data));
	img_sprite->img_two = malloc(sizeof(t_data));
	tex_to_img_sprite(vars, img_sprite);
	infos->img_sprite = img_sprite;
}
