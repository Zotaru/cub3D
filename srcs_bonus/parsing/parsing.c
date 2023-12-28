/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:54:40 by amonier           #+#    #+#             */
/*   Updated: 2023/12/11 16:51:14 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_pars(t_pars *pars)
{
	pars->file = NULL;
	pars->no = NULL;
	pars->so = NULL;
	pars->we = NULL;
	pars->ea = NULL;
	pars->f = NULL;
	pars->c = NULL;
	pars->map = NULL;
	pars->player_info = NULL;
	return ;
}

void	good_format(char **argv, t_pars *temp)
{
	int	len;
	int	position;

	len = ft_strlen(argv[1]);
	if (len < 4)
	{
		free(temp);
		printf("Error\n");
		printf("Not the right argument\n");
		exit(1);
	}
	position = len - 4;
	if (ft_strncmp(".cub", (argv[1]) + position, 5) != 0)
	{
		free(temp);
		printf("Error\n");
		printf("Not the right argument\n");
		exit(1);
	}
	return ;
}

int	count_nb_line_file(char **argv, t_pars *temp)
{
	int		count_line;
	int		fd;
	char	*line;

	count_line = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(temp);
		perror("Error opening file");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count_line++;
		free(line);
	}
	close(fd);
	return (count_line);
}

void	arg_error(int argc)
{
	printf("Error\n");
	if (argc < 2)
		printf("Not enough argument\n");
	if (argc > 2)
		printf("Too many arguments\n");
	exit(1);
}

t_infos	*parsing(int argc, char **argv)
{
	t_pars			*pars;
	t_infos			*infos;
	t_sprite_lst	*sprite;	

	if (argc != 2)
		arg_error(argc);
	pars = malloc(sizeof(t_pars));
	if (pars == NULL)
		exit(1);
	init_pars(pars);
	good_format(argv, pars);
	copy_file(argv, pars);
	use_file(pars);
	new_map(pars);
	sprite = sprite_mapping(pars);
	check_map(pars, sprite);
	infos = pars_to_info(pars);
	infos->sprite = sprite;
	infos->wall = create_wall_lst(pars);
	free_double_tab_char(pars->file);
	free(pars);
	return (infos);
}
