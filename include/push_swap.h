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
	t_node	*a;
	t_node	*b;
	int		a_len;
	int		b_len;
	bool	silent;	
}	t_stack;

// ================================PUSH__SWAP===============================
int		normalize_stack(t_stack *stack);
// =========================================================================

// ================================OPERATIONS==============================
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
// =========================================================================

// ==================================SHARED=================================
t_node	*parse_argv(int argc, char *argv[]);
t_stack	*init_stack(int argc, char *argv[]);
void	printf_lst(t_stack *stack);
// =========================================================================

// ===================================LIST==================================
void	append_list(t_node **lst, int num);
void	clean_list(t_node **lst);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstcpy(t_node *src);
// =========================================================================

#endif
