/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:47:01 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 22:49:22 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__init_raycast_data(t_player *player, int x)
{
	double	cam;

	cam = 2 * x / (double)SCREEN_WIDTH - 1;
	player->ray_dirx = player->dirx + player->planex * cam;
	player->ray_diry = player->diry + player->planey * cam;
	player->mapx = (int)player->posx;
	player->mapy = (int)player->posy;
	player->deltadistx = fabs(1 / player->ray_dirx);
	player->deltadisty = fabs(1 / player->ray_diry);
}

void	__draw_image(t_program_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (data->buff[y][x] == 0x0 && y < SCREEN_HEIGHT / 2)
				__draw_pixel(&data->cub, x, y, __create_rgb(data->parsed->c_r,
						data->parsed->c_g, data->parsed->c_b));
			else if (data->buff[y][x] == 0x0 && y > SCREEN_HEIGHT / 2)
				__draw_pixel(&data->cub, x, y, __create_rgb(data->parsed->f_r,
						data->parsed->f_g, data->parsed->f_b));
			else
				__draw_pixel(&data->cub, x, y, data->buff[y][x]);
			x++;
		}
		y++;
	}
}

int	__end_game(t_program_data *data)
{
	__putstr_fd("Wall collisions not handled in our cub3d\n", 2);
	__quit(data);
	return (__SUCCESS);
}

void	__reset_buff(int **buffer)
{
	int	i;
	int	j;

	j = -1;
	while (++j < SCREEN_HEIGHT)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			buffer[j][i] = 0;
	}
}

int	__raycast_loop(t_program_data *data)
{
	int				x;
	static size_t	next_frame;
	size_t			current_time;

	x = -1;
	next_frame = 0;
	current_time = __get_time();
	__reset_buff(data->buff);
	if (current_time >= next_frame)
	{
		while (++x < SCREEN_WIDTH)
		{
			if (data->parsed->map_desc[(int)data->player->posx]
				[(int)data->player->posy] == '1')
				return (__end_game(data));
			next_frame = current_time + 1000 / 60;
			__init_raycast_data(data->player, x);
			__dda(data, data->player);
			__init_drawing_data(data, x);
		}
		__draw_image(data);
		__put_image_to_window(data);
	}
	return (__SUCCESS);
}
