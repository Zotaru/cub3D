/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:34:04 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/12 17:44:12 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	malloc_error_tex(t_texture *tex, t_vars *vars)
{
	if (tex->img_no)
		free(tex->img_no);
	if (tex->img_so)
		free(tex->img_so);
	if (tex->img_we)
		free(tex->img_we);
	if (tex->img_ea)
		free(tex->img_ea);
	destroy_bis(vars);
	exit (1);
}

void	check_open(t_texture *tex, t_vars *vars)
{
	if (!is_valid_xpm(tex->no) || !is_valid_xpm(tex->so)
		|| !is_valid_xpm(tex->we) || !is_valid_xpm(tex->ea))
	{
		if (tex->img_no)
			free(tex->img_no);
		if (tex->img_so)
			free(tex->img_so);
		if (tex->img_we)
			free(tex->img_we);
		if (tex->img_ea)
			free(tex->img_ea);
		destroy_bis(vars);
		ft_printf("Error\n");
		ft_printf("Texture file is not valid path\n");
		exit (1);
	}
}

void	parse_tex(t_texture *tex, t_vars *vars)
{
	check_lines(tex, vars);
	tex->no = ft_strduppos(tex->no, 3, end_line(tex->no));
	tex->so = ft_strduppos(tex->so, 3, end_line(tex->so));
	tex->we = ft_strduppos(tex->we, 3, end_line(tex->we));
	tex->ea = ft_strduppos(tex->ea, 3, end_line(tex->ea));
	if (check_null_str(tex))
		malloc_error_tex(tex, vars);
	check_open(tex, vars);
}

void	fill_tex(t_texture *tex, t_vars *vars)
{
	tex->img_no->img = mlx_xpm_file_to_image(vars->mlx, tex->no, \
	&(tex->no_width), &(tex->no_height));
	tex->img_so->img = mlx_xpm_file_to_image(vars->mlx, tex->so, \
	&(tex->so_width), &(tex->so_height));
	tex->img_we->img = mlx_xpm_file_to_image(vars->mlx, tex->we, \
	&(tex->we_width), &(tex->we_height));
	tex->img_ea->img = mlx_xpm_file_to_image(vars->mlx, tex->ea, \
	&(tex->ea_width), &(tex->ea_height));
	tex->img_no->addr = mlx_get_data_addr(tex->img_no->img, \
	&(tex->img_no->bits_per_pixel), &(tex->img_no->line_length), \
	&(tex->img_no->endian));
	tex->img_so->addr = mlx_get_data_addr(tex->img_so->img, \
	&(tex->img_so->bits_per_pixel), &(tex->img_so->line_length), \
	&(tex->img_so->endian));
	tex->img_we->addr = mlx_get_data_addr(tex->img_we->img, \
	&(tex->img_we->bits_per_pixel), &(tex->img_we->line_length), \
	&(tex->img_we->endian));
	tex->img_ea->addr = mlx_get_data_addr(tex->img_ea->img, \
	&(tex->img_ea->bits_per_pixel), &(tex->img_ea->line_length), \
	&(tex->img_ea->endian));
}

void	texture_check(t_infos *info, t_vars *vars)
{
	info->texture->img_no = malloc(sizeof(t_data));
	info->texture->img_so = malloc(sizeof(t_data));
	info->texture->img_we = malloc(sizeof(t_data));
	info->texture->img_ea = malloc(sizeof(t_data));
	info->texture->ftab = NULL;
	info->texture->ctab = NULL;
	if (check_null_img(info->texture))
		malloc_error_tex(info->texture, vars);
	parse_tex(info->texture, vars);
	fill_tex(info->texture, vars);
}
