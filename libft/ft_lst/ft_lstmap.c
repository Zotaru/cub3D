/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:00:43 by amonier           #+#    #+#             */
/*   Updated: 2023/05/02 22:18:18 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_ilist	*ft_lstmap(t_ilist *lst, int (*f)(int), void (*del)(int))
{
	t_ilist	*new_list;
	t_ilist	*element;

	new_list = NULL;
	while (lst)
	{
		element = ft_lstnew((*f)(lst->content));
		if (element == NULL)
		{
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, element);
		lst = lst->next;
	}
	return (new_list);
}
