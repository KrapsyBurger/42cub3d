/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parsing_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:30:01 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/21 18:15:17 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__get_c_red(t_parsing *data, int *j, int *k, int *i)
{
	data->c_red = __substr(data->color_c, *i, *k - *i);
	data->c_r = __atoi(data->c_red);
	if (data->c_r > 255 || __strlen(data->c_red) > 12)
		data->c_r = 255;
	else if (data->c_r < 0)
		data->c_r = 0;
	*j += 1;
	*i = *k;
}

void	__get_c_green(t_parsing *data, int *j, int *k, int *i)
{
	data->c_green = __substr(data->color_c, *i, *k - *i);
	data->c_g = __atoi(data->c_green);
	if (data->c_g > 255 || __strlen(data->c_green) > 12)
		data->c_g = 255;
	else if (data->c_g < 0)
		data->c_g = 0;
	*j += 1;
	*i = *k;
}

void	__get_c_blue(t_parsing *data, int *k, int *i)
{
	data->c_blue = __substr(data->color_c, *i, *k - *i);
	data->c_b = __atoi(data->c_blue);
	if (data->c_b > 255 || __strlen(data->c_blue) > 12)
		data->c_b = 255;
	else if (data->c_b < 0)
		data->c_b = 0;
	*i = *k;
}

void	__rgb_c_getter(t_parsing *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (data->color_c[i])
	{
		if (__isdigit(data->color_c[i]))
		{
			while (__isdigit(data->color_c[k]))
				k++;
			if (j == 0)
				__get_c_red(data, &j, &k, &i);
			else if (j == 1)
				__get_c_green(data, &j, &k, &i);
			else if (j == 2)
				__get_c_blue(data, &k, &i);
		}
		if (!data->color_c[i])
			break ;
		i++;
		k = i;
	}
}
