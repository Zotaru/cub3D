/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:21:46 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 16:49:31 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	julia_click(t_vars *mlx, int x, int y)
// {
// 	mlx->julia_x = (x * ((mlx->axe)->x_max - (mlx->axe)->x_min) / IMG_LENGTH)
// 		+ (mlx->axe)->x_min;
// 	mlx->julia_y = (mlx->axe)->y_max - (y * ((mlx->axe)->y_max
// 				- (mlx->axe)->y_min) / IMG_WIDTH);
// 	clear_image(mlx->img);
// 	my_mlx_julia_fract(mlx->img, mlx->julia_x, mlx->julia_y, *(mlx->axe));
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, (mlx->img)->img, 0, 0);
// }

int	mouse_hook(int keycode, int x, int y, t_vars *mlx)
{
	int	i;

	(void) x;
	(void) y;
	(void) mlx;
	if (keycode == 4)
		i = 0;
	if (keycode == 5)
		i = 0;
	return (i);
}
