/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:02:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/22 13:46:52 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	__game_loop(t_program_data *data)
{
	mlx_hook(data->cub.win, 2, 1L << 0, __move_little_square, data);
	mlx_hook(data->cub.win, 17, 1L << 0, __close_little_window, data);
	mlx_loop_hook(data->cub.mlx, &__raycast_loop, data);
	mlx_loop(data->cub.mlx);
}

int	main(int argc, char **argv)
{
	t_program_data	*data;

	if (SCREEN_HEIGHT < 0 || SCREEN_WIDTH < 0)
		exit(__FAILURE);
	if (argc != 2)
		return (__putstr_fd("Error\nWrong arguments number.\n", 2), -1);
	data = __calloc(1, sizeof(t_program_data));
	if (__init_cub3d(data, argv) == __FAILURE)
		return (__quit(data), __FAILURE);
	if (__parsing(data, 0) == 1)
		return (__quit(data), -1);
	if (__init_user(data, data->player) == __FAILURE)
		return (__quit(data), -1);
	if (!__load_textures(data))
		return (__FAILURE);
	data->text_num = 0;
	__game_loop(data);
	__quit(data);
	return (0);
}
