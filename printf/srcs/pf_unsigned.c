/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:40:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:50:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_len_of_num(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int num, int precision)
{
	int		len;
	int		len_of_num;
	char	*res;

	len_of_num = get_len_of_num(num);
	len = len_of_num;
	if (precision > len)
		len += precision - len;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len--] = 0;
	while (len_of_num--)
	{
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	while (len >= 0)
		res[len--] = '0';
	return (res);
}

char	*pf_unsigned(va_list val, t_spec_info *s_info)
{
	unsigned int	nb;
	char			*buffer;

	nb = va_arg(val, unsigned int);
	if (nb == 0 && s_info->is_precision && !s_info->precision)
		return (ft_strdup(""));
	buffer = ft_uitoa(nb, s_info->precision);
	if (!buffer)
		return (0);
	return (buffer);
}
