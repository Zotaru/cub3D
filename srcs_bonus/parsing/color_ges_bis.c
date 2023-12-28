/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ges_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:38:55 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/08 20:55:29 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_color(t_vars *vars)
{
	destroy_tex(vars);
	destroy_bis(vars);
	exit (1);
}

void	free_color(int *t, char **temp)
{
	free(t);
	free_double_tab_char(temp);
}
