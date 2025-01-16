/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:07:52 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:24:52 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_data(t_data *data)
{
	if (data->a)
	{
		clean_list(&data->a->head);
		free(data->a);
	}
	if (data->b)
	{
		clean_list(&data->b->head);
		free(data->b);
	}
	free(data);
}
