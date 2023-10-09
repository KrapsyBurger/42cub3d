/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_trn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:03:04 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/07 15:20:37 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	float_trn(int condition, float success, float failure)
{
	if (condition)
		return (success);
	return (failure);
}
