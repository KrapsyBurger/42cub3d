/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:01:06 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/22 19:46:12 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	__idx_positioning_and_malloc(t_parsing *data, int *len,
	int *start, int *line_counter)
{
	if (!data->full_map[*len])
		return (1);
	while (!__isalnum(data->full_map[*len]) && data->full_map[*len])
		*len += 1;
	if (!data->full_map[*len])
		return (1);
	while (data->full_map[*len] != '\n')
		*len -= 1;
	*len += 1;
	*start = *len;
	while (data->full_map[*len])
	{
		if (data->full_map[*len] == '\n')
			*line_counter += 1;
		*len += 1;
	}
	data->map_desc = malloc(sizeof(char *) * (*line_counter + 2));
	*len = *start;
	while (data->full_map[*len] != '\n')
		*len += 1;
	data->map_desc[0] = __substr(data->full_map, *start, *len - *start);
	data->map_desc[0] = __strtrim(data->map_desc[0], "\r");
	*start = *len;
	*len += 1;
	return (0);
}

int	__map_desc_parse(t_parsing *data, int len, int start)
{
	int	line_counter;
	int	map_tab_idx;

	line_counter = 0;
	map_tab_idx = 1;
	if (__idx_positioning_and_malloc(data, &len, &start, &line_counter) == 1)
		return (1);
	while (data->full_map[len])
	{
		if (data->full_map[len] == '\n')
		{
			data->map_desc[map_tab_idx] = __substr(data->full_map,
					start + 1, len - start - 1);
			data->map_desc[map_tab_idx] = __strtrim(data->map_desc[map_tab_idx],
					"\r");
			map_tab_idx++;
			start = len;
		}
		len++;
	}
	data->map_desc[map_tab_idx] = __substr(data->full_map, start + 1,
			__strlen(data->full_map) - start);
	data->map_desc[map_tab_idx] = __strtrim(data->map_desc[map_tab_idx], "\r");
	data->map_desc[map_tab_idx + 1] = NULL;
	return (0);
}

int	__elem_parse_helper(t_parsing *data, int *start, int *len, int i)
{
	char	*elem;

	while (i < 6)
	{
		while (!__isalnum(data->full_map[*len]))
			*len += 1;
		*start = *len;
		while (__isalnum(data->full_map[*len]))
			*len += 1;
		if (data->full_map[*len] == ' ' || data->full_map[*len] == '\t')
		{
			elem = __substr(data->full_map, *start, *len - *start);
			if (__elem_compare(elem) == 6)
				return (__free(elem),
					__putstr_fd("Error\nParsing elements failed\n", 2), 1);
			*start = *len;
			__elem_saving(data, len, __elem_compare(elem));
			__jump_to_next_elem(data->full_map, len, start);
			i++;
			__free(elem);
		}
		else
			return (__putstr_fd("Error\nParsing elements failed\n", 2), 1);
	}
	return (0);
}

int	__parsing(t_program_data *data, int len)
{
	int		start;

	start = 0;
	if (__elem_parse_helper(data->parsed, &start, &len, 0) == 1)
		return (1);
	if (__elements_check(data->parsed) == 1)
		return (1);
	if (__map_desc_parse(data->parsed, len, start) == 1)
		return (__putstr_fd("Error\nNo map in file.\n", 2), 1);
	if (__is_map_closed_check(data->parsed->map_desc) == 1)
		return (1);
	__rgb_c_getter(data->parsed);
	__rgb_f_getter(data->parsed);
	return (0);
}

int	__map_opening(t_parsing *data, char *s)
{
	if (__cub_checker(s) == 0)
		return (__putstr_fd("Error\nFile's format isn't right.\n", 2), 2);
	data->map_fd = open(s, O_RDONLY);
	if (data->map_fd == -1)
		return (__putstr_fd("Error\nFile can not be opened.\n", 2), 2);
	return (0);
}
