/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:08:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 19:08:43 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	normalize_stack(data->a);
	data->silent = true;
	free_data(data);
}

