/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:35:28 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/21 23:35:45 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	__map_valid_elem_compare(int one, int player, int zero)
{
	if (zero == 0 && player == 0)
		return (__putstr_fd("Error\nMap got no floor.\n", 2), 1);
	if (one == 0)
		return (__putstr_fd("Error\nMap got no walls.\n", 2), 1);
	if (player > 1)
		return (__putstr_fd("Error\nCan't have many players.\n", 2), 1);
	if (player == 0)
		return (__putstr_fd("Error\nNo player in the map.\n", 2), 1);
	return (0);
}

int	__map_valid_elem_in_map_check(char **map, int t_i, int s_i)
{
	int		one;
	int		player;
	int		zero;

	one = 0;
	player = 0;
	zero = 0;
	while (map[++t_i])
	{
		while (map[t_i][++s_i])
		{
			if (map[t_i][s_i] == '0')
				zero++;
			else if (map[t_i][s_i] == '1')
				one++;
			else if (map[t_i][s_i] == 'N' || map[t_i][s_i] == 'W' ||
					map[t_i][s_i] == 'E' || map[t_i][s_i] == 'S')
				player++;
		}
		s_i = -1;
	}
	return (__map_valid_elem_compare(one, player, zero));
}

int	__is_there_space(char *s, int a)
{
	int	i;

	i = 0;
	if (a == 0)
	{
		if (s[0] == ' ' || s[0] == '\t')
			return (1);
		if (s[__strlen(s) - 1] == ' ' || s[__strlen(s) - 1] == '\t')
			return (1);
	}
	else if (a == 1)
	{
		if (!s)
			return (1);
		while (s[i])
		{
			if (s[i] == ' ' || s[i] == '\t')
				return (1);
			else
				i++;
		}
	}
	return (0);
}

int	__comma_counter(char *s)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (s[i])
	{
		if (s[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

int	__elements_check(t_parsing *data)
{
	if (data->color_f == NULL)
		return (__putstr_fd("Error\nParsing elements failed.\n", 2), 1);
	if (__comma_counter(data->color_f) != 2
		|| __is_there_enough_values(data->color_f, 0, -1, 0) == 1)
		return (__putstr_fd("Error\nWrong F color.\n", 2), 1);
	if (data->color_c == NULL)
		return (__putstr_fd("Error\nParsing elements failed.\n", 2), 1);
	if (__comma_counter(data->color_c) != 2
		|| __is_there_enough_values(data->color_c, 0, -1, 0) == 1)
		return (__putstr_fd("Error\nWrong C color.\n", 2), 1);
	if (__is_there_space(data->path_no, 1) == 1
		|| __is_there_space(data->path_so, 1) == 1
		|| __is_there_space(data->path_we, 1) == 1
		|| __is_there_space(data->path_ea, 1) == 1)
		return (__putstr_fd("Error\nParsing elements failed.\n", 2), 1);
	else
		return (0);
}
