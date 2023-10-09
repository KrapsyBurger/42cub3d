/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:29:39 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__draw_on_buffer_picture(t_program_data *data,
			t_drawing *drawing, int x)
{
	int		y;
	int		color;
	int		tex_y;
	double	tex_pos;

	tex_pos = (drawing->draw_start - SCREEN_HEIGHT
			/ 2 + drawing->line_height / 2) * drawing->step;
	y = drawing->draw_start;
	while (y < drawing->draw_end)
	{
		tex_y = (int)tex_pos & (BLOCK_SIZE - 1);
		tex_pos += drawing->step;
		color = data->textures[data->text_num][BLOCK_SIZE
			* tex_y + drawing->text_x];
		if (data->side == 1)
			color = (color >> 1) & 8355711;
		data->buff[y][x] = color;
		data->reset = 1;
		y++;
	}
}

void	__get_drawing_data(t_drawing *drawing, t_program_data *data)
{
	data->draw->line_height = (int)(SCREEN_HEIGHT / data->player->perpwall);
	data->draw->draw_start = -(data->draw->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (data->draw->draw_start < 0)
		data->draw->draw_start = 0;
	data->draw->draw_end = data->draw->line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->draw->draw_end >= SCREEN_HEIGHT)
		data->draw->draw_end = SCREEN_HEIGHT - 1;
	drawing->text_x = (int)(drawing->wallx * (double)BLOCK_SIZE);
	if (data->side == 0 && data->player->ray_dirx > 0)
			drawing->text_x = BLOCK_SIZE - drawing->text_x - 1;
	if (data->side == 1 && data->player->ray_diry < 0)
			drawing->text_x = BLOCK_SIZE - drawing->text_x - 1;
	drawing->step = 1.0 * BLOCK_SIZE / drawing->line_height;
}

void	__init_drawing_data(t_program_data *data, int x)
{
	if (data->side == 0 && data->player->ray_dirx < 0)
		data->text_num = 1;
	if (data->side == 0 && data->player->ray_dirx >= 0)
		data->text_num = 0;
	if (data->side == 1 && data->player->ray_diry < 0)
		data->text_num = 2;
	if (data->side == 1 && data->player->ray_diry >= 0)
		data->text_num = 3;
	if (data->side == 0)
		data->draw->wallx = data->player->posy
			+ data->player->perpwall * data->player->ray_diry;
	else
		data->draw->wallx = data->player->posx
			+ data->player->perpwall * data->player->ray_dirx;
	data->draw->wallx -= floor(data->draw->wallx);
	__get_drawing_data(data->draw, data);
	__draw_on_buffer_picture(data, data->draw, x);
}
