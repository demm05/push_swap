/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:59:49 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:21:22 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_a(t_data *data, enum e_loc to);
void	move_top_b(t_data *data, enum e_loc to);
void	move_bottom_a(t_data *data, enum e_loc to);
void	move_bottom_b(t_data *data, enum e_loc to);

int	move_from_to(t_data *data, enum e_loc from, enum e_loc to)
{
	if (from == TOP_A)
		move_top_a(data, to);
	else if (from == TOP_B)
		move_top_b(data, to);
	else if (from == BOTTOM_A)
		move_bottom_a(data, to);
	else if (from == BOTTOM_B)
		move_bottom_b(data, to);
	return (1);
}

void	move_top_a(t_data *data, enum e_loc to)
{
	if (to == BOTTOM_A)
		ra(data);
	else if (to == TOP_B)
		pb(data);
	else if (to == BOTTOM_B)
	{
		pb(data);
		rb(data);
	}
}

void	move_top_b(t_data *data, enum e_loc to)
{
	if (to == TOP_A)
		pa(data);
	else if (to == BOTTOM_B)
		rb(data);
	else if (to == BOTTOM_A)
	{
		pa(data);
		ra(data);
	}
}

void	move_bottom_a(t_data *data, enum e_loc to)
{
	if (to == TOP_A)
		rra(data);
	else if (to == TOP_B)
	{
		rra(data);
		pb(data);
	}
	else if (to == BOTTOM_B)
	{
		rra(data);
		pb(data);
		rb(data);
	}
}

void	move_bottom_b(t_data *data, enum e_loc to)
{
	if (to == TOP_B)
		rrb(data);
	else if (to == TOP_A)
	{
		rrb(data);
		pa(data);
	}
	else if (to == BOTTOM_A)
	{
		rrb(data);
		pa(data);
		ra(data);
	}
}
