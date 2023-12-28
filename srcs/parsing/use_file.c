/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:05:14 by amonier           #+#    #+#             */
/*   Updated: 2023/12/11 16:51:20 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_string_begin_line(t_pars *pars,
	char *string, char **string_to_init)
{
	int	i;

	i = 0;
	while ((pars->file)[i] != NULL &&
		ft_strncmp(string, (pars->file)[i], ft_strlen(string)) != 0)
		i++;
	if ((pars->file)[i] != NULL &&
		ft_strncmp(string, (pars->file)[i], ft_strlen(string)) == 0)
	{
		*string_to_init = ft_strdup((pars->file)[i]);
		if (*string_to_init == NULL)
		{
			free_t_pars(pars);
			exit(1);
		}
	}
	(void)string_to_init;
	return ;
}

int	count_start_of_line(t_pars *pars, char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while ((pars->file)[i])
	{
		if (ft_strncmp((pars->file)[i], str, ft_strlen(str)) == 0)
			count++;
		i++;
	}
	return (count);
}

void	escape_null(t_pars *pars)
{
	free_t_pars(pars);
	ft_printf("Error\n");
	ft_printf("Invalid number of arg\n");
	exit (1);
}

void	check_double_start(t_pars *pars)
{
	if (count_start_of_line(pars, "NO ") != 1)
		escape_null(pars);
	if (count_start_of_line(pars, "SO ") != 1)
		escape_null(pars);
	if (count_start_of_line(pars, "WE ") != 1)
		escape_null(pars);
	if (count_start_of_line(pars, "EA ") != 1)
		escape_null(pars);
	if (count_start_of_line(pars, "F ") != 1)
		escape_null(pars);
	if (count_start_of_line(pars, "C ") != 1)
		escape_null(pars);
}

void	use_file(t_pars *pars)
{
	check_double_start(pars);
	find_string_begin_line(pars, "NO ", &(pars->no));
	find_string_begin_line(pars, "SO ", &(pars->so));
	find_string_begin_line(pars, "WE ", &(pars->we));
	find_string_begin_line(pars, "EA ", &(pars->ea));
	find_string_begin_line(pars, "F ", &(pars->f));
	find_string_begin_line(pars, "C ", &(pars->c));
	extract_map(pars);
	return ;
}
