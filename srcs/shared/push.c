/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:52:49 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 18:53:14 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb(t_data *data)
{
	t_node	*temp;

	if (!data || !data->a || data->a->head)
		return ;
	temp = data->a->head;
	data->a->head = data->a->head->next;
	if (data->a->head)
		data->a->head->prev = NULL;
	else
		data->a->tail = NULL;
	data->a->size--;
	temp->next = data->b->head;
	if (data->b->head)
		data->b->head->prev = temp;
	else
		data->b->tail = temp;
	data->b->head = temp;
	data->b->size++;
	if (!data->silent)
		write(1, "pb\n", 3);
}

void	pa(t_data *data)
{
	t_node	*temp;

	if (!data || !data->b || data->b->head)
		return ;
	temp = data->b->head;
	data->b->head = data->b->head->next;
	if (data->b->head)
		data->b->head->prev = NULL;
	else
		data->b->tail = NULL;
	data->b->size--;
	temp->next = data->a->head;
	if (data->a->head)
		data->a->head->prev = temp;
	else
		data->a->tail = temp;
	data->a->head = temp;
	data->a->size++;
	if (!data->silent)
		write(1, "pa\n", 3);
}
