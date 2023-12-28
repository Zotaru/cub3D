/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_wall_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:50:06 by amonier           #+#    #+#             */
/*   Updated: 2023/10/27 10:52:23 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_wall_lst	*ft_lst_wall_last(t_wall_lst *lst)
{
	t_wall_lst	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != 0)
		temp = temp->next;
	return (temp);
}
