/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:59:15 by amonier           #+#    #+#             */
/*   Updated: 2023/05/02 22:18:18 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_lstadd_back(t_ilist **lst, t_ilist *new)
{
	t_ilist	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
}
