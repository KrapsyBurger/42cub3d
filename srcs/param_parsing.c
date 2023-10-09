/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:50:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:14:40 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	__parameter_analyse(int ac, char **av)
{
	if (ac != 2)
		return (__FALSE);
	if (__strlen(av[1]) < 4
		|| !__strstr(av[1], ".cub")
		|| __strcmp(av[1] + __strlen(av[1]) - 4, ".cub"))
		return (__FALSE);
	return (__TRUE);
}

void	__usage(void)
{
	__putstr_fd("usage : ./cub3d <.cub3d file>\n", 2);
}
