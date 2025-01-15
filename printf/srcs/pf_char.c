/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:39:58 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 16:21:05 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*pf_char(va_list val, t_spec_info *s_info)
{
	char	c;
	int		i;

	c = va_arg(val, int);
	i = 1;
	s_info->is_char = 1;
	s_info->flags.zero = 0;
	if (s_info->width && !s_info->flags.minus)
	{
		while (i++ < s_info->width)
			_putchar(' ');
	}
	_putchar(c);
	return (ft_strdup(""));
}

char	*pf_37(va_list val, t_spec_info *s_info)
{
	char	*buffer;

	(void)val;
	s_info->flags.zero = 0;
	buffer = malloc(sizeof(char) * 2);
	buffer[0] = '%';
	buffer[1] = 0;
	return (buffer);
}
