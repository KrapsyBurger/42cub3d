/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_user_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:44:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 23:00:49 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	__is_valid_pos(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

void	__base_dir(int *x, int *y, t_player *player, char c)
{
	player->posx = (double)*x + 0.5;
	player->posy = (double)*y + 0.5;
	__dir(player, c);
}

void	__init_user_pos(t_player *player, t_program_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->parsed->map_desc[j])
	{
		while (data->parsed->map_desc[j][i])
		{
			if (__is_valid_pos(data->parsed->map_desc[j][i]))
				return (__base_dir(&j, &i, player,
						data->parsed->map_desc[j][i]));
			i++;
		}
		j++;
		i = 0;
	}
}

int	__init_user(t_program_data *data, t_player *player)
{
	player->dirx = 0;
	player->diry = 0;
	player->planex = 0.0;
	player->planey = 0.66;
	__init_user_pos(player, data);
	return (__SUCCESS);
}
