/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:00:42 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/15 16:56:02 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_split_loc(enum e_loc loc, t_chunk *max, t_chunk *mid, t_chunk *min);
void	set_pivots(enum e_loc loc, int size, int *pivot1, int *pivot2);
void	init_dest(t_split *dest);

void	split_chunk(t_data *data, t_chunk *to_split, t_split *dest)
{
	t_node	*cur;
	t_node	*next;
	int	pivot1;
	int	pivot2;

	init_dest(dest);
	set_pivots(to_split->loc, to_split->size, &pivot1, &pivot2);
	set_split_loc(to_split->loc, &dest->max, &dest->mid, &dest->min);
//	ft_printf("first:% d\tsecond: %d\n", pivot1, pivot2);
	cur = get_correct_node(data, to_split->loc);
	while (to_split->size--)
	{
		if (!cur)
		{
			ft_printf("HELLO there\n");
			break ;
		}
		next = get_next_node(cur, to_split->loc);
		if (cur->nbr < pivot1)
		{
			//ft_printf("min: %d\n", cur->nbr);
			dest->min.size += move_from_to(data, to_split->loc, dest->min.loc);
		}
		else if (cur->nbr < pivot2)
		{
			//ft_printf("mid: %d\n", cur->nbr);
			dest->mid.size += move_from_to(data, to_split->loc, dest->mid.loc);
		}
		else
		{
			dest->max.size += move_from_to(data, to_split->loc, dest->max.loc);
			//ft_printf("max: %d\n", cur->nbr);
		}
		cur = next;
	}
}

void	set_split_loc(enum e_loc loc, t_chunk *max, t_chunk *mid, t_chunk *min)
{
	if (loc == TOP_A)
	{
		max->loc = BOTTOM_A;
		mid->loc = TOP_B;
		min->loc = BOTTOM_B;
	}
	else if (loc == BOTTOM_A)
	{
		max->loc = TOP_A;
		mid->loc = TOP_B;
		min->loc = BOTTOM_B;
	}
	else if (loc == TOP_B)
	{
		max->loc = TOP_A;
		mid->loc = BOTTOM_A;
		min->loc = BOTTOM_B;
	}
	else if (loc == BOTTOM_B)
	{
		max->loc = TOP_A;
		mid->loc = BOTTOM_A;
		min->loc = TOP_B; 
	}
}

void	set_pivots(enum e_loc loc, int size, int *pivot1, int *pivot2)
{
	*pivot1 = size / 3;
	if (loc == TOP_A || BOTTOM_A)
		*pivot2 = 2 * size / 3;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pivot2 = size / 2;
	if ((loc == TOP_A || loc == BOTTOM_A) && size < 15)
		*pivot2 = size;
	if (loc == BOTTOM_B && size < 8)
		*pivot1 = size / 2;
}

void	init_dest(t_split *dest)
{
	dest->max.size = 0;
	dest->mid.size = 0;
	dest->min.size = 0;
}
