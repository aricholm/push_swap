/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:38:40 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/13 15:09:06 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_sa(t_stack *stack)
{
	stack_swap(&stack->a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack)
{
	stack_swap(&stack->b);
	write(1, "sb\n", 3);
}

void	ft_pa(t_stack *stack)
{
	stack_push(&stack->a, &stack->b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *stack)
{
	stack_push(&stack->b, &stack->a);
	write(1, "pb\n", 3);
}
