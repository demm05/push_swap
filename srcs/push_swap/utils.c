/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:00:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:24:16 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_next_node(t_node *node, enum e_loc loc)
{
	if (!node)
		return (NULL);
	if (loc == BOTTOM_A || loc == BOTTOM_B)
		return (node->prev);
	return (node->next);
}

t_node	*get_correct_node(t_data *data, enum e_loc loc)
{
	if (loc == TOP_A)
		return (data->a->head);
	else if (loc == TOP_B)
		return (data->b->head);
	else if (loc == BOTTOM_A)
		return (data->a->tail);
	else if (loc == BOTTOM_B)
		return (data->b->tail);
	return (NULL);
}

int	chunk_max_val(t_data *data, t_chunk *chunk)
{
	t_node	*cur;
	int		max;
	int		size;

	size = chunk->size;
	max = 0;
	cur = get_correct_node(data, chunk->loc);
	while (size--)
	{
		if (!cur)
			break ;
		if (cur->nbr > max)
			max = cur->nbr;
		cur = get_next_node(cur, chunk->loc);
	}
	return (max);
}
