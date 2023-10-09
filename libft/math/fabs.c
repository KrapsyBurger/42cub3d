/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:22:20 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:36:10 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**					Absolute value of a float
*/

#include "libft.h"

float	float_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	double_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
