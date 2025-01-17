/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:08:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/17 13:37:47 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_op	get_op(char *str)
{
	if (!str)
		return (NULL);
	if (!ft_strcmp(str, "pa"))
		return (pa);
	if (!ft_strcmp(str, "pb"))
		return (pb);
	if (!ft_strcmp(str, "sa"))
		return (sa);
	if (!ft_strcmp(str, "sb"))
		return (sb);
	if (!ft_strcmp(str, "ss"))
		return (ss);
	if (!ft_strcmp(str, "ra"))
		return (ra);
	if (!ft_strcmp(str, "rb"))
		return (rb);
	if (!ft_strcmp(str, "rr"))
		return (rr);
	if (!ft_strcmp(str, "rra"))
		return (rra);
	if (!ft_strcmp(str, "rrb"))
		return (rrb);
	if (!ft_strcmp(str, "rrr"))
		return (rrr);
	return (NULL);
}

char	*read_op(void)
{
	static char	str[4];
	int			bytes;
	int			i;

	i = 0;
	while (1)
	{
		bytes = read(0, &str[i], 1);
		if (bytes == -1)
			return (NULL);
		if (str[i] == '\n' && i < 2)
			return (NULL);
		if (bytes == 0 || str[i] == '\n')
		{
			str[i] = 0;
			return (str);
		}
		if (++i > 3)
		{
			while (read(0, &str[i], 1)) 
				if (str[i] == '\n')
					break;
			return (NULL);
		}
	}
}

int	process_ops(t_data *data)
{
	char	*op;
	t_op	func;

	while (1)
	{
		op = read_op();
		if (!op)
			return (1);
		if (!ft_strcmp(op, ""))
			return (0);
		func = get_op(op);
		if (!func)
			return (1);
		func(data);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	data->silent = true;
	if (!process_ops(data))
	{
		if (is_sorted(data) && !data->b->size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	free_data(data);
	return (0);
}
