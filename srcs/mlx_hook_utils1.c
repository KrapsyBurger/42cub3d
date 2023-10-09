/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:23:36 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 23:00:22 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__right_hook(t_program_data *data, t_player *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx + player->dirx * player->move_speed;
	new_posy = player->posy + player->diry * player->move_speed;
	if (data->parsed->map_desc[(int)new_posx][(int)player->posy] != '1')
		player->posx += player->planex * player->move_speed;
	if (data->parsed->map_desc[(int)player->posx][(int)new_posy] != '1')
		player->posy += player->planey * player->move_speed;
}

int	__move_little_square(int key_hook, t_program_data *data)
{
	if (key_hook == ESC)
		__quit(data);
	if (key_hook == W)
		__up_hook(data, data->player);
	if (key_hook == S)
		__down_hook(data, data->player);
	if (key_hook == A)
		__left_hook(data, data->player);
	if (key_hook == D)
		__right_hook(data, data->player);
	if (key_hook == 65361)
		__rotate_left_hook(data->player);
	if (key_hook == 65363)
		__rotate_right_hook(data->player);
	return (1);
}

int	__close_little_window(t_program_data *data)
{
	__quit(data);
	return (1);
}
