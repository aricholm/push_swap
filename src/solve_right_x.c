/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_right_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:37:59 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 22:24:52 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include "utilities.h"
#include "linked_list.h"

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

int	getmax(t_list *list)
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

void	solve_right_x(t_stack *stack, size_t many)
{
	size_t	pushback;
	int		max;

	if (many < 2)
		return ;
	if (many == 2)
	{
		if (stack->b->value < stack->b->next->value)
			ft_sb(stack);
		return ;
	}
	pushback = many - 1;
	max = getmax(stack->b);
	while (many > 1)
	{
		iterate_rotate(stack, RIGHT, find_x(stack->b, max--));
		ft_pa(stack);
		many--;
	}
	iterate_rotate(stack, RIGHT, find_x(stack->b, max));
	iterate_func(ft_pb, stack, pushback);
}
