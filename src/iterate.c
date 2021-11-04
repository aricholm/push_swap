/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:56:06 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 22:30:23 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "checker.h"

size_t	stealth_iterate_func(size_t (*f)(), t_stack *stack, size_t i)
{
	while (i != 0)
	{
		f(stack);
		i--;
	}
	return (i);
}

size_t	stealth_iterate_rotate(t_stack *stack, t_side which, int i)
{
	if (i < 0)
	{
		i = -i;
		if (which == RIGHT)
			stealth_iterate_func(ch_rrb, stack, i);
		else
			stealth_iterate_func(ch_rra, stack, i);
	}
	else
	{
		if (which == RIGHT)
			stealth_iterate_func(ch_rb, stack, i);
		else
			stealth_iterate_func(ch_ra, stack, i);
	}
	return (i);
}

void	iterate_func(void (*f)(), t_stack *stack, size_t i)
{
	while (i != 0)
	{
		f(stack);
		i--;
	}
}

void	iterate_rotate(t_stack *stack, t_side which, int i)
{
	if (i < 0)
	{
		i = -i;
		if (which == RIGHT)
			iterate_func(ft_rrb, stack, i);
		else
			iterate_func(ft_rra, stack, i);
	}
	else
	{
		if (which == RIGHT)
			iterate_func(ft_rb, stack, i);
		else
			iterate_func(ft_ra, stack, i);
	}
}
