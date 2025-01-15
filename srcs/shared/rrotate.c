/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:50:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 18:51:24 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rra_internal(t_data *data, int print)
{
	t_node	*last;
	t_node	*first;

	if (!data || !data->a || !data->a->head || !data->a->head->next)
		return ;
	first = data->a->head;
	last = data->a->tail;
	data->a->head = last;
	data->a->tail = last->prev;
	data->a->tail->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	if (print && !data->silent)
		write(1, "rra\n", 4);
}

static void	rrb_internal(t_data *data, int print)
{
	t_node	*last;
	t_node	*first;

	if (!data || !data->b || !data->b->head || !data->b->head->next)
		return ;
	first = data->b->head;
	last = data->b->tail;
	data->b->head = last;
	data->b->tail = last->prev;
	data->b->tail->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	if (print && !data->silent)
		write(1, "rrb\n", 4);
}

void	rra(t_data *data)
{
	rra_internal(data, 1);
}

void	rrb(t_data *data)
{
	rrb_internal(data, 1);
}

void	rrr(t_data *data)
{
	rra_internal(data, 0);
	rrb_internal(data, 0);
	if (!data->silent)
		write(1, "rrr\n", 4);
}
