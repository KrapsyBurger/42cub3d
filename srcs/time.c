/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:04:10 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/15 16:04:40 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef USE_TIME

size_t	__get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((size_t)(time.tv_sec * 1000) + (size_t)(time.tv_usec / 1000));
}

#else

size_t	__get_time(void)
{
	static struct timeval	time = {};

	time.tv_sec += 1;
	return ((size_t)(time.tv_sec * 1000) + (size_t)(time.tv_usec / 1000));
}

#endif