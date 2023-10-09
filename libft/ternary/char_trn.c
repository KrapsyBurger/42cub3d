/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_trn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:01:50 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:36:47 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	char_trn(int condition, char success, char failure)
{
	if (condition)
		return (success);
	return (failure);
}
