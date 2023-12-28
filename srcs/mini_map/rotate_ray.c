/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:46:43 by amonier           #+#    #+#             */
/*   Updated: 2023/10/25 18:43:38 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// matrice de rotation: 
// (cos(a)   -sin(a))
// (sin(a)    cos(a))

// create new ray from first
t_ray	*create_new_rotate_ray(t_vars *vars, t_ray *ray_1, double angle)
{
	t_ray	*ray_2;
	double	radians;

	ray_2 = malloc(sizeof(t_ray));
	if (ray_2 == NULL)
	{
		destroy(vars);
		exit(1);
	}
	radians = degree_to_radian(angle);
	ray_2->ray_x = cos(radians) * ray_1->ray_x - sin(radians) * ray_1->ray_y;
	ray_2->ray_y = sin(radians) * ray_1->ray_x + cos(radians) * ray_1->ray_y;
	return (ray_2);
}

//rotate the actual ray
void	rotate_ray(t_ray *ray_1, double angle)
{
	double	radians;
	double	old_x;
	double	old_y;

	radians = degree_to_radian(angle);
	old_x = ray_1->ray_x;
	old_y = ray_1->ray_y;
	ray_1->ray_x = cos(radians) * old_x - sin(radians) * old_y;
	ray_1->ray_y = sin(radians) * old_x + cos(radians) * old_y;
	return ;
}
