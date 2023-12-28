/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_point_addback.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:59:40 by amonier           #+#    #+#             */
/*   Updated: 2023/10/19 21:37:40 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_lst_point_addback(t_point_lst **lst, t_point_lst *new)
{
	t_point_lst	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = ft_lst_point_last(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
}
