/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:22:32 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/08 23:23:03 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_wall_one(t_wall_lst *temp, t_wall_lst **wall, int i, int j)
{
	temp = ft_lst_wall_new(i, j + 1, i + 1, j + 1);
	temp->norm_x = 0.0;
	temp->norm_y = -1.0;
	ft_lst_wall_addback(wall, temp);
}

void	find_wall_two(t_wall_lst *temp, t_wall_lst **wall, int i, int j)
{
	temp = ft_lst_wall_new(i, j, i + 1, j);
	temp->norm_x = 0.0;
	temp->norm_y = 1.0;
	ft_lst_wall_addback(wall, temp);
}

void	find_wall_three(t_wall_lst *temp, t_wall_lst **wall, int i, int j)
{
	temp = ft_lst_wall_new(i + 1, j, i + 1, j + 1);
	temp->norm_x = -1.0;
	temp->norm_y = 0.0;
	ft_lst_wall_addback(wall, temp);
}

void	find_wall_four(t_wall_lst *temp, t_wall_lst **wall, int i, int j)
{
	temp = ft_lst_wall_new(i, j, i, j + 1);
	temp->norm_x = 1.0;
	temp->norm_y = 0.0;
	ft_lst_wall_addback(wall, temp);
}
