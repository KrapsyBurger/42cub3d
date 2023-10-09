/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_trn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:04:45 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 18:36:38 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*void_ptr_trn(int condition, void *success, void *failure)
{
	if (condition)
		return (success);
	return (failure);
}

char	*char_ptr_trn(int condition, char *success, char *failure)
{
	if (condition)
		return (success);
	return (failure);
}

int	*int_ptr_trn(int condition, int *success, int *failure)
{
	if (condition)
		return (success);
	return (failure);
}
