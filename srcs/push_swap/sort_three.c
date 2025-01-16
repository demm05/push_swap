/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:00:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:24:44 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_top_a(t_data *data, t_chunk *to_sort, int max);
void	sort_three_top_b(t_data *data, t_chunk *to_sort, int max);
void	sort_three_bottom_a(t_data *data, t_chunk *to_sort, int max);
void	sort_three_bottom_b(t_data *data, t_chunk *to_sort, int max);

void	sort_three(t_data *data, t_chunk *to_sort)
{
	enum e_loc	loc;
	int			max;

	max = chunk_max_val(data, to_sort);
	loc = to_sort->loc;
	if (loc == TOP_A)
		sort_three_top_a(data, to_sort, max);
	else if (loc == TOP_B)
		sort_three_top_b(data, to_sort, max);
	else if (loc == BOTTOM_A)
		sort_three_bottom_a(data, to_sort, max);
	else if (loc == BOTTOM_B)
		sort_three_bottom_b(data, to_sort, max);
}

void	sort_three_top_a(t_data *data, t_chunk *to_sort, int max)
{
	if (data->a->head->next->nbr == max)
	{
		ra(data);
		sa(data);
		rra(data);
	}
	else if (data->a->head->nbr == max)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_top_b(t_data *data, t_chunk *to_sort, int max)
{
	pa(data);
	if (data->b->head->next->nbr == max)
	{
		sb(data);
		pa(data);
		sa(data);
	}
	else if (data->b->head->nbr == max)
	{
		pa(data);
		sa(data);
	}
	else
		pa(data);
	pa(data);
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_a(t_data *data, t_chunk *to_sort, int max)
{
	rra(data);
	rra(data);
	if (data->a->tail->nbr == max)
	{
		pb(data);
		rra(data);
		sa(data);
		pa(data);
	}
	else
	{
		if (data->a->head->nbr == max)
			sa(data);
		rra(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size = -1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_b(t_data *data, t_chunk *to_sort, int max)
{
	rrb(data);
	rrb(data);
	if (data->b->tail->nbr == max)
	{
		rrb(data);
		pa(data);
		pa(data);
	}
	else
	{
		if (data->b->head->next->nbr == max)
			sb(data);
		pa(data);
		pa(data);
		rrb(data);
	}
	pa(data);
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}
