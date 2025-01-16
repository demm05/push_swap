/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:21:43 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:23:02 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	base_sort_three_a(t_data *data);
static void	base_sort_four_a(t_data *data);
static void	base_sort_two_a(t_data *data);
static void	base_sort_five_a(t_data *data);

void	base_sort_a(t_data *data)
{
	if (data->a->size <= 1)
		return ;
	else if (data->a->size == 2)
		base_sort_two_a(data);
	else if (data->a->size == 3)
		base_sort_three_a(data);
	else if (data->a->size == 4)
		base_sort_four_a(data);
	else if (data->a->size == 5)
		base_sort_five_a(data);
}

static void	base_sort_two_a(t_data *data)
{
	if (data->a->head->nbr > data->a->tail->nbr)
		sa(data);
}

static void	base_sort_three_a(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a->head->nbr;
	second = data->a->head->next->nbr;
	third = data->a->tail->nbr;
	if (first < second && second < third)
		return ;
	if (first < third && first > second)
		sa(data);
	else if (third < first && second > first)
		rra(data);
	else if (first > third && third > second)
		ra(data);
	else if (third > first && third < second)
	{
		rra(data);
		sa(data);
	}
	else if (first > second && second > third)
	{
		sa(data);
		rra(data);
	}
}

static void	base_sort_four_a(t_data *data)
{
	if (!data->a->tail->prev->nbr)
		rra(data);
	if (!data->a->tail->nbr)
		rra(data);
	if (!data->a->head->next->nbr)
		sa(data);
	if (is_sorted(data))
		return ;
	pb(data);
	base_sort_three_a(data);
	pa(data);
}

static void	base_sort_five_a(t_data *data)
{
	if (!data->a->tail->prev->nbr)
		rra(data);
	if (!data->a->tail->nbr)
		rra(data);
	while (data->a->size > 3)
	{
		if (data->a->head->nbr <= 1)
			pb(data);
		else
			ra(data);
	}
	if (!is_sorted(data))
		base_sort_three_a(data);
	if (data->b->head->nbr == 0)
		sb(data);
	pa(data);
	pa(data);
}
