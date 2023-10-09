/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:17:31 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:14:35 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	__mlx_destroy_win(t_cub *cub)
{
	mlx_destroy_display(cub->mlx);
	__free(cub->mlx);
}

static void	__mlx_destroy_img(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	__free(cub->mlx);
}

int	__mlx_init(t_cub *cub)
{	
	__memset(cub, 0, sizeof(cub));
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (__FAILURE);
	cub->win = mlx_new_window(cub->mlx, 1920, 1080, "cub");
	if (!cub->win)
		return (__mlx_destroy_win(cub), __FAILURE);
	cub->img.new_img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->img.new_img)
		return (__mlx_destroy_img(cub), __FAILURE);
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.new_img,
			&cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	return (__SUCCESS);
}

unsigned long	__create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
