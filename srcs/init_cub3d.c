/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:48:44 by ychibani          #+#    #+#             */
/*   Updated: 2023/10/24 16:21:06 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	__init_textures(t_program_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->textures = (int **)malloc(sizeof(int *) * 4);
	if (!data->textures)
		return (0);
	while (++i < 4)
	{
		data->textures[i] = (int *)malloc(sizeof(int)
				* (SCREEN_WIDTH * SCREEN_HEIGHT));
		if (!data->textures[i])
			return (__free_int_tab(data->textures, &i), __FAILURE);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < (SCREEN_WIDTH * SCREEN_HEIGHT))
			data->textures[i][j] = 0;
	}
	return (__SUCCESS);
}

int	__load_image(t_program_data *data, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	img->new_img = mlx_xpm_file_to_image(data->cub.mlx,
			path, &img->img_width, &img->img_height);
	if (!img->new_img)
		return (0);
	img->addr = (int *)mlx_get_data_addr(img->new_img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x]
				= (int)img->addr[img->img_width * y + x];
	}
	mlx_destroy_image(data->cub.mlx, img->new_img);
	return (__SUCCESS);
}

int	__load_textures(t_program_data *data)
{
	t_img	img;

	if (!__init_textures(data))
		return (__putstr_fd("Error\nTexture file corrupted.", 2),
			__quit(data), -1);
	if (!__load_image(data, data->textures[0], data->parsed->path_so, &img))
		return (__putstr_fd("Error\nTexture file corrupted.", 2),
			__quit(data), -1);
	if (!__load_image(data, data->textures[1], data->parsed->path_no, &img))
		return (__putstr_fd("Error\nTexture file corrupted.", 2),
			__quit(data), -1);
	if (!__load_image(data, data->textures[2], data->parsed->path_we, &img))
		return (__putstr_fd("Error\nTexture file corrupted.", 2),
			__quit(data), -1);
	if (!__load_image(data, data->textures[3], data->parsed->path_ea, &img))
		return (__putstr_fd("Error\nTexture file corrupted.", 2),
			__quit(data), -1);
	return (__SUCCESS);
}

static void	__init_speed_and_rotation(t_program_data *data)
{
	data->player->move_speed = 0.2;
	data->player->rotate_speed = 0.2;
}

int	__init_cub3d(t_program_data *data, char **av)
{
	t_drawing	drawing;

	__memset(&drawing, 0, sizeof(t_drawing));
	data->draw = &drawing;
	if (!data)
		return (__FAILURE);
	data->parsed = __calloc(1, sizeof(t_parsing));
	if (!data->parsed)
		return (__FAILURE);
	data->player = __calloc(1, sizeof(t_player));
	if (!data->player)
		return (__free(data->parsed), __FAILURE);
	if (__mlx_init(&data->cub) == __FAILURE)
		exit(1);
	if (__map_opening(data->parsed, av[1]) == 2)
		return (__FAILURE);
	if (__init_buf(data) == __FAILURE)
		return (__FAILURE);
	data->parsed->full_map = __fill_string(data->parsed->map_fd);
	__init_speed_and_rotation(data);
	return (1);
}
