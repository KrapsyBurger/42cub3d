/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:40:41 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/22 13:41:39 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__up_hook(t_program_data *data, t_player *player)
{
	int	new_posx;
	int	new_posy;

	new_posx = (int)(player->posx - player->dirx * player->move_speed);
	new_posy = (int)(player->posy - player->diry * player->move_speed);
	if (data->parsed->map_desc[new_posx][(int)player->posy] != '1')
		player->posx += data->player->dirx * player->move_speed;
	if (data->parsed->map_desc[(int)player->posx][new_posy] != '1')
		player->posy += data->player->diry * player->move_speed;
}

void	__down_hook(t_program_data *data, t_player *player)
{
	player->posx -= data->player->dirx * player->move_speed;
	player->posy -= data->player->diry * player->move_speed;
}

void	__rotate_right_hook(t_player *player)
{
	double	olddirx;
	double	oldplanex;

	olddirx = player->dirx;
	oldplanex = player->planex;
	player->dirx = player->dirx * cos(-player->rotate_speed)
		- player->diry * sin(-player->rotate_speed);
	player->diry = olddirx * sin(-player->rotate_speed) + player->diry
		* cos(-player->rotate_speed);
	player->planex = player->planex * cos(-player->rotate_speed)
		- player->planey * sin(-player->rotate_speed);
	player->planey = oldplanex * sin(-player->rotate_speed)
		+ player->planey * cos(-player->rotate_speed);
}

void	__rotate_left_hook(t_player *player)
{
	double	olddirx;
	double	oldplanex;

	olddirx = player->dirx;
	oldplanex = player->planex;
	player->dirx = player->dirx * cos(player->rotate_speed)
		- player->diry * sin(player->rotate_speed);
	player->diry = olddirx * sin(player->rotate_speed)
		+ player->diry * cos(player->rotate_speed);
	player->planex = player->planex * cos(player->rotate_speed)
		- player->planey * sin(player->rotate_speed);
	player->planey = oldplanex * sin(player->rotate_speed)
		+ player->planey * cos(player->rotate_speed);
}

void	__left_hook(t_program_data *data, t_player *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx + player->dirx * player->move_speed;
	new_posy = player->posy + player->diry * player->move_speed;
	if (data->parsed->map_desc[(int)new_posx][(int)player->posy] != '1')
		player->posx -= player->planex * player->move_speed;
	if (data->parsed->map_desc[(int)player->posx][(int)new_posy] != '1')
		player->posy -= player->planey * player->move_speed;
}
