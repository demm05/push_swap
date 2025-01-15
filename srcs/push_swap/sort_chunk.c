/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:18:55 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/15 16:51:22 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rec_sort_chunk(t_data *data, t_chunk *to_sort);

void	sort_chunk(t_data *data)
{
	t_chunk	chunk;

	chunk.loc = TOP_A;
	chunk.size = data->a->size;
	rec_sort_chunk(data, &chunk);
}

void	rec_sort_chunk(t_data *data, t_chunk *to_sort)
{
	t_split	dest;

	ft_printf("To_sort: %d\n", to_sort->size);
	if (to_sort->size <= 3)
	{
		return ;
	}
	split_chunk(data, to_sort, &dest);
	rec_sort_chunk(data, &dest.max);
	rec_sort_chunk(data, &dest.mid);
	rec_sort_chunk(data, &dest.mid);
}
