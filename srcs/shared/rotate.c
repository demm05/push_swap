/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:49:40 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 18:51:33 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	internal_ra(t_stack *stack, int print)
{
	t_node	*last;
	t_node	*first;

	if (!stack->a || !stack->a->next)
		return ;
	first = stack->a;
	last = stack->a;
	while (last->next)
		last = last->next;
	stack->a = first->next;
	stack->a->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print && !stack->silent)
		write(1, "ra\n", 3);
}

static void	internal_rb(t_stack *stack, int print)
{
	t_node	*last;
	t_node	*first;

	if (!stack->b || !stack->b->next)
		return ;
	first = stack->b;
	last = stack->b;
	while (last->next)
		last = last->next;
	stack->b = first->next;
	stack->b->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print && !stack->silent)
		write(1, "rb\n", 3);
}

void	ra(t_stack *stack)
{
	internal_ra(stack, 1);
}

void	rb(t_stack *stack)
{
	internal_rb(stack, 1);
}

void	rr(t_stack *stack)
{
	internal_ra(stack, 1);
	internal_rb(stack, 1);
	if (!stack->silent)
		write(1, "rr\n", 3);
}
