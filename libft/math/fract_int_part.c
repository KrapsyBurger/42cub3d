/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_int_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:23 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:36:02 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	fractional_part(float x)
{
	if (x > 0)
		return (x - integer_part(x));
	return (x - (integer_part(x) + 1));
}
