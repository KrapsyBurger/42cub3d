/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:50:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/22 16:50:25 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*__ft_strjoin(char *s1, char *s2, int b)
{
	char			*a;
	unsigned long	i;
	unsigned long	j;

	if (s1 == NULL)
		s1 = __strdup("");
	if (!s2 || !s1)
		return (NULL);
	s2[b] = '\0';
	a = malloc(sizeof(char) * (__strlen(s1) + __strlen(s2) + 1));
	i = -1;
	j = -1;
	if (a == NULL)
		return (__free(s1), NULL);
	while (s1[++i] != '\0')
		a[i] = s1[i];
	while (s2[++j] != '\0')
	{
		a[i] = s2[j];
		i++;
	}
	a[i] = '\0';
	free(s1);
	return (a);
}

char	*__fill_string(int fd)
{
	char	*s;
	char	*buff;
	int		i;

	s = NULL;
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return (NULL);
	buff[1] = '\0';
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, 1);
		if (i == -1)
			return (__free(buff), exit(__FAILURE), NULL);
		if (i == 0 || __strlen(buff) < 1)
			break ;
		s = __ft_strjoin(s, buff, 1);
	}
	free(buff);
	buff = NULL;
	return (s);
}

int	__cub_checker(char *s)
{
	if (__strlen(s) < 4
		|| !__strstr(s, ".cub")
		|| __strcmp(s + __strlen(s) - 4, ".cub"))
		return (__FALSE);
	return (__TRUE);
}

void	__jump_to_next_elem(char *s, int *len, int *start)
{
	while (s[*len] != '\n')
		*len += 1;
	while (s[*len] == '\n')
		*len += 1;
	*start = *len;
}

int	__elem_compare(char *elem)
{
	if (__strcmp(elem, "NO") == 0 || __strcmp(elem, "N") == 0)
		return (0);
	if (__strcmp(elem, "SO") == 0 || __strcmp(elem, "S") == 0)
		return (1);
	if (__strcmp(elem, "WE") == 0 || __strcmp(elem, "W") == 0)
		return (2);
	if (__strcmp(elem, "EA") == 0 || __strcmp(elem, "E") == 0)
		return (3);
	if (__strcmp(elem, "F") == 0)
		return (4);
	if (__strcmp(elem, "C") == 0)
		return (5);
	else
		return (6);
}
