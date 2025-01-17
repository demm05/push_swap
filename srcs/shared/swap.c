/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:44:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 18:52:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	internal_sa(t_data *data, int print)
{
	t_node	*first;
	t_node	*second;

	if (!data || !data->a || ! data->a->head || !data->a->head->next)
		return ;
	first = data->a->head;
	second = first->next;
	data->a->head = second;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		data->a->tail = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	if (!data->silent && print)
		write(1, "sa\n", 3);
}

static void	internal_sb(t_data *data, int print)
{
	t_node	*first;
	t_node	*second;

	if (!data || !data->b || ! data->b->head || !data->b->head->next)
		return ;
	first = data->b->head;
	second = first->next;
	data->b->head = second;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		data->b->tail = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	if (!data->silent && print)
		write(1, "sb\n", 3);
}

void	sa(t_data *data)
{
	internal_sa(data, 1);
}

void	sb(t_data *data)
{
	internal_sb(data, 1);
}

void	ss(t_data *data)
{
	internal_sa(data, 0);
	internal_sb(data, 0);
	if (!data->silent)
		write(1, "ss\n", 3);
}
