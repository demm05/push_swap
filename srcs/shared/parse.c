/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:53:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/14 19:09:01 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <limits.h>

static inline long	ft_atoi(const char *nptr)
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
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			while (str[++i])
				if (str[i] == '-' || str[i] == '+')
					return (-1);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (get_i_of_next_num(str + i) != -1)
				return (i);
			return (-1);
		}
		else
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

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Size of number exceed size of integer type\n");
		return (-1);
	}
	if (check_for_duplicate(*lst, num))
	{
		ft_printf("Duplicate of numbers\n");
		return (-1);
	}
	i = get_i_of_next_num(str);
	if (i == -1)
	{
		ft_printf("Only numbers\n");
		return (-1);
	}
	append_list(lst, num);
	return (i);
}

t_node	*parse_argv(int argc, char *argv[])
{
	t_node	*head;
	char	*str;
	int		i;
	int		j;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			j = parse_str(str, &head);
			if (j == -1)
			{
				clean_list(&head);
				return (NULL);
			}
			str += j;
		}
		i++;
	}
	return (head);
}
