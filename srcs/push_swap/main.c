/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:03:09 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 20:08:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = init_stack(argc, argv);
	normalize_stack(stack);
	stack->silent = 0;
	if (!stack)
		return (1);
	//sort_stack(stack);
	//printf_lst(stack);
	clean_list(&stack->a);
	clean_list(&stack->b);
	free(stack);
}
