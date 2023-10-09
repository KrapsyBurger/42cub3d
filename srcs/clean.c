/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:49:32 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:17:25 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__free(void *addr)
{
	free(addr);
	addr = NULL;
}

void	__free_parsing_struct_helper(t_parsing *data)
{
	if (data->path_no != NULL)
		__free(data->path_no);
	if (data->path_so != NULL)
		__free(data->path_so);
	if (data->path_we != NULL)
		__free(data->path_we);
	if (data->path_ea != NULL)
		__free(data->path_ea);
	if (data->color_c != NULL)
		__free(data->color_c);
	if (data->c_blue != NULL)
		__free(data->c_blue);
	if (data->c_green != NULL)
		__free(data->c_green);
	if (data->c_red != NULL)
		__free(data->c_red);
	if (data->color_f != NULL)
		__free(data->color_f);
	if (data->f_blue != NULL)
		__free(data->f_blue);
}

void	__free_parsing_struct(t_parsing *data)
{
	int	i;

	i = -1;
	__free_parsing_struct_helper(data);
	if (data->f_green != NULL)
		__free(data->f_green);
	if (data->f_red != NULL)
		__free(data->f_red);
	if (data->full_map != NULL)
		__free(data->full_map);
	if (data->map_desc != NULL)
	{
		while (data->map_desc[++i] != NULL)
			__free(data->map_desc[i]);
		__free(data->map_desc);
	}
	close(data->map_fd);
	__free(data);
}

void	__free_int_tab(int **tab, int *index)
{
	int	i;

	i = 0;
	while (i < *index)
	{
		__free(tab[i]);
		i++;
	}
	__free(tab);
}
