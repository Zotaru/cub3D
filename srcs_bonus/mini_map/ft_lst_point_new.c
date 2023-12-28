/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_point_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:56:29 by amonier           #+#    #+#             */
/*   Updated: 2023/10/20 20:42:03 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point_lst	*ft_lst_point_new(int x, int y, double x_p, double y_p)
{
	t_point_lst	*result;

	result = malloc(sizeof(t_point_lst));
	if (result == NULL)
		return (NULL);
	result->pixel_x = x;
	result->pixel_y = y;
	result->x_pos = x_p;
	result->y_pos = y_p;
	result->next = NULL;
	return (result);
}
