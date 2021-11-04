/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:43:22 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 18:47:12 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

size_t	ch_ss(t_stack *stack)
{
	stack_swap(&stack->a);
	stack_swap(&stack->b);
	return (1);
}

size_t	ch_rr(t_stack *stack)
{
	stack_rotate(&stack->a);
	stack_rotate(&stack->b);
	return (1);
}

size_t	ch_rrr(t_stack *stack)
{
	stack_reverse_rotate(&stack->a);
	stack_reverse_rotate(&stack->b);
	return (1);
}
