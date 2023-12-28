/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:27:03 by amonier           #+#    #+#             */
/*   Updated: 2023/12/11 16:51:13 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_t_pars(t_pars *pars)
{
	if (pars->file != NULL)
		free_double_tab_char(pars->file);
	if (pars->no != NULL)
		free(pars->no);
	if (pars->so != NULL)
		free(pars->so);
	if (pars->we != NULL)
		free(pars->we);
	if (pars->ea != NULL)
		free(pars->ea);
	if (pars->f != NULL)
		free(pars->f);
	if (pars->c != NULL)
		free(pars->c);
	if (pars->map != NULL)
		free_double_tab_char(pars->map);
	if (pars->player_info != NULL)
		free(pars->player_info);
	free(pars);
}
