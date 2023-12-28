/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:38:36 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/08 17:54:22 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_sprite_lst	*ft_lst_sprite_new(int x, int y)
{
	t_sprite_lst	*result;

	result = malloc(sizeof(t_sprite_lst));
	if (result == NULL)
		return (NULL);
	result->pos_x = x;
	result->pos_y = y;
	result->next = NULL;
	return (result);
}

t_sprite_lst	*ft_lst_sprite_last(t_sprite_lst *lst)
{
	t_sprite_lst	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != 0)
		temp = temp->next;
	return (temp);
}

void	ft_lst_sprite_clear(t_sprite_lst **lst)
{
	t_sprite_lst	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

void	ft_lst_sprite_addback(t_sprite_lst **lst, t_sprite_lst *new)
{
	t_sprite_lst	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = ft_lst_sprite_last(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
}
