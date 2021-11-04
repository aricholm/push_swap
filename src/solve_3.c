/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:22:26 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 22:38:46 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stealth.h"

static size_t	get_max(t_list *list)
{
	if (list->value > list->next->value
		&& list->value > list->next->next->value)
		return (1);
	if (list->next->value > list->value
		&& list->next->value > list->next->next->value)
		return (2);
	if (list->next->next->value > list->next->value
		&& list->next->next->value > list->next->value)
		return (3);
	return (0);
}

static size_t	get_min(t_list *list)
{
	if (list->value < list->next->value
		&& list->value < list->next->next->value)
		return (1);
	if (list->next->value < list->value
		&& list->next->value < list->next->next->value)
		return (2);
	if (list->next->next->value < list->next->value
		&& list->next->next->value < list->next->value)
		return (3);
	return (0);
}

void	solve_3(t_stack *stack)
{
	size_t	min;
	size_t	max;

	min = get_min(stack->a);
	max = get_max(stack->a);
	if (min == 1 && max == 3)
		return ;
	if (min == 2 && max == 3)
		return (ft_sa(stack));
	if (min == 2 && max == 1)
		return (ft_ra(stack));
	if (min == 3 && max == 2)
		return (ft_rra(stack));
	if (min == 3 && max == 1)
	{
		ft_sa(stack);
		ft_rra(stack);
		return ;
	}
	if (min == 1 && max == 2)
	{
		ft_sa(stack);
		ft_ra(stack);
		return ;
	}	
}

size_t	stealth_solve_3(t_stack *stack)
{
	size_t	min;
	size_t	max;

	min = get_min(stack->a);
	max = get_max(stack->a);
	if (min == 1 && max == 3)
		return (0);
	if (min == 2 && max == 3)
		return (ch_sa(stack));
	if (min == 2 && max == 1)
		return (ch_ra(stack));
	if (min == 3 && max == 2)
		return (ch_rra(stack));
	if (min == 3 && max == 1)
	{
		ch_sa(stack);
		ch_rra(stack);
	}
	if (min == 1 && max == 2)
	{
		ch_sa(stack);
		ch_ra(stack);
	}	
	return (2);
}
