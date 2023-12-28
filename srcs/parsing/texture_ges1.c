/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ges1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:27:01 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 18:43:38 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_info_bis(t_infos *infos)
{
	if ((infos->texture)->no != NULL)
		free((infos->texture)->no);
	if ((infos->texture)->so != NULL)
		free((infos->texture)->so);
	if ((infos->texture)->we != NULL)
		free((infos->texture)->we);
	if ((infos->texture)->ea != NULL)
		free((infos->texture)->ea);
	if ((infos->texture)->f != NULL)
		free((infos->texture)->f);
	if ((infos->texture)->c != NULL)
		free((infos->texture)->c);
	if ((infos->texture)->ftab != NULL)
		free((infos->texture)->ftab);
	if ((infos->texture)->ctab != NULL)
		free((infos->texture)->ctab);
	free(infos->texture);
	free(infos->player);
	free_double_tab_char((infos->map)->map);
	free(infos->map);
	ft_lst_wall_clear(&(infos->wall));
	ft_lst_sprite_clear(&(infos->sprite));
	free(infos);
	return ;
}

void	destroy_bis(t_vars *vars)
{
	free_info_bis(vars->infos);
	mlx_destroy_image(vars->mlx, (vars->img)->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->img);
	free(vars);
	return ;
}

char	*ft_strduppos(char *src, int start, int ending)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(((ending - start) + 2) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[start] && start <= ending)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

int	end_line(char *line)
{
	int	i;

	i = 3;
	while (line[i] && line[i] != '\n' && line[i] != ' ')
	{
		i++;
	}
	return (i - 1);
}

int	is_valid_xpm(char *line)
{
	int	temp_fd;

	temp_fd = open(line, O_RDONLY);
	if (temp_fd == -1)
		return (0);
	close(temp_fd);
	return (1);
}
