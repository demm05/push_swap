/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:43:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 20:08:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "external.h"

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	bool	silent;	
}	t_data;

// ================================PUSH__SWAP===============================
int		normalize_stack(t_stack *stack);
// =========================================================================

// ================================OPERATIONS==============================
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
// =========================================================================

// ==================================SHARED=================================
t_node	*parse_argv(int argc, char *argv[]);
t_data	*init_data(int argc, char *argv[]);
void	printf_lst(t_data *data);
// =========================================================================

// ===================================LIST==================================
void	append_list(t_node **lst, int num);
void	clean_list(t_node **lst);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstcpy(t_node *src);
// =========================================================================

#endif
