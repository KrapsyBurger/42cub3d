/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_trn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:18:07 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:37:05 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	double_trn(int condition, double success, double failure)
{
	if (condition)
		return (success);
	return (failure);
}
