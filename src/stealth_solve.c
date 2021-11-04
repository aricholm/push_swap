/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stealth_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:11:22 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/28 17:42:22 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stealth.h"
#include "utilities.h"
#include "operations.h"

size_t	stealth_solve(t_stack *stack, size_t many)
{
	size_t	operations;

	operations = 0;
	while (stealth_push_lowest_x(stack, many, &operations))
		operations += stealth_solve_right_x(stack, many);
	operations += stealth_slow_solve(stack);
	while (stack->b)
		operations += ch_pa(stack);
	return (operations);
}

size_t	optimal_divide(t_stack stack)
{
	t_stack	newstack;
	size_t	i;
	size_t	optimized;
	size_t	ops;
	size_t	min;

	i = 3;
	min = 2147483647;
	optimized = 3;
	while (i < ft_lstsize(stack.a) / 3 && i < 60)
	{
		newstack.a = duplicate_stack(stack.a);
		newstack.b = NULL;
		ops = stealth_solve(&newstack, i);
		if (ops < min)
		{
			optimized = i;
			min = ops;
		}
		free_stack(&newstack);
		i++;
	}
	return (optimized);
}
