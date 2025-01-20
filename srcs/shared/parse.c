/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:53:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/17 15:02:35 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static long	ps_atoi(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		result = result * 10 + (*nptr++ - '0');
		if ((result * sign > INT_MAX) || (result * sign < INT_MIN))
			break ;
	}
	return (result * sign);
}

static int	get_i_of_next_num(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[++i]))
			return (-1);
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (get_i_of_next_num(str + i) != -1)
				return (i + 1);
			return (-1);
		}
		else
			return (-1);
		if (ft_isdigit(str[i - 1]) && (str[i] == '-' || str[i] == '+'))
			return (-1);
	}
	return (i);
}

static int	check_for_duplicate(t_node *lst, int num)
{
	while (lst)
	{
		if (lst->nbr == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	parse_str(char *str, t_node **lst)
{
	long	num;
	int		i;

	num = ps_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (-1);
	if (check_for_duplicate(*lst, num))
		return (-1);
	i = get_i_of_next_num(str);
	if (i == -1)
		return (-1);
	append_list(lst, num);
	return (i);
}

int	parse_argv(int argc, char *argv[], t_stack *stack)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	stack->head = NULL;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			j = parse_str(str, &stack->head);
			if (j == -1)
				return (EXIT_FAILURE);
			str += j;
		}
		i++;
	}
	if (i > 1 && !stack->head)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
