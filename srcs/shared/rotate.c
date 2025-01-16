/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:49:40 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:25:12 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	internal_ra(t_data *data, int print)
{
	t_node	*first;
	t_node	*last;

	if (!data || !data->a || !data->a->head || !data->a->head->next)
		return ;
	first = data->a->head;
	last = data->a->tail;
	data->a->head = first->next;
	data->a->tail = first;
	data->a->head->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print && !data->silent)
		write(1, "ra\n", 3);
}

static void	internal_rb(t_data *data, int print)
{
	t_node	*first;
	t_node	*last;

	if (!data || !data->b || !data->b->head || !data->b->head->next)
		return ;
	first = data->b->head;
	last = data->b->tail;
	data->b->head = first->next;
	data->b->tail = first;
	data->b->head->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print && !data->silent)
		write(1, "rb\n", 3);
}

void	ra(t_data *data)
{
	internal_ra(data, 1);
}

void	rb(t_data *data)
{
	internal_rb(data, 1);
}

void	rr(t_data *data)
{
	internal_ra(data, 0);
	internal_rb(data, 0);
	if (!data->silent)
		write(1, "rr\n", 3);
}
