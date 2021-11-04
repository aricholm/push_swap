/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:13:00 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 16:44:54 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include "linked_list.h"

static int	getmin(t_list *list)
{
	int	min;

	if (!list)
		return (-1);
	min = list->value;
	while (list)
	{
		if (min > list->value)
			min = list->value;
		list = list->next;
	}
	return (min);
}

static int	get_min_place(t_list *list)
{
	int	pos;
	int	len;

	pos = 0;
	len = ft_lstsize(list);
	while (list->value != getmin(list))
	{
		list = list->next;
		pos++;
	}
	if (pos > -1 * (pos - len))
		return (pos - len);
	return (pos);
}

static t_bool	is_increasing(t_list *list)
{
	int		value;

	if (list)
	{
		while (list->next)
		{
			value = list->value;
			list = list->next;
			if (value != list->value - 1)
				return (FALSE);
		}
	}
	return (TRUE);
}

void	slow_solve(t_stack *stack)
{
	if (stack->a->next && !stack->a->next->next)
	{
		if (stack->a->value > stack->a->next->value)
			return (ft_sa(stack));
	}
	while (ft_lstsize(stack->a) > 3 && !is_increasing(stack->a))
	{
		iterate_rotate(stack, LEFT, get_min_place(stack->a));
		ft_pb(stack);
	}
	if (ft_lstsize(stack->a) == 3)
		solve_3(stack);
	iterate_func(ft_pa, stack, ft_lstsize(stack->b));
}
