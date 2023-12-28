/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_wall_addback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:56:42 by amonier           #+#    #+#             */
/*   Updated: 2023/10/27 10:57:35 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_lst_wall_addback(t_wall_lst **lst, t_wall_lst *new)
{
	t_wall_lst	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = ft_lst_wall_last(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
}
