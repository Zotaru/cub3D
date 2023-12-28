/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifying_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:22:44 by amonier           #+#    #+#             */
/*   Updated: 2023/12/10 17:17:51 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// faire attention aux normes qui devrqient etre juste

int	if_one(t_wall_lst **temp, t_wall_lst **prec, t_wall_lst **act)
{
	(*temp)->x_start = (*act)->x_start;
	(*temp)->y_start = (*act)->y_start;
	(*prec)->next = (*act)->next;
	free(*act);
	*act = (*prec)->next;
	return (1);
}

int	if_two(t_wall_lst **temp, t_wall_lst **prec, t_wall_lst **act)
{
	(*temp)->x_end = (*act)->x_end;
	(*temp)->y_end = (*act)->y_end;
	(*prec)->next = (*act)->next;
	free(*act);
	*act = (*prec)->next;
	return (1);
}

int	norm_wall(t_wall_lst **temp, t_wall_lst **prec, t_wall_lst **act)
{
	int	i;

	i = 0;
	if ((*temp)->x_start == (*act)->x_end && (*temp)->y_start == (*act)->y_end)
	{
		if ((*temp)->x_end == (*act)->x_start
			|| (*temp)->y_end == (*act)->y_start)
			i += if_one(temp, prec, act);
	}
	else if ((*temp)->x_end == (*act)->x_start
		&& (*temp)->y_end == (*act)->y_start)
	{
		if ((*temp)->x_start == (*act)->x_end
			|| (*temp)->y_start == (*act)->y_end)
			i += if_two(temp, prec, act);
	}
	return (i);
}

void	simplifying_wall(t_wall_lst **wall)
{
	t_wall_lst	*temp;
	t_wall_lst	*prec;
	t_wall_lst	*act;
	int			found;

	found = 0;
	temp = *wall;
	prec = *wall;
	act = temp->next;
	while (temp)
	{
		while (act)
		{
			found += norm_wall(&temp, &prec, &act);
			prec = prec->next;
			if (act)
				act = act->next;
		}
		if (found == 0)
			temp = temp->next;
		found = 0;
		if (temp)
			act = temp->next;
		prec = temp;
	}
}
