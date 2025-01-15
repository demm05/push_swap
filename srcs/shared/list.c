/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:56:06 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/15 15:23:25 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	clean_list(t_node **lst)
{
	t_node	*next;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

void	append_list(t_node **lst, int num)
{
	t_node	*new;
	t_node	*node;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		clean_list(lst);
		exit(1);
	}
	new->nbr = num;
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	new->prev = node;
	node->next = new;
	node->next->prev = node;
}

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	printf_lst(t_data *data)
{
	t_node	*lst;

	lst = data->a->head;
	ft_printf("---A---\n");
	while (lst)
	{
		ft_printf("%d\n", lst->nbr);
		lst = lst->next;
	}
	ft_printf("\n---B---\n");
	lst = data->b->head;
	while (lst)
	{
		ft_printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}

t_node	*ft_lstcpy(t_node *src)
{
	t_node	*dest;

	dest = NULL;
	while (src)
	{
		append_list(&dest, src->nbr);
		src = src->next;
	}
	return (dest);
}
