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

t_stack	*init_stack(int argc, char *argv[])
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = parse_argv(argc, argv);
	if (!stack->a)
	{
		clean_list(&stack->a);
		free(stack);
		return (NULL);
	}
	stack->a_len = ft_lstsize(stack->a);
	return (stack);
}
