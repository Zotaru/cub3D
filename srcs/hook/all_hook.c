/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:13:43 by amonier           #+#    #+#             */
/*   Updated: 2023/10/11 17:39:44 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	all_hook(t_vars *vars)
{
	mlx_hook(vars->win, 17, 1L << 17, cross, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 2, 1L << 0, keyboard, vars);
}
