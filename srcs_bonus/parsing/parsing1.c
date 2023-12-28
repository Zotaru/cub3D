/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:00:37 by wfreulon          #+#    #+#             */
/*   Updated: 2023/12/11 16:51:16 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_infos	*fill_infos(t_infos *infos, t_pars *pars)
{
	infos->player = pars->player_info;
	(infos->map)->map = pars->map;
	(infos->map)->size_x = ft_strlen((pars->map)[0]);
	(infos->map)->size_y = nb_line_double_tab(pars->map);
	(infos->texture)->no = pars->no;
	(infos->texture)->so = pars->so;
	(infos->texture)->we = pars->we;
	(infos->texture)->ea = pars->ea;
	(infos->texture)->f = pars->f;
	(infos->texture)->c = pars->c;
	return (infos);
}

t_infos	*pars_to_info(t_pars *pars)
{
	t_infos	*infos;

	infos = malloc(sizeof(t_infos));
	if (infos == NULL)
	{
		free_t_pars(pars);
		exit(1);
	}
	infos->texture = malloc(sizeof(t_texture));
	if (infos->texture == NULL)
	{
		free(infos);
		free_t_pars(pars);
		exit(1);
	}
	infos->map = malloc(sizeof(t_map));
	if (infos->map == NULL)
	{
		free(infos->texture);
		free(infos);
		free_t_pars(pars);
		exit(1);
	}
	infos = fill_infos(infos, pars);
	return (infos);
}

void	exit_file(t_pars *temp)
{
	free(temp);
	exit(1);
}

void	error_file(t_pars *temp)
{
	perror("Error opening file");
	free(temp->file);
	exit_file(temp);
}

void	copy_file(char **argv, t_pars *temp)
{
	int		count_line;
	int		fd;
	char	*line;
	int		position;

	position = 0;
	count_line = count_nb_line_file(argv, temp);
	temp->file = malloc(sizeof(char *) * (count_line + 1));
	if (temp->file == NULL)
		exit_file(temp);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_file(temp);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(temp->file)[position] = line;
		position++;
	}
	close(fd);
	(temp->file)[position] = NULL;
	return ;
}
