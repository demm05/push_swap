/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:18:55 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/15 18:39:19 by dmelnyk          ###   ########.fr       */
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

	if (to_sort->loc == BOTTOM_B && data->b->size == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && data->a->size == to_sort->size)
		to_sort->loc = TOP_A;

	if (to_sort->size <= 3)
	{
		if (to_sort->size == 1)
			sort_one(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 3)
			sort_three(data, to_sort);
		return ;
	}
	split_chunk(data, to_sort, &dest);
	ft_printf("---max---\n");
	rec_sort_chunk(data, &dest.max);
	ft_printf("---mid---\n");
	rec_sort_chunk(data, &dest.mid);
	ft_printf("---min---\n");
	rec_sort_chunk(data, &dest.mid);
}
