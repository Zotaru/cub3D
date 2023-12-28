/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_point_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:18:56 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 23:40:20 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	color_point_lst(t_vars *vars, t_point_lst *point_lst, int color)
{
	t_point_lst	*temp;

	temp = point_lst;
	while (temp)
	{
		my_mlx_pixel_put(vars->img, temp->pixel_x, temp->pixel_y, color);
		temp = temp->next;
	}
}
