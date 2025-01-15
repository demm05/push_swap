/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:33:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 17:46:47 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_len_of_num(long n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (0);
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	parse_flags(const char *format, t_spec_info *s_info, int *i)
{
	int	temp;

	while (format[*i])
	{
		if (*i == 0 && format[*i] == '0')
		{
			while (format[*i] >= '0' && format[*i] <= '9')
				*i += 1;
			if (format[*i] == '.')
			{
				s_info->is_precision = 1;
				*i = 1;
				break ;
			}
			*i = 0;
		}
		temp = check_flag(format[*i], &s_info->flags);
		if (temp == 1)
			*i += 1;
		else if (temp == -1)
			return (-1);
		else if (!temp)
			break ;
	}
	return (0);
}

void	parse_width(const char *format, t_spec_info *s_info, int *i)
{
	if (format[*i] >= '0' && format[*i] <= '9')
	{
		s_info->width = pf_atoi(format + *i);
		while (format[*i] == '0')
			*i += 1;
		*i += get_len_of_num(s_info->width);
	}
}

void	parse_precision(const char *format, t_spec_info *s_info, int *i)
{
	if (format[*i] == '.')
	{
		*i += 1;
		s_info->is_precision = 1;
		s_info->precision = pf_atoi(format + *i);
		while (!s_info->precision && format[*i] == '0')
			*i += 1;
		*i += get_len_of_num(s_info->precision);
	}
}
