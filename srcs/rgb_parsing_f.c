/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parsing_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:30:31 by nfascia           #+#    #+#             */
/*   Updated: 2022/11/21 18:15:29 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	__get_f_red(t_parsing *data, int *j, int *k, int *i)
{
	data->f_red = __substr(data->color_f, *i, *k - *i);
	data->f_r = __atoi(data->f_red);
	if (data->f_r > 255 || __strlen(data->f_red) > 12)
		data->f_r = 255;
	else if (data->f_r < 0)
		data->f_r = 0;
	*j += 1;
	*i = *k;
}

void	__get_f_green(t_parsing *data, int *j, int *k, int *i)
{
	data->f_green = __substr(data->color_f, *i, *k - *i);
	data->f_g = __atoi(data->f_green);
	if (data->f_g > 255 || __strlen(data->f_green) > 12)
		data->f_g = 255;
	else if (data->f_g < 0)
		data->f_g = 0;
	*j += 1;
	*i = *k;
}

void	__get_f_blue(t_parsing *data, int *k, int *i)
{
	data->f_blue = __substr(data->color_f, *i, *k - *i);
	data->f_b = __atoi(data->f_blue);
	if (data->f_b > 255 || __strlen(data->f_blue) > 12)
		data->f_b = 255;
	else if (data->f_b < 0)
		data->f_b = 0;
	*i = *k;
}

void	__rgb_f_getter(t_parsing *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (data->color_f[i])
	{
		if (__isdigit(data->color_f[k]))
		{
			while (__isdigit(data->color_f[k]))
				k++;
			if (j == 0)
				__get_f_red(data, &j, &k, &i);
			else if (j == 1)
				__get_f_green(data, &j, &k, &i);
			else if (j == 2)
				__get_f_blue(data, &k, &i);
		}
		if (!data->color_f[i])
			break ;
		i++;
		k = i;
	}
}
