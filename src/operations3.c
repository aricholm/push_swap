/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:25:21 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/13 15:09:16 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_ss(t_stack *stack)
{
	stack_swap(&stack->a);
	stack_swap(&stack->b);
	write(1, "ss\n", 3);
}

void	ft_rr(t_stack *stack)
{
	stack_rotate(&stack->a);
	stack_rotate(&stack->b);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack *stack)
{
	stack_reverse_rotate(&stack->a);
	stack_reverse_rotate(&stack->b);
	write(1, "rrr\n", 4);
}
