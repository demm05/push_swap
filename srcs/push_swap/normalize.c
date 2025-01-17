/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:07:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 13:24:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_middle(t_node *head)
{
	t_node	*slow;
	t_node	*fast;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

static t_node	*merge(t_node *left, t_node *right)
{
	if (!left)
		return (right);
	if (!right)
		return (left);
	if (left->nbr < right->nbr)
	{
		left->next = merge(left->next, right);
		return (left);
	}
	else
	{
		right->next = merge(left, right->next);
		return (right);
	}
}

static t_node	*merge_sort(t_node *head)
{
	t_node	*left;
	t_node	*right;
	t_node	*temp;

	if (!head || !head->next)
		return (head);
	left = head;
	right = get_middle(head);
	temp = right->next;
	right->next = NULL;
	right = temp;
	left = merge_sort(left);
	right = merge_sort(right);
	return (merge(left, right));
}

static int	get_index(t_node *lst, int nbr)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->nbr == nbr)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

int	normalize_stack(t_stack *stack)
{
	t_node	*sorted;
	t_node	*cur;
	int		i;

	sorted = ft_lstcpy(stack->head);
	sorted = merge_sort(sorted);
	cur = stack->head;
	while (cur)
	{
		i = get_index(sorted, cur->nbr);
		cur->nbr = i;
		cur = cur->next;
	}
	clean_list(&sorted);
	return (1);
}
