/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:01:11 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/08 22:04:34 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_double_char(char **str)
{
	int	position;

	position = 0;
	while (str[position])
	{
		printf("%s", str[position]);
		position++;
	}
	return ;
}

void	print_wall(t_wall_lst *wall)
{
	t_wall_lst	*temp;

	temp = wall;
	while (temp)
	{
		printf("------------------\n");
		printf("xstart :%f, ystart:%f\n", temp->x_start, temp->y_start);
		printf("x_end: %f, y_end:: %f\n", temp->x_end, temp->y_end);
		temp = temp->next;
	}
}
