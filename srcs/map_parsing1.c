/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:58:19 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/22 22:04:59 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__sub_and_trim(char **s1, t_parsing *data, int len, int start)
{
	if (*s1)
		__free(*s1);
	*s1 = __substr(data->full_map, start, len - start);
	*s1 = __strtrim(*s1, "\r");
	while (__is_there_space(*s1, 0) == 1)
	{
		*s1 = __strtrim(*s1, " ");
		*s1 = __strtrim(*s1, "\t");
	}
}

void	__elem_saving(t_parsing *data, int *len, int direction)
{
	int	start;

	start = *len;
	while (data->full_map[*len] != '\n')
		*len += 1;
	if (direction == 0)
		__sub_and_trim(&data->path_no, data, *len, start);
	else if (direction == 1)
		__sub_and_trim(&data->path_so, data, *len, start);
	else if (direction == 2)
		__sub_and_trim(&data->path_we, data, *len, start);
	else if (direction == 3)
		__sub_and_trim(&data->path_ea, data, *len, start);
	else if (direction == 4)
		__sub_and_trim(&data->color_f, data, *len, start);
	else if (direction == 5)
		__sub_and_trim(&data->color_c, data, *len, start);
}

int	__map_char_checker(char **map, int tab_idx, int string_idx)
{
	char	c;

	c = 'A';
	while (map[tab_idx])
	{
		while (map[tab_idx][string_idx])
		{
			c = map[tab_idx][string_idx];
			if (c == '0' || c == '1' || c == 'N' || c == 'S'
				|| c == 'E' || c == 'W' || c == ' ' || c == '\n')
				string_idx++;
			else if (c == '\r')
				break ;
			else
				return (__putstr_fd("Error\nWrong char in map.\n", 2), 1);
		}
		if (c == '\r')
			break ;
		string_idx = 0;
		tab_idx++;
	}
	return (0);
}

int	__first_last_line_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '1' || s[i] == ' ' || s[i] == '\n')
			i++;
		else if (s[i] == '\r')
			break ;
		else
			return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
	}
	return (0);
}

int	__map_char_check_around(char **map, int tab_idx, int string_idx, char c)
{
	if (__map_check_around_helper(map, tab_idx, string_idx, c) == 1)
		return (1);
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (__strlen(map[tab_idx + 1]) < 1)
			return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
		c = map[tab_idx + 1][string_idx];
	}
	else
		return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	else
		return (__putstr_fd("Error\nMap isn't closed.\n", 2), 1);
	return (0);
}
