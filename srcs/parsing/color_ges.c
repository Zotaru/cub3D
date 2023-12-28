/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:16:21 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/12 02:56:59 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	double_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*temp_to_tab(char **temp, t_vars *vars)
{
	int	i;
	int	*t;

	i = 0;
	if (double_size(temp) != 3)
		return (free_double_tab_char(temp), NULL);
	t = malloc(3 * sizeof(int));
	if (!t)
		exit_color(vars);
	while (temp[i])
	{
		if (ft_strlen(temp[i]) > 3)
			return (free_color(t, temp), NULL);
		t[i] = ft_atoi(temp[i]);
		if (t[i] > 255 || t[i] < 0)
			return (free_color(t, temp), NULL);
		i++;
	}
	return (free_double_tab_char(temp), t);
}

int	check_digit(t_texture *tex)
{
	int	i;

	i = 2;
	while (tex->f[i] && tex->f[i] != '\n')
	{
		if (!ft_isdigit(tex->f[i]) && tex->f[i] != ',')
			return (0);
		i++;
	}
	if (i == 2)
		return (0);
	i = 2;
	while (tex->c[i] && tex->c[i] != '\n')
	{
		if (!ft_isdigit(tex->c[i]) && tex->c[i] != ',')
			return (0);
		i++;
	}
	if (i == 2)
		return (0);
	return (1);
}

void	dup_all(t_texture *tex, t_vars *vars)
{
	tex->f = ft_strduppos(tex->f, 2, end_line(tex->f));
	tex->c = ft_strduppos(tex->c, 2, end_line(tex->c));
	if (!tex->f || !tex->c)
		exit_color(vars);
}

void	color_check(t_infos *info, t_vars *vars)
{
	char	**temp;

	if (!check_digit(info->texture))
	{
		ft_printf("Error\n");
		ft_printf("On a dit RGB : intR,intG,intB\n");
		exit_color(vars);
	}
	dup_all(info->texture, vars);
	temp = ft_split(info->texture->f, ',');
	info->texture->ftab = temp_to_tab(temp, vars);
	temp = ft_split(info->texture->c, ',');
	info->texture->ctab = temp_to_tab(temp, vars);
	if (!info->texture->ftab || !info->texture->ctab)
	{
		ft_printf("Error\n");
		ft_printf("C'est pas du RGB là try again\n");
		exit_color(vars);
	}
}
