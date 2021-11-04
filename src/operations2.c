/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:22:04 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/13 15:09:11 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_ra(t_stack *stack)
{
	stack_rotate(&stack->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *stack)
{
	stack_rotate(&stack->b);
	write(1, "rb\n", 3);
}

void	ft_rra(t_stack *stack)
{
	stack_reverse_rotate(&stack->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack)
{
	stack_reverse_rotate(&stack->b);
	write(1, "rrb\n", 4);
}
