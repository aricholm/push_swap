/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:51:15 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/13 15:08:43 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

void	stack_swap(t_list **list);
void	stack_push(t_list **stack_to, t_list **stack_from);
void	stack_rotate(t_list **list);
void	stack_reverse_rotate(t_list **list);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rrr(t_stack *stack);
void	iterate_func(void (*f)(), t_stack *stack, size_t i);
void	iterate_rotate(t_stack *stack, t_side which, int i);
void	slow_solve(t_stack *stack);
void	solve_3(t_stack *stack);
void	solve_3_right(t_stack *stack);
void	solve_right_x(t_stack *stack, size_t many);
t_bool	push_lowest_x(t_stack *stack, size_t many);
#endif