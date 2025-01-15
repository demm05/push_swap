/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:43:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/15 16:12:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "external.h"

enum	e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
};

typedef struct	s_chunk
{
	enum e_loc	loc;
	int			size;
}	t_chunk;

typedef struct	s_split
{
	t_chunk	max;
	t_chunk	mid;
	t_chunk	min;
}	t_split;

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
void	sort(t_data *data);
void	sort_chunk(t_data *data);
void	split_chunk(t_data *data, t_chunk *to_sort, t_split *dest);
int		move_from_to(t_data *data, enum e_loc from, enum e_loc to);
t_node	*get_next_node(t_node *node, enum e_loc loc);
t_node	*get_correct_node(t_data *data, enum e_loc loc);
int		chunk_max_val(t_data *data, t_chunk *chunk);
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
