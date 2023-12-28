/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_wall_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:44:17 by amonier           #+#    #+#             */
/*   Updated: 2023/10/27 10:47:45 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_wall_lst	*ft_lst_wall_new(int x, int y, int x_last, int y_last)
{
	t_wall_lst	*result;

	result = malloc(sizeof(t_wall_lst));
	if (result == NULL)
		return (NULL);
	result->x_start = x;
	result->y_start = y;
	result->x_end = x_last;
	result->y_end = y_last;
	result->next = NULL;
	return (result);
}
