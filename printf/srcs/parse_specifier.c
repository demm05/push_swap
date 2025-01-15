/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:35:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 16:53:20 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

t_spec_formatter	get_spec(char c)
{
	if (!c)
		return (0);
	if (c == '%')
		return (pf_37);
	if (c == 'c')
		return (pf_char);
	if (c == 's')
		return (pf_string);
	if (c == 'p')
		return (pf_pointer);
	if (c == 'i' || c == 'd')
		return (pf_integer);
	if (c == 'u')
		return (pf_unsigned);
	if (c == 'x')
		return (pf_lhex);
	if (c == 'X')
		return (pf_uhex);
	return (0);
}

void	do_width(char *buffer, t_format_info *t_info, t_spec_info s_info)
{
	int		i;
	char	pad;
	int		len;

	if (s_info.is_char && s_info.width && !s_info.flags.minus)
		return ;
	if (s_info.flags.zero)
		pad = '0';
	else
		pad = ' ';
	if (s_info.flags.minus)
		_pf_putstr(buffer, 1);
	i = 0;
	len = t_info->len;
	while (i++ < (s_info.width - len))
	{
		_putchar(pad);
		t_info->len++;
	}
	if (!s_info.flags.minus)
		_pf_putstr(buffer, 1);
}

char	*get_buffer(const char *format, va_list val,
					t_format_info *t_info, t_spec_info *s_info)
{
	char				*buffer;
	t_spec_formatter	func;	

	func = get_spec(*format);
	if (!func)
		return (NULL);
	buffer = func(val, s_info);
	if (!buffer)
		return (NULL);
	if (s_info->is_char)
	{
		if (s_info->width && !s_info->flags.minus)
			t_info->len = s_info->width;
		else
			t_info->len = 1;
	}
	else
		t_info->len = ft_strlen(buffer);
	t_info->is_valid = 1;
	return (buffer);
}

void	pf_initialize_var(t_spec_info *s_info, t_format_info *t_info)
{
	t_info->is_valid = 0;
	s_info->flags.plus = 0;
	s_info->flags.hash = 0;
	s_info->flags.minus = 0;
	s_info->flags.space = 0;
	s_info->flags.zero = 0;
	s_info->is_precision = 0;
	s_info->precision = 0;
	s_info->is_width = 0;
	s_info->width = 0;
	s_info->is_char = 0;
}

void	parse_specifier(const char *format, t_format_info *t_info, va_list val)
{
	t_spec_info			s_info;
	int					i;
	char				*buffer;

	i = 0;
	pf_initialize_var(&s_info, t_info);
	if (parse_flags(format, &s_info, &i) == -1)
		return ;
	parse_width(format, &s_info, &i);
	parse_precision(format, &s_info, &i);
	buffer = get_buffer(format + i, val, t_info, &s_info);
	if (!buffer)
		return ;
	do_width(buffer, t_info, s_info);
	t_info->f_len = i + 2;
	free(buffer);
}
