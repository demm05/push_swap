/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:40:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 16:53:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	get_hex(unsigned long long nb, char *buffer, int is_upper);
static int	hex_len(unsigned long long nb);

char	*pf_pointer(va_list val, t_spec_info *s_info)
{
	unsigned long long	nb;
	char				*buffer;

	(void)s_info;
	nb = va_arg(val, unsigned long long);
	if (!nb)
		return (ft_strdup("(nil)"));
	buffer = malloc(sizeof(char) * (hex_len(nb) + 3));
	if (!buffer)
		return (0);
	get_hex(nb, buffer + 2, 0);
	buffer[0] = '0';
	buffer[1] = 'x';
	return (buffer);
}

static void	get_hex(unsigned long long nb, char *buffer, int is_upper)
{
	int	i;
	int	len;
	int	r;

	len = hex_len(nb);
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

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}
