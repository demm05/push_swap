/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:44:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 18:52:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	internal_sa(t_stack *stack, int print)
{
	t_node	*temp;
	t_node	*next;

	if (!stack->a || !stack->a->next)
		return ;
	temp = stack->a;
	stack->a = stack->a->next;
	next = stack->a->next;
	stack->a->next = temp;
	stack->a->prev = NULL;
	temp->next = next;
	if (next)
		next->prev = temp;
	temp->prev = stack->a;
	if (!stack->silent && print)
		write(1, "sa\n", 3);
}

static void	internal_sb(t_stack *stack, int print)
{
	t_node	*temp;
	t_node	*next;

	if (!stack->b || !stack->b->next)
		return ;
	temp = stack->b;
	stack->b = stack->b->next;
	next = stack->b->next;
	stack->b->next = temp;
	stack->b->prev = NULL;
	temp->next = next;
	if (next)
		next->prev = temp;
	temp->prev = stack->b;
	if (!stack->silent && print)
		write(1, "sb\n", 3);
}

void	sa(t_stack *stack)
{
	internal_sa(stack, 1);
}

void	sb(t_stack *stack)
{
	internal_sb(stack, 1);
}

void	ss(t_stack *stack)
{
	internal_sa(stack, 0);
	internal_sb(stack, 0);
	if (!stack->silent)
		write(1, "ss\n", 3);
}
