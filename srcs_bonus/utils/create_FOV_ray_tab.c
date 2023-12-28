/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_FOV_ray_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:07 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 19:50:25 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// en gros j ai juste besoin d une seule chose
// c est le nombre de rayon
// j ai l impression d en avoir 321 
// car count marque 321 
// et je commence a 0 et finis donc de lancer des rayons a 320
// ce qui pourrait etre faux 
// mais a voir
// j ai donc juste besoin de SCREEN_L_PX
t_ray_fov	*create_fov_ray_tab(t_vars *vars, t_infos *infos)
{
	t_ray_fov	*final;
	int			i;
	t_ray		*new_ray;
	double		step_angle_degree;
	double		step;

	i = 0;
	step = 0.0;
	step_angle_degree = FOV / ((double) SCREEN_L_PX);
	new_ray = create_new_rotate_ray(vars, \
		(infos->body_player)->front_ray, - (FOV / 2.0) - step_angle_degree);
	final = malloc(sizeof(t_ray_fov) * (SCREEN_L_PX + 1));
	while (i < (SCREEN_L_PX + 1))
	{
		(final[i]).ray = \
			create_new_rotate_ray(vars, new_ray, step + step_angle_degree);
		step = step + step_angle_degree;
		i++;
	}
	free(new_ray);
	return (final);
}

void	rotate_fov(t_ray_fov *fov_tab, double angle)
{
	int	i;

	i = 0;
	while (i < (SCREEN_L_PX + 1))
	{
		rotate_ray(fov_tab[i].ray, angle);
		i++;
	}
	return ;
}

void	free_fov_ray_tab(t_ray_fov *fov_tab)
{
	int	i;

	i = 0;
	while (i < (SCREEN_L_PX + 1))
	{
		free(fov_tab[i].ray);
		i++;
	}
	free(fov_tab);
}
