/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:37:59 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/22 22:16:03 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	__is_map_closed_check(char **map)
{
	int		tab_idx;
	int		string_idx;
	char	c;

	tab_idx = 0;
	string_idx = -1;
	if (__first_last_line_check(map[tab_idx]) == 1
		|| __map_char_checker(map, tab_idx, string_idx + 1) == 1
		|| __map_valid_elem_in_map_check(map, tab_idx - 1, string_idx) == 1
		|| __first_last_line_check(map[__map_end(map) - 1]) == 1)
		return (1);
	while (map[++tab_idx])
	{
		while (map[tab_idx][++string_idx])
		{
			c = map[tab_idx][string_idx];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (__map_char_check_around(map, tab_idx, string_idx, c) == 1)
					return (1);
			}
		}
		string_idx = -1;
	}
	return (0);
}

int	__map_end(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	__is_there_enough_values(char *s, int commas, int i, int values)
{
	while (s[++i])
	{
		if (__isdigit(s[i]) && commas < 2)
		{
			values++;
			while (s[i] != ',')
			{
				if (!__isdigit(s[i]) && s[i] != ',')
					return (1);
				i++;
			}
			commas++;
		}
		if (!__isdigit(s[i]) && s[i] != ',')
			return (1);
		else if (values == 3)
			return (0);
		else if (__isdigit(s[i]))
			values++;
	}
	if (values == 3)
		return (0);
	return (1);
}

int	__map_check_around_helper(char **map, int tab_idx, int string_idx, char c)
{
	if (string_idx == (int)__strlen(map[tab_idx]))
		return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
	c = map[tab_idx][string_idx + 1];
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (string_idx == 0)
			return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
		c = map[tab_idx][string_idx - 1];
	}
	else
		return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (__strlen(map[tab_idx - 1]) < 1)
			return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
		c = map[tab_idx - 1][string_idx];
	}
	else
		return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
	return (0);
}
