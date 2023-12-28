/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:38:38 by amonier           #+#    #+#             */
/*   Updated: 2023/10/11 18:18:23 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_image(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < IMG_LENGTH)
	{
		while (j < IMG_WIDTH)
		{
			my_mlx_pixel_put(img, i, j, 0x00000000);
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}
