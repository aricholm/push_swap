/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:42:10 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 18:46:48 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

size_t	ch_ra(t_stack *stack)
{
	stack_rotate(&stack->a);
	return (1);
}

size_t	ch_rb(t_stack *stack)
{
	stack_rotate(&stack->b);
	return (1);
}

size_t	ch_rra(t_stack *stack)
{
	stack_reverse_rotate(&stack->a);
	return (1);
}

size_t	ch_rrb(t_stack *stack)
{
	stack_reverse_rotate(&stack->b);
	return (1);
}
