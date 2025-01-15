/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:42:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 18:22:53 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	parse_format(const char *format, va_list val)
{
	int				len;
	int				i;
	t_format_info	info;

	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			parse_specifier(format + i + 1, &info, val);
			if (info.is_valid && info.len >= 0)
			{
				len += info.len;
				i += info.f_len;
				continue ;
			}
		}
		len += _putchar(format[i++]);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				len;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	len = parse_format(format, args);
	va_end(args);
	return (len);
}

// #include <unistd.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char *s = "%#2.222x\n";
// 	printf(s, 0); 
// 	ft_printf(s, 0); 
// 	return (0);
// }
