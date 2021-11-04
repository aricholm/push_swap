/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stealth_push_lowest_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:52:19 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 22:23:41 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "linked_list.h"
#include "stealth.h"

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

static t_bool	is_set(int value, int min, int max)
{
	if (value >= min && value < max)
		return (TRUE);
	return (FALSE);
}

t_bool	stealth_push_lowest_x(t_stack *stack, size_t many, size_t *ops)
{
	int	min;
	int	max;

	if (ft_lstsize(stack->a) < many + 1)
		return (FALSE);
	min = getmin(stack->a);
	max = min + many;
	while (many > 0)
	{
		while (!is_set(stack->a->value, min, max))
			*ops += ch_ra(stack);
		*ops += ch_pb(stack);
		many--;
	}
	return (TRUE);
}
