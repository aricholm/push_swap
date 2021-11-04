/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:10:56 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/13 19:08:12 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include "utilities.h"

static t_bool	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_integer(char *value)
{
	size_t	i;

	i = 0;
	if (value[i] == '+' || value[i] == '-')
		i++;
	while (value[i])
	{
		if (!is_number(value[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	is_range(long number)
{
	if (number <= INT_MAX && number >= INT_MIN)
		return (TRUE);
	return (FALSE);
}

t_bool	is_unique(t_list *stack, long number)
{
	t_list	*i;

	i = stack;
	while (i)
	{
		if (i->value == number)
			return (FALSE);
		i = i->next;
	}
	return (TRUE);
}

t_bool	is_valid(t_list *stack, char *value)
{
	if (!is_integer(value) || !is_range(ft_atoi(value))
		|| !is_unique(stack, ft_atoi(value)))
		return (FALSE);
	return (TRUE);
}
