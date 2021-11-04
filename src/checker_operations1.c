/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:40:42 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 18:46:18 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

size_t	ch_sa(t_stack *stack)
{
	stack_swap(&stack->a);
	return (1);
}

size_t	ch_sb(t_stack *stack)
{
	stack_swap(&stack->b);
	return (1);
}

size_t	ch_pa(t_stack *stack)
{
	stack_push(&stack->a, &stack->b);
	return (1);
}

size_t	ch_pb(t_stack *stack)
{
	stack_push(&stack->b, &stack->a);
	return (1);
}
