/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_point_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:35:47 by amonier           #+#    #+#             */
/*   Updated: 2023/10/19 21:38:07 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point_lst	*ft_lst_point_last(t_point_lst *lst)
{
	t_point_lst	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != 0)
		temp = temp->next;
	return (temp);
}
