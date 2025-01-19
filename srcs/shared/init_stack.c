/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:04:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/17 15:08:27 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_values(t_data *data)
{
	t_node	*cur;
	int		i;

	if (!data->a->head)
		return ;
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
	int		status;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	if (!data->a || !data->b)
	{
		free_data(data);
		return (NULL);
	}
	status = parse_argv(argc, argv, data->a);
	fill_values(data);
	if (!data->a->head || status == EXIT_FAILURE || data->a->size < argc - 1)
	{
		if (status == EXIT_FAILURE || data->a->size < argc - 1)
			(void)!write(2, "Error\n", 6);
		free_data(data);
		return (NULL);
	}
	return (data);
}
