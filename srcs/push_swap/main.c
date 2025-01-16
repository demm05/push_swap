/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:03:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:21:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 3)
		return (0);
	data = init_data(argc, argv);
	if (!data->a)
		return (1);
	normalize_stack(data->a);
	data->silent = false;
	if (!is_sorted(data))
		sort(data);
	clean_list(&data->a->head);
	clean_list(&data->b->head);
	free(data->a);
	free(data->b);
	free(data);
}
