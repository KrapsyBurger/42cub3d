/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:43:58 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/03 17:44:17 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	__printf(const char *format_str, ...)
{
	va_list		arguments;
	t_struct	content;
	int			i;

	content.ret = 0;
	i = 0;
	va_start(arguments, format_str);
	while (format_str[i])
	{
		if (format_str[i] == '%')
		{
			content.conversion = format_str[i + 1];
			__treat_format(&content, arguments);
			i++;
		}
		else
			__putchar(format_str[i], &content);
		i++;
	}
	va_end(arguments);
	return (content.ret);
}
