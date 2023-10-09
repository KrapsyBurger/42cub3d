/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:49:37 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/21 18:57:15 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__face_north(t_player *player)
{
	player->dirx = -1;
	player->diry = 0;
	player->planex = 0 * player->diry;
	player->planey = -0.66 * player->dirx;
}

void	__face_south(t_player *player)
{
	player->dirx = 1;
	player->diry = 0;
	player->planex = 0 * player->diry;
	player->planey = 0.66 * -player->dirx;
}

void	__face_east(t_player *player)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = 0.66 * player->diry;
	player->planey = 0 * player->dirx;
}

void	__face_west(t_player *player)
{
	player->dirx = 0;
	player->diry = -1;
	player->planex = 0.66 * player->diry;
	player->planey = 0 * player->dirx;
}

void	__dir(t_player *player, char c)
{
	if (c == 'N')
		__face_north(player);
	if (c == 'E')
		__face_east(player);
	if (c == 'W')
		__face_west(player);
	if (c == 'S')
		__face_south(player);
}
