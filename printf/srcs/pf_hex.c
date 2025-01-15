/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:40:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 18:30:33 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	hex_len(unsigned long long nb);
static void	get_hex(unsigned long long nb,
				char *buffer, int is_upper, int precision);

char	*pf_uhex(va_list val, t_spec_info *s_info)
{
	unsigned int	nb;
	int				len;
	char			*buffer;

	nb = va_arg(val, unsigned int);
	if (nb == 0 && !s_info->is_precision)
		return (ft_strdup("0"));
	len = hex_len(nb);
	if (len < s_info->precision)
		len = s_info->precision;
	buffer = malloc(sizeof(char) * (len + 3));
	if (!buffer)
		return (0);
	if (s_info->flags.hash && !(s_info->is_precision && nb == 0))
	{
		get_hex(nb, buffer + 2, 1, s_info->precision);
		buffer[0] = '0';
		buffer[1] = 'X';
	}
	else
		get_hex(nb, buffer, 1, s_info->precision);
	return (buffer);
}

char	*pf_lhex(va_list val, t_spec_info *s_info)
{
	unsigned int	nb;
	int				len;
	char			*buffer;

	nb = va_arg(val, unsigned int);
	if (nb == 0 && !s_info->is_precision)
		return (ft_strdup("0"));
	len = hex_len(nb);
	if (len < s_info->precision)
		len = s_info->precision;
	buffer = malloc(sizeof(char) * (len + 3));
	if (!buffer)
		return (0);
	if (s_info->flags.hash && !(s_info->is_precision && nb == 0))
	{
		get_hex(nb, buffer + 2, 0, s_info->precision);
		buffer[0] = '0';
		buffer[1] = 'x';
	}
	else
		get_hex(nb, buffer, 0, s_info->precision);
	return (buffer);
}

static void	fill_zeros(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
		buffer[i++] = '0';
}

static void	get_hex(unsigned long long nb, char *buffer,
					int is_upper, int precision)
{
	int	i;
	int	len;
	int	r;

	len = hex_len(nb);
	if (precision > len)
	{
		fill_zeros(buffer, precision - len);
		len = precision;
	}
	i = 0;
	while (i < len)
	{
		r = nb % 16;
		if (r <= 9)
			buffer[len - i - 1] = r + '0';
		else if (is_upper)
			buffer[len - i - 1] = r - 10 + 'A';
		else
			buffer[len - i - 1] = r - 10 + 'a';
		i++;
		nb /= 16;
	}
	buffer[i] = 0;
}

static int	hex_len(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}
