/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:49:39 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 12:59:26 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_data *data)
{
	bool	sorted;
	t_node	*cur;

	cur = data->a->head;
	sorted = 1;
	while (cur->next)
	{
		if (cur->nbr > cur->next->nbr)
		{
			sorted = 0;
			break ;
		}
		cur = cur->next;
	}
	return (sorted);
}
