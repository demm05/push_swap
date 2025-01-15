/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:41:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 15:39:42 by dmelnyk          ###   ########.fr       */
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

static void	set_values(long *num, int *len,
					int *is_minus, t_spec_info s_info)
{
	int	len_of_n;

	*len = 0;
	*is_minus = 0;
	if (*num < 0)
	{
		*is_minus = 1;
		*num *= -1;
		*len += 1;
	}
	len_of_n = get_len_of_num(*num);
	*len += len_of_n;
	if (s_info.precision > len_of_n)
		*len = s_info.precision + *is_minus;
	if (!s_info.is_precision && s_info.flags.zero && s_info.width > *len)
		*len = s_info.width;
}

char	*pf_itoa(int n, t_spec_info s_info)
{
	long	num;
	int		len;
	int		is_minus;
	char	*res;
	int		len_of_n;

	num = n;
	set_values(&num, &len, &is_minus, s_info);
	len_of_n = get_len_of_num(num);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len--] = 0;
	while (len_of_n--)
	{
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	while (len - is_minus >= 0)
		res[len--] = '0';
	if (is_minus)
		res[0] = '-';
	return (res);
}

char	*pf_integer(va_list val, t_spec_info *s_info)
{
	int		nb;
	char	*temp;
	char	*buffer;

	nb = va_arg(val, int);
	if (nb == 0 && s_info->is_precision && !s_info->precision)
	{
		if (s_info->flags.plus)
			return (ft_strdup("+"));
		return (ft_strdup(""));
	}
	buffer = pf_itoa(nb, *s_info);
	if (!buffer)
		return (0);
	temp = buffer;
	if (s_info->flags.plus && buffer[0] != '-')
		buffer = ft_strjoin("+", buffer);
	else if (s_info->flags.space && buffer[0] != '-')
		buffer = ft_strjoin(" ", buffer);
	else
		return (buffer);
	free(temp);
	return (buffer);
}
