/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:57:30 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/08 21:57:50 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_check_map(t_pars *pars, t_sprite_lst *sprite)
{
	printf("Error\n");
	printf("Invalid map dude\n");
	ft_lst_sprite_clear(&sprite);
	free_t_pars(pars);
	exit(1);
}
