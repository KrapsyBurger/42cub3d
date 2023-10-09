/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:58:16 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/21 18:17:12 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	__fill_buf_with_zero(t_program_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			data->buff[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	__malloc_lines_for_buf(t_program_data *data)
{
	int	i;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		data->buff[i] = (int *)malloc(sizeof(int)
				* (BLOCK_SIZE * SCREEN_WIDTH));
		if (!data->buff[i])
			return (__putstr_fd("Error\nMalloc buff failed.", 2), -1);
		i++;
	}
	return (0);
}

int	__init_buf(t_program_data *data)
{
	int	err;

	err = 0;
	data->buff = (int **)malloc(sizeof(int *) * SCREEN_HEIGHT);
	if (!data->buff)
		return (__putstr_fd("Error\nMalloc buff failed.", 2), -1);
	err = __malloc_lines_for_buf(data);
	if (err)
		return (err);
	__fill_buf_with_zero(data);
	return (0);
}
