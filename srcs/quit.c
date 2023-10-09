/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:49:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/22 13:56:54 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__quit(t_program_data *data)
{
	int	size;
	int	*ptr;
	int	height;

	size = 4;
	ptr = &size;
	height = SCREEN_HEIGHT;
	__free_parsing_struct(data->parsed);
	mlx_destroy_image(data->cub.mlx, data->cub.img.new_img);
	mlx_destroy_window(data->cub.mlx, data->cub.win);
	mlx_destroy_display(data->cub.mlx);
	if (data->textures)
		__free_int_tab(data->textures, ptr);
	if (data->buff)
		__free_int_tab(data->buff, &height);
	__free(data->cub.mlx);
	__free(data->player);
	__free(data);
	exit(1);
}
