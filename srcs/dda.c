/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:33 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:25:59 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__init_ray_dir(t_player *player)
{
	player->stepx = double_trn(player->ray_dirx < 0, -1, 1);
	player->side_distx = double_trn(player->ray_dirx < 0,
			(player->posx - player->mapx) * player->deltadistx,
			(player->mapx + 1.0 - player->posx) * player->deltadistx);
	player->stepy = double_trn(player->ray_diry < 0, -1, 1);
	player->side_disty = double_trn(player->ray_diry < 0,
			(player->posy - player->mapy) * player->deltadisty,
			(player->mapy + 1.0 - player->posy) * player->deltadisty);
}

int	__get_wall_orientation(t_program_data *data, int side)
{
	return (int_trn(side == 0, (data->player->mapx - data->player->mapx
				+ (1 - data->player->stepx) / 2)
			/ data->player->ray_dirx, (data->player->mapy - data->player->mapy
				+ (1 - data->player->stepy) / 2)
			/ data->player->ray_diry));
}

void	__jumping_to_next_case(t_program_data *data,
			t_player *player, int *x, int *y)
{
	if (player->side_distx < player->side_disty)
	{
		player->side_distx += player->deltadistx;
		player->mapx += player->stepx;
		data->side = 0;
	}
	else
	{
		player->side_disty += player->deltadisty;
		player->mapy += player->stepy;
		data->side = 1;
	}
	*x = player->mapx;
	*y = player->mapy;
}

int	__dda(t_program_data *data, t_player *player)
{
	int	hit;
	int	x;
	int	y;

	hit = 0;
	x = 0;
	y = 0;
	__init_ray_dir(player);
	while (!hit)
	{
		__jumping_to_next_case(data, player, &x, &y);
		if (data->parsed->map_desc[x][y] == '1')
			hit = 1;
	}
	if (data->side == 0)
		player->perpwall = (player->mapx - player->posx
				+ (1 - player->stepx) / 2) / player->ray_dirx;
	else
		player->perpwall = (player->mapy - player->posy
				+ (1 - player->stepy) / 2) / player->ray_diry;
	return (1);
}
