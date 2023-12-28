/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:38:37 by amonier           #+#    #+#             */
/*   Updated: 2023/12/11 16:51:07 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tex_infos(t_infos *infos)
{
	if ((infos->texture)->no != NULL)
		free((infos->texture)->no);
	if ((infos->texture)->so != NULL)
		free((infos->texture)->so);
	if ((infos->texture)->we != NULL)
		free((infos->texture)->we);
	if ((infos->texture)->ea != NULL)
		free((infos->texture)->ea);
	if ((infos->texture)->f != NULL)
		free((infos->texture)->f);
	if ((infos->texture)->c != NULL)
		free((infos->texture)->c);
}

void	free_t_infos(t_infos *infos)
{
	free_tex_infos(infos);
	ft_lst_sprite_clear(&(infos->sprite));
	free(infos->texture);
	free(infos->player);
	free_double_tab_char((infos->map)->map);
	free(infos->map);
	ft_lst_point_clear(&((infos->body_player)->body_point));
	free(infos->body_player->front_ray);
	free(infos->body_player->left_ray);
	free(infos->body_player->back_ray);
	free(infos->body_player->right_ray);
	free_fov_ray_tab(infos->body_player->fov_tab);
	free((infos->body_player));
	ft_lst_wall_clear(&(infos->wall));
	free(infos);
	return ;
}
