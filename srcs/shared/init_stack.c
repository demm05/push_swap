/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:04:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 19:08:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	fill_values(t_data *data)
{
	t_node	*cur;
	int		i;

	cur = data->a->head;
	i = 1;
	while (cur->next)
	{
		cur = cur->next;
		i++;
	}
	data->a->tail = cur;
	data->a->size = i;
	data->b->size = 0;
	data->b->head = NULL;
	data->b->tail = NULL;
}

t_data	*init_data(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	// TODO: panic free
	if (!data->a || !data->b)
		return (NULL);
	data->a->head = parse_argv(argc, argv);
	if (!data->a->head)
	{
		free(data);
		return (NULL);
	}
	fill_values(data);
	return (data);
}
