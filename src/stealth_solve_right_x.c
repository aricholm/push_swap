/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stealth_solve_right_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:37:59 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 22:53:24 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include "utilities.h"
#include "linked_list.h"
#include "stealth.h"

static int	find_x(t_list *list, int number)
{
	int	pos;
	int	len;

	pos = 0;
	len = ft_lstsize(list);
	while (list->value != number)
	{
		list = list->next;
		pos++;
	}
	if (pos > -1 * (pos - len))
		return (pos - len);
	return (pos);
}

static int	getmax(t_list *list)
{
	int	max;

	if (!list)
		return (-1);
	max = list->value;
	while (list)
	{
		if (max < list->value)
			max = list->value;
		list = list->next;
	}
	return (max);
}

size_t	stealth_solve_right_x(t_stack *stack, size_t many)
{
	size_t	pushback;
	int		max;
	size_t	ops;

	ops = 0;
	if (many < 2)
		return (0);
	if (many == 2)
	{
		if (stack->b->value < stack->b->next->value)
			ops += ch_sb(stack);
		return (1);
	}
	pushback = many - 1;
	max = getmax(stack->b);
	while (many > 1)
	{
		ops += stealth_iterate_rotate(stack, RIGHT, find_x(stack->b, max--));
		ops += ch_pa(stack);
		many--;
	}
	ops += stealth_iterate_rotate(stack, RIGHT, find_x(stack->b, max));
	ops += stealth_iterate_func(ch_pb, stack, pushback);
	return (ops);
}
