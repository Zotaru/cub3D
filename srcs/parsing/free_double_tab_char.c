/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_tab_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:55:36 by amonier           #+#    #+#             */
/*   Updated: 2023/12/08 21:59:47 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_double_tab_char(char **tab)
{
	int	position;

	position = 0;
	while (tab[position])
	{
		free(tab[position]);
		position++;
	}
	free(tab);
}
