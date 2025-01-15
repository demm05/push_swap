/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:03:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 20:08:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"



int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data(argc, argv);
	normalize_stack(data->a);
	data->silent = false;
	if (!data->a)
		return (1);
	//sort_stack(stack);
	//printf_lst(stack);
	ft_printf("%d %d\n", data->a->head->nbr, data->a->size);
	clean_list(&data->a->head);
	clean_list(&data->b->head);
	free(data->a);
	free(data->b);
	free(data);
}
