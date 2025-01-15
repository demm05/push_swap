/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:49:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 17:03:25 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	check_flag(char c, t_flags *flags)
{
	if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '#')
	{
		if ((c == '+' && flags->space) || \
			(c == ' ' && flags->plus))
			return (-1);
		if (c == '+')
			flags->plus = 1;
		else if (c == '-')
			flags->minus = 1;
		else if (c == ' ')
			flags->space = 1;
		else if (c == '0')
			flags->zero = 1;
		else if (c == '#')
			flags->hash = 1;
		return (1);
	}
	return (0);
}

int	pf_atoi(const char *nptr)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
		result = result * 10 + (nptr[i++] - '0');
	return (result);
}
