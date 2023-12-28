/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ges2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:29:36 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/12 17:44:33 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_xpm(int i, char *line)
{	
	while (line[i] == ' ' || line[i] == '\n' || line[i] == '\0')
		i--;
	if (line[i] != 'm')
		return (0);
	i--;
	if (line[i] != 'p')
		return (0);
	i--;
	if (line[i] != 'x')
		return (0);
	i--;
	if (line[i] != '.')
		return (0);
	return (1);
}

int	end_line_err(char *line)
{
	int	i;

	i = 3;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' && (line[i + 1] != '\0' || line[i + 1] != '\n'))
			return (0);
		i++;
	}
	if (i == 3)
		return (0);
	if (!is_xpm(i, line))
		return (0);
	return (i);
}

void	check_lines(t_texture *tex, t_vars *vars)
{
	if (!end_line_err(tex->no) || !end_line_err(tex->so)
		|| !end_line_err(tex->we) || !end_line_err(tex->ea))
	{
		if (tex->img_no)
			free(tex->img_no);
		if (tex->img_so)
			free(tex->img_so);
		if (tex->img_we)
			free(tex->img_we);
		if (tex->img_ea)
			free(tex->img_ea);
		destroy_bis(vars);
		ft_printf("Error\n");
		ft_printf("Are you certain your .xpm file name is valid?\n");
		exit (1);
	}
}

int	check_null_str(t_texture *tex)
{
	if (tex->no == NULL)
		return (1);
	if (tex->so == NULL)
		return (1);
	if (tex->we == NULL)
		return (1);
	if (tex->ea == NULL)
		return (1);
	return (0);
}

int	check_null_img(t_texture *tex)
{
	if (tex->img_no == NULL)
		return (1);
	if (tex->img_so == NULL)
		return (1);
	if (tex->img_we == NULL)
		return (1);
	if (tex->img_ea == NULL)
		return (1);
	return (0);
}
