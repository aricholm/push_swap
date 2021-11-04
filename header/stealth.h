/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stealth.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:22:12 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 23:23:23 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STEALTH_H
# define STEALTH_H
# include "checker.h"
# include "linked_list.h"

t_bool	stealth_push_lowest_x(t_stack *stack, size_t many, size_t *ops);
size_t	stealth_slow_solve(t_stack *stack);
size_t	stealth_solve_right_x(t_stack *stack, size_t many);
size_t	stealth_solve_3(t_stack *stack);
size_t	stealth_iterate_rotate(t_stack *stack, t_side which, int i);
size_t	stealth_iterate_func(size_t (*f)(), t_stack *stack, size_t i);

#endif